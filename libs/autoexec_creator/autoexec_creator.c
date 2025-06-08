#include "autoexec_creator.h"
#include "..\nstd_string\nstd_string.h"
#include "..\cfg_commands\cfg_commands.h"

static long search_inline_parameter(const char* string, long setting_position);

void append_configs_to_file(char** config_file_string, FILE* autoexec)
{
	if (config_file_string == NULL || autoexec == NULL)
		return;

	//char** config[] = {(char**)Audio_Settings, (char**)Game_Settings, (char**)Keyboard_And_Mouse_Settings, NULL};
	long i, j, k;
	long setting_position;
	long parameter_position;
	int str_length;

	int was_found;
	int sub_menu;

	for (i = 0; i < menu_ammount; i++)
	{
		for (j = 0, sub_menu = 0; cfg_menu[i].sub_menu_last_config[sub_menu] > -1; j++, sub_menu += (j > cfg_menu[i].sub_menu_last_config[sub_menu])? 1 : 0)
		{
			if (j == 0)
			{
				fprintf(autoexec, "%s//%s\n\n", (i != 0) ? "\n\n" : "", cfg_menu[i].sub_menu_title[sub_menu]);
			}
			else if (j == cfg_menu[i].sub_menu_last_config[sub_menu - 1] + 1)
			{
				fprintf(autoexec, "\n\n//%s\n\n", cfg_menu[i].sub_menu_title[sub_menu]);
			}

			for (k = 0, was_found = 0; config_file_string[k] != NULL; k++)
			{
				setting_position = search_for_quoted_target_string(cfg_menu[i].config[j], config_file_string[k]);
				if (setting_position == STRING_NOT_FOUND || setting_position == INVALID_INPUT)
				{
					continue;
				}
				parameter_position = search_inline_parameter(config_file_string[k], setting_position);
				if (parameter_position == PARAMETER_NOT_FOUND || parameter_position == INVALID_INPUT)
				{
					continue;
				}
				for (str_length = 0; config_file_string[k][parameter_position + str_length] != '\"'; str_length++);

				if (i == 2 && j >= Yaw && j <= Chat_Wheel_3)
				{
					fprintf(autoexec, "bind \"%.*s\" \"%s\"\t\t\t\t// %s\n", str_length, config_file_string[k] + parameter_position, cfg_menu[i].config[j], cfg_menu[i].config_name[j]);
					was_found = 1;
					continue;
				}
				fprintf(autoexec, "%s \"%.*s\"\t\t\t\t// %s\n", cfg_menu[i].config[j], str_length, config_file_string[k] + parameter_position, cfg_menu[i].config_name[j]);
				was_found = 1;
			}
			if(cfg_menu[i].config[j][0] == '\0')
				continue;
			if (!was_found && i == 2 && j >= Yaw && j <= Chat_Wheel_3)
				fprintf(autoexec, "// bind \"\" \"%s\"\t\t\t\t// %s\n", cfg_menu[i].config[j], cfg_menu[i].config_name[j]);
			else if (!was_found)
				fprintf(autoexec, "// %s \"\"\t\t\t\t// %s\n", cfg_menu[i].config[j], cfg_menu[i].config_name[j]);
		}
	}
}

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