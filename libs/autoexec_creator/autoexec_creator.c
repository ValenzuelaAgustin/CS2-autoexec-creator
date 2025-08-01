#include "autoexec_creator.h"
#include "..\nstd_string\nstd_string.h"
#include "..\cfg_commands\cfg_commands.h"

enum
{
	SETTING_NOT_FOUND = STRING_NOT_FOUND + 1,
	PARAMETER_NOT_FOUND
};

enum
{
	MACHINE_CONVARS,
	USER_CONVARS,
	USER_KEYS,
	ADDITIONAL_INPUT_FILE
};

#define IS_BETWEEN(x, min, max) ((x) >= (min) && (x) <= (max))

#define CONFIG_LOADED_TEXT "echo -----------------------------------------------------------------------\necho -----------------------------Config loaded-----------------------------\necho -----------------------------------------------------------------------"

static char is_key_binded[ammount_of_keys];

static void append_binding(FILE* autoexec, const char* command, const char* command_name, const char* bindable_input);

static void append_config(FILE* autoexec, const char* config, const char* config_name, const char* value, int value_length);

static long search_inline_parameter(const char* config_file_string, long setting_position, long setting_length);

static long search_setting_and_parameter(const char* config_file_string, const char* config);

static void append_config_to_file(FILE* autoexec, char** config_file_string, long menu, long config);

static void append_binding(FILE* autoexec, const char* command, const char* command_name, const char* bindable_input)
{
	if (autoexec == NULL || command == NULL || command_name == NULL)
		return;

	int has_bindable_input = bindable_input != NULL;

	fprintf(autoexec, "\n%sbind \"%s\" \"%s\"\t\t\t\t// %s", (has_bindable_input) ? "" : "// ", (has_bindable_input) ? bindable_input : "", command, command_name);
}

static void append_config(FILE* autoexec, const char* config, const char* config_name, const char* value, int value_length)
{
	if (autoexec == NULL || config == NULL || config_name == NULL)
		return;

	int has_value = value != NULL && value_length > 0;

	fprintf(autoexec, "\n%s%s \"%.*s\"\t\t\t\t// %s", (has_value) ? "" : "// ", config, (has_value) ? value_length : 0, (has_value) ? value : "", config_name);
}

static long search_inline_parameter(const char* config_file_string, long setting_position, long setting_length)
{
	if ( config_file_string == NULL || setting_position < 0)
		return INVALID_INPUT;

	long i, parameter_position;
	int qm_counter;

	for (i = setting_position; i > 0 && config_file_string[i] != '\n'; i--);

	for (i += config_file_string[i] == '\n', qm_counter = 0; i < setting_position - 1 && qm_counter < 2; i++)
	{
		if (config_file_string[i] == '\"')
		{
			qm_counter++;
			parameter_position = (qm_counter == 1) ? i + 1 : parameter_position;
		}
	}

	if (qm_counter == 2)
		return parameter_position;

	for (i = setting_position + setting_length; config_file_string[i] != '\"' && config_file_string[i] != ' ' && config_file_string[i] != '\t'; i++);
	i++;

	for (qm_counter = 0; config_file_string[i] && config_file_string[i] != '\n' && qm_counter < 2; i++)
	{
		if (config_file_string[i] == '\"')
		{
			qm_counter++;
			parameter_position = (qm_counter == 1) ? i + 1 : parameter_position;
		}
	}

	return (qm_counter == 2) ? parameter_position : PARAMETER_NOT_FOUND;
}

static long search_setting_and_parameter(const char* config_file_string, const char* config)
{
	if (config_file_string == NULL || config == NULL)
		return INVALID_INPUT;

	long setting_position;
	long setting_length = strlength(config);
	long prev_char_before_setting;
	long next_char_after_setting;
	long starting_pos;
	int is_valid;

	//setting_position = search_for_quoted_target_string(config, config_file_string);
	for(is_valid = 0, setting_position = 0, starting_pos = 0; setting_position >= 0 && !is_valid;)
	{
		setting_position = starting_pos + search_for_target_string(config, config_file_string + starting_pos);
		starting_pos = setting_position + 1;
		if(setting_position < 0)
			continue;
		prev_char_before_setting = setting_position - 1;
		next_char_after_setting = setting_position + setting_length;
		if(config_file_string[next_char_after_setting] == '\n' || config_file_string[next_char_after_setting] == '\t' ||
		   config_file_string[next_char_after_setting] == '\"' || config_file_string[next_char_after_setting] == ' '  || config_file_string[next_char_after_setting] == '$')
		{
			is_valid = 1;
		}
		if(prev_char_before_setting < 1)
			continue;
		if(config_file_string[prev_char_before_setting] != '\n' && config_file_string[prev_char_before_setting] != '\t' &&
		   config_file_string[prev_char_before_setting] != '\"' && config_file_string[prev_char_before_setting] != ' ')
		{
			is_valid = 0;
		}
	}

	if (setting_position < 0)
	{
		return SETTING_NOT_FOUND;
	}
	return search_inline_parameter(config_file_string, setting_position, setting_length);
}

