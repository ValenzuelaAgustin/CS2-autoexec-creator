#include "autoexec_creator.h"
#include "..\nstd_string\nstd_string.h"
#include "..\cfg_commands\cfg_commands.h"

#define IS_BETWEEN(x, min, max) ((x) >= (min) && (x) <= (max))

static long search_inline_parameter(const char* string, long setting_position);

static long search_setting_parameter(const char* config_file_string, long menu, long config);

static void append_config_to_file(FILE* autoexec, char** config_file_string, long menu, long config);

static long search_inline_parameter(const char* string, long setting_position)
{
	if ( string == NULL || setting_position < 0)
		return INVALID_INPUT;

	long i, parameter_position;
	int qm_counter;

	for (i = setting_position; i > 0 && string[i] != '\n'; i--);

	for ((string[i] == '\n') ? i++ : i, qm_counter = 0; i < setting_position - 1 && qm_counter < 2; i++)
	{
		if (string[i] == '\"')
		{
			qm_counter++;
			parameter_position = (qm_counter == 1) ? i + 1 : parameter_position;
		}
	}

	if (qm_counter == 2)
		return parameter_position;

	for (i = setting_position; string[i++] != '\"';);

	for (qm_counter = 0; string[i] && string[i] != '\n' && qm_counter < 2; i++)
	{
		if (string[i] == '\"')
		{
			qm_counter++;
			parameter_position = (qm_counter == 1) ? i + 1 : parameter_position;
		}
	}

	return (qm_counter == 2) ? parameter_position : PARAMETER_NOT_FOUND;
}

static long search_setting_parameter(const char* config_file_string, long menu, long config)
{
	if (config_file_string == NULL || menu < 0 || config < 0)
		return INVALID_INPUT;

	long setting_position;

	setting_position = search_for_quoted_target_string(cfg_menu[menu].config[config], config_file_string);
	if (setting_position < 0)
	{
		return setting_position;
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
		parameter_position = search_setting_parameter(config_file_string[i] + new_line_start, menu, config);
		if (parameter_position < 0)
		{
			i++;
			new_line_start = 0;
			continue;
		}
		parameter_position += new_line_start;
		for (new_line_start = parameter_position; config_file_string[i][new_line_start] != '\n' && config_file_string[i][new_line_start] != '\0'; new_line_start++);
		for (str_length = 0; config_file_string[i][parameter_position + str_length] != '\"'; str_length++);

		if (menu == 2 && IS_BETWEEN(config, Yaw, Chat_Wheel_3))
		{
			fprintf(autoexec, "bind \"%.*s\" \"%s\"\t\t\t\t// %s\n", str_length, config_file_string[i] + parameter_position, cfg_menu[menu].config[config], cfg_menu[menu].config_name[config]);
			was_found = 1;
			continue;
		}
		fprintf(autoexec, "%s \"%.*s\"\t\t\t\t// %s\n", cfg_menu[menu].config[config], str_length, config_file_string[i] + parameter_position, cfg_menu[menu].config_name[config]);
		was_found = 1;
	}

	if (!was_found && menu == 2 && IS_BETWEEN(config, Yaw, Chat_Wheel_3))
		fprintf(autoexec, "// bind \"\" \"%s\"\t\t\t\t// %s\n", cfg_menu[menu].config[config], cfg_menu[menu].config_name[config]);
	else if (!was_found)
		fprintf(autoexec, "// %s \"\"\t\t\t\t// %s\n", cfg_menu[menu].config[config], cfg_menu[menu].config_name[config]);
}

void write_autoexec(char** config_file_string, FILE* autoexec)
{
	if (config_file_string == NULL || config_file_string[0] == NULL || autoexec == NULL)
		return;

	long menu, config;
	int sub_menu;

	for (menu = 0; menu < menu_ammount; menu++)
	{
		for (config = 0, sub_menu = 0; cfg_menu[menu].sub_menu_last_config[sub_menu] > -1; config++, sub_menu += (config > cfg_menu[menu].sub_menu_last_config[sub_menu])? 1 : 0)
		{
			if (config == 0)
			{
				fprintf(autoexec, "%s//%s\n\n", (menu != 0) ? "\n\n" : "", cfg_menu[menu].sub_menu_title[sub_menu]);
			}
			else if (config == cfg_menu[menu].sub_menu_last_config[sub_menu - 1] + 1)
			{
				fprintf(autoexec, "\n\n//%s\n\n", cfg_menu[menu].sub_menu_title[sub_menu]);
			}
			append_config_to_file(autoexec, config_file_string, menu, config);
		}
	}
}