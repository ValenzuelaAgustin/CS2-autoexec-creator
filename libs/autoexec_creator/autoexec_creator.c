#include "autoexec_creator.h"
#include "..\nstd_string\nstd_string.h"
#include "..\cfg_commands\cfg_commands.h"

static long search_inline_parameter(const char* string, long setting_position);

void append_configs_to_file(char** config_file_string, FILE* autoexec)
{
	if (config_file_string == NULL || autoexec == NULL)
		return;

	char** config[] = {(char**)Audio_Settings, (char**)Game_Settings, (char**)Keyboard_And_Mouse_Settings, NULL};
	long i, j, k;
	long setting_position;
	long parameter_position;
	long str_length;

	for (i = 0; config[i] != NULL; i++)
	{
		for (j = 0; config[i][j] != NULL; j++)
		{
			for (k = 0; config_file_string[k] != NULL; k++)
			{
				setting_position = search_for_quoted_target_string(config[i][j], config_file_string[k]);
				if (setting_position == STRING_NOT_FOUND)
				{
					continue;
				}
				parameter_position = search_inline_parameter(config_file_string[k], setting_position);
				if (parameter_position == PARAMETER_NOT_FOUND)
				{
					continue;
				}
				for (str_length = 0; config_file_string[k][parameter_position + str_length] != '\"'; str_length++);

				if (i == 2 && j >= Yaw && j <= Chat_Wheel_3)
				{
					fprintf(autoexec, "bind \"%.*s\" \"%s\"\n", str_length, config_file_string[k] + parameter_position, config[i][j]);
					continue;
				}
				fprintf(autoexec, "%s \"%.*s\"\n", config[i][j], str_length, config_file_string[k] + parameter_position);
			}
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