static void append_config_to_file(FILE* autoexec, char** config_file_string, long menu, long config)
{
	if(cfg_menu[menu].config[config][0] == '\0')
		return;

	long i, j;
	long parameter_position;
	long new_line_start;
	int was_found;
	int str_length;

	for (i = 0, was_found = 0, new_line_start = 0; config_file_string[i] != NULL;)
	{
		if (i == USER_KEYS && menu != KEYBOARD_AND_MOUSE)
		{
			i++;
			continue;
		}

		parameter_position = search_setting_and_parameter(config_file_string[i] + new_line_start, cfg_menu[menu].config[config]);
		if (parameter_position < 0)
		{
			i++;
			new_line_start = 0;
			continue;
		}
		parameter_position += new_line_start;
		for (new_line_start = parameter_position; config_file_string[i][new_line_start] != '\n' && config_file_string[i][new_line_start] != '\0'; new_line_start++);
		for (str_length = 0; config_file_string[i][parameter_position + str_length] != '\"'; str_length++);

		if (menu == KEYBOARD_AND_MOUSE && IS_BETWEEN(config, Yaw, Chat_Wheel_3))
		{
			for (j = 0; j < ammount_of_keys && search_for_quoted_target_string(Keys[j], config_file_string[i] + parameter_position - 1) != 1; j++);
			if (j >= ammount_of_keys)
				continue;
			append_binding(autoexec, cfg_menu[menu].config[config], cfg_menu[menu].config_name[config], Keys[j]);
			was_found = 1;
			is_key_binded[j] = 1;
			break;
		}
		append_config(autoexec, cfg_menu[menu].config[config], cfg_menu[menu].config_name[config], config_file_string[i] + parameter_position, str_length);
		was_found = 1;
		break;
	}

	if (was_found)
		return;

	if (menu == KEYBOARD_AND_MOUSE && IS_BETWEEN(config, Yaw, Chat_Wheel_3))
		append_binding(autoexec, cfg_menu[menu].config[config], cfg_menu[menu].config_name[config], NULL);
	else
		append_config(autoexec, cfg_menu[menu].config[config], cfg_menu[menu].config_name[config], NULL, 0);
}

void write_autoexec(FILE* autoexec, char** config_file_string)
{
	if (config_file_string == NULL || config_file_string[0] == NULL || autoexec == NULL)
		return;

	long parameter_position;
	long menu, config;
	int file_index;
	int sub_menu;
	int str_l;
	int i;

	for (i = 0; i < ammount_of_keys; i++)
		is_key_binded[i] = 0;

	for (menu = 0; menu < menu_ammount; menu++)
	{
		for (config = 0, sub_menu = 0; cfg_menu[menu].sub_menu_last_config[sub_menu] > -1; config++, sub_menu += config > cfg_menu[menu].sub_menu_last_config[sub_menu])
		{
			if (!config || config == cfg_menu[menu].sub_menu_last_config[sub_menu - (sub_menu > 0)] + 1)
			{
				fprintf(autoexec, "%s// %s\n", (menu || config) ? "\n\n\n" : "",cfg_menu[menu].sub_menu_title[sub_menu]);
			}
			append_config_to_file(autoexec, config_file_string, menu, config);
		}
	}

	fprintf(autoexec, "\n\n\n// Other Bindings\n");

	for (i = 0, file_index = USER_KEYS; i < ammount_of_keys; i++, file_index = USER_KEYS)
	{
		if (is_key_binded[i])
			continue;
		parameter_position = search_setting_and_parameter(config_file_string[file_index], Keys[i]);
		if (parameter_position < 0)
		{
			file_index = ADDITIONAL_INPUT_FILE;
			parameter_position = search_setting_and_parameter(config_file_string[file_index], Keys[i]);
		}
		if (parameter_position < 0)
			continue;
		if (search_for_quoted_target_string("<unbound>", config_file_string[file_index] + parameter_position - 1) == 1)
			continue;
		for (str_l = 0; config_file_string[file_index][parameter_position+str_l] != '\"'; str_l++);
		fprintf(autoexec, "\nbind \"%s\" \"%.*s\"", Keys[i], str_l, config_file_string[file_index] + parameter_position);
	}

	fprintf(autoexec, "\n\n%s", CONFIG_LOADED_TEXT);
}