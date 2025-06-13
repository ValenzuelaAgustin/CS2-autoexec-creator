#include "autoexec_creator.h"
#include "..\nstd_string\nstd_string.h"
#include "..\cfg_commands\cfg_commands.h"

enum
{
	SETTING_NOT_FOUND = STRING_NOT_FOUND + 1,
	PARAMETER_NOT_FOUND
};

#define IS_BETWEEN(x, min, max) ((x) >= (min) && (x) <= (max))

#define BINDING_TEXT "\nbind \"%.*s\" \"%s\"\t\t\t\t// %s"
#define CONFIG_TEXT "\n%s \"%.*s\"\t\t\t\t// %s"
#define COMMENTED_BINDING_TEXT "\n// bind \"\" \"%s\"\t\t\t\t// %s"
#define COMMENTED_CONFIG_TEXT "\n// %s \"\"\t\t\t\t// %s"

#define APPEND_BINDING(autoexec, menu, config, str_length, str) fprintf(autoexec, BINDING_TEXT, str_length, str, cfg_menu[menu].config[config], cfg_menu[menu].config_name[config])
#define APPEND_CONFIG(autoexec, menu, config, str_length, str) fprintf(autoexec, CONFIG_TEXT, cfg_menu[menu].config[config], str_length, str, cfg_menu[menu].config_name[config])
#define APPEND_COMMENTED_BINDING(autoexec, menu, config) fprintf(autoexec, COMMENTED_BINDING_TEXT, cfg_menu[menu].config[config], cfg_menu[menu].config_name[config])
#define APPEND_COMMENTED_CONFIG(autoexec, menu, config) fprintf(autoexec, COMMENTED_CONFIG_TEXT, cfg_menu[menu].config[config], cfg_menu[menu].config_name[config])

static long search_inline_parameter(const char* config_file_string, long setting_position);

static long search_setting_parameter(const char* config_file_string, const char* config);

static void append_config_to_file(FILE* autoexec, char** config_file_string, long menu, long config);

static long search_inline_parameter(const char* config_file_string, long setting_position)
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

	for (i = setting_position; config_file_string[i++] != '\"';);

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

static long search_setting_parameter(const char* config_file_string, const char* config)
{
	if (config_file_string == NULL || config == NULL)
		return INVALID_INPUT;

	long setting_position;

	setting_position = search_for_quoted_target_string(config, config_file_string);
	if (setting_position < 0)
	{
		return SETTING_NOT_FOUND;
	}
	return search_inline_parameter(config_file_string, setting_position);
}

static void append_config_to_file(FILE* autoexec, char** config_file_string, long menu, long config)
{
	if(cfg_menu[menu].config[config][0] == '\0')
		return;

	long i;
	long parameter_position;
	long new_line_start;
	int was_found;
	int str_length;

	for (i = 0, was_found = 0, new_line_start = 0; config_file_string[i] != NULL;)
	{
		parameter_position = search_setting_parameter(config_file_string[i] + new_line_start, cfg_menu[menu].config[config]);
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
			APPEND_BINDING(autoexec, menu, config, str_length, config_file_string[i] + parameter_position);
			was_found = 1;
			continue;
		}
		APPEND_CONFIG(autoexec, menu, config, str_length, config_file_string[i] + parameter_position);
		was_found = 1;
	}

	if (was_found)
		return;

	if (menu == KEYBOARD_AND_MOUSE && IS_BETWEEN(config, Yaw, Chat_Wheel_3))
		APPEND_COMMENTED_BINDING(autoexec, menu, config);
	else
		APPEND_COMMENTED_CONFIG(autoexec, menu, config);
}

void write_autoexec(char** config_file_string, FILE* autoexec)
{
	if (config_file_string == NULL || config_file_string[0] == NULL || autoexec == NULL)
		return;

	long menu, config;
	int sub_menu;

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
}