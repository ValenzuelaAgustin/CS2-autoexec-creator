#include "menu.h"
#include "..\cfg_commands\keyboard_and_mouse.h"
#include "..\nstd_string\nstd_string.h"
#include "..\autoexec_creator\autoexec_creator.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct
{
	const char* name;
	const char* message;
	const char* const * options;
	int options_ammount;
} menu_t;

static char NULL_TERMINATOR = '\0';
static const char default_output_file_name[] = "autoexec.cfg";
static const char defuault_message[] = "Enter the number corresponding to the desired option:\t";
static const char default_select_file_name_message[] = "Enter the desired file name or just press ENTER to return to the main menu:\t";
static const char default_change_directory_message[] = "Enter the desired directory or just press ENTER to return to the main menu:\t";

static const char* const menu_name[] =
{
	"Main menu",
	"Create autoexec file",
	"Set \"enter_missing_commands_values\"",
	"Set \"use_only_additional_input_file\"",
	"Change output file name",
	"Change input directory",
	"Change output directory",
	"Add an additional input file"
};

static const char* const main_menu_options[] =
{
	menu_name[create_autoexec],
	menu_name[set_enter_missing_commands_values],
	menu_name[set_use_only_additional_input_file],
	menu_name[change_output_file_name],
	menu_name[change_input_directory],
	menu_name[change_output_directory],
	menu_name[add_additional_input_file],
	"Quit program"
};

static const char* const create_autoexec_menu_options[] =
{
	menu_name[main_m],
	"Start"
};

static const char* const default_set_variable_menu_options[] =
{
	menu_name[main_m],
	"true",
	"false"
};

static const menu_t menu[] =
{
	{
		menu_name[main_m],
		defuault_message,
		main_menu_options,
		sizeof(main_menu_options) / sizeof(main_menu_options[0])
	},
	{
		menu_name[create_autoexec],
		defuault_message,
		create_autoexec_menu_options,
		sizeof(create_autoexec_menu_options) / sizeof(create_autoexec_menu_options[0])
	},
	{
		menu_name[set_enter_missing_commands_values],
		defuault_message,
		default_set_variable_menu_options,
		sizeof(default_set_variable_menu_options) / sizeof(default_set_variable_menu_options[0])
	},
	{
		menu_name[set_use_only_additional_input_file],
		defuault_message,
		default_set_variable_menu_options,
		sizeof(default_set_variable_menu_options) / sizeof(default_set_variable_menu_options[0])
	},
	{
		menu_name[change_output_file_name],
		default_select_file_name_message,
		NULL,
		0
	},
	{
		menu_name[change_input_directory],
		default_change_directory_message,
		NULL,
		0
	},
	{
		menu_name[change_output_directory],
		default_change_directory_message,
		NULL,
		0
	},
	{
		menu_name[add_additional_input_file],
		default_select_file_name_message,
		NULL,
		0
	}
};

static char additional_file_name[40] = "";
static const char* const file_name[] =
{
	"cs2_machine_convars.vcfg",
	"cs2_user_convars_0_slot0.vcfg",
	"cs2_user_keys_0_slot0.vcfg",	// THIS HAS TO BE IN THE THIRD POSITION OF THIS STRING
	additional_file_name
};
static int using_default_output_file_name;
static int enter_missing_commands_values = 0;
static int use_only_additional_input_file = 0;
static char* config_file_string[5];
static char output_file_name[32];
static char output_file_directory[256];
static char input_file_directory[256];
static const char* default_directory = NULL;
static int using_default_directory[2];
enum
{
	INPUT_DIR,
	OUTPUT_DIR
};

static void _print_menu(const menu_t* menu);
static void clear_stdin();
static int selected_option();
static int standard_change_name_menu(char* string, const int string_length, const int menu_index);
static int load_input_files();
static int create_autoexec_file(FILE** autoexec);
static const char* command_not_found_handler(const char* command_name, int is_a_bind);

static void _print_menu(const menu_t* menu)
{
	if (menu == NULL)
		return;

	unsigned int i;
	printf("\n# %s:", menu->name);
	for (i = 0; i < menu->options_ammount; i++)
	{
		printf("\n[%d] %s", i, menu->options[i]);
	}
	printf("\n%s", menu->message);
	fflush(stdout);
}

static void clear_stdin()
{
	int c = 0;
	while((c = getchar()) != '\n' && c != EOF);
}

static int selected_option()
{
	int c = getchar();
	if(c != '\n')
		clear_stdin();
	if((c -= '0') < 0)
		return -1;
	return c;
}

static int standard_change_name_menu(char* string, const int string_length, const int menu_index)
{
	int c = getchar();
	int i;

	if(c == '\n')
	{
		return main_m;
	}

	if(fgets(string + 1, string_length - 1, stdin) == NULL)
	{
		printf("\nThere was an error while trying to read the stdin\n");
		return main_m;
	}
	string[0] = c;

	for(i = 0; string[i] && string[i] != '\n'; i++);

	if(string[i] == '\0' && (c = getchar()) != '\n')
	{
		switch(menu_index)
		{
		case change_input_directory:
		case change_output_directory:
			printf("The directory name is too large (max length = %d)\n", string_length - 1);
			break;

		case change_output_file_name:
		case add_additional_input_file:
			printf("The file name is too large (max length = %d)\n", string_length - 1);
			break;
		}
		clear_stdin();
		string[0] = '\0';
		printf("%s", menu[menu_index].message);
		return menu_index;
	}

	string[i] = '\0';

	switch(menu_index)
	{
	case change_input_directory:
	case change_output_directory:
		printf("The directory name was stored successfully\n");
		break;

	case change_output_file_name:
	case add_additional_input_file:
		printf("The file name was stored successfully\n");
		break;
	}

	return main_m;
}

static int load_input_files()
{
	long i;

	using_default_directory[INPUT_DIR] = 0;
	if(!SetCurrentDirectory(input_file_directory))
	{
		if(input_file_directory[0])
			printf("\nThe program was unable to set the input directory to: %s", input_file_directory);
		if((!default_directory || !SetCurrentDirectory(default_directory)))
		{
			if(default_directory && default_directory[0])
				printf("\nThe program was unable to set the input directory to: %s", default_directory);
			printf("\nBefore creating an autoexec file, you must first specify a valid input directory.");
			return 0;
		}
		using_default_directory[INPUT_DIR] = 1;
	}

	for(i = (use_only_additional_input_file) ? 3 : 0; i < 4; i++)
	{
 		config_file_string[i] = copy_file_to_string(file_name[i]);
	}
 	config_file_string[4] = NULL;

	if(use_only_additional_input_file && !config_file_string[3])
	{
		if(additional_file_name[0])
		{
			printf("\nThe program was unable to open the file: %s\\%s", (using_default_directory[INPUT_DIR]) ? default_directory : input_file_directory, additional_file_name);
		}
		else
		{
			printf("\nIf you want to create an autoexec file using only an external file, you must first specify the name of such file...");
		}
		return 0;
	}
	if(!use_only_additional_input_file && (config_file_string[0] == NULL || config_file_string[1] == NULL || config_file_string[2] == NULL))
	{
		printf("\nThe following files could not be open:");
		for(i = 0; i < 3; i++)
		{
			if(config_file_string[i] == NULL)
				printf("\n\t%s", file_name[i]);
			free(config_file_string[i]);
			config_file_string[i] = NULL;
		}
		free(config_file_string[3]);
		config_file_string[3] = NULL;
		return 0;
	}

	for(i = 0; use_only_additional_input_file && i < 3; i++)
	{
		config_file_string[i] = &NULL_TERMINATOR;
	}

	return 1;
}

static int create_autoexec_file(FILE** autoexec)
{
	using_default_output_file_name = 0;

	using_default_directory[OUTPUT_DIR] = 0;
	if(!SetCurrentDirectory(output_file_directory))
	{
		if(output_file_directory[0])
			printf("\nThe program was unable to set the output directory to: %s", output_file_directory);
		if((!default_directory || !SetCurrentDirectory(default_directory)))
		{
			if(default_directory && default_directory[0])
				printf("\nThe program was unable to set the output directory to: %s", default_directory);
			printf("\nBefore creating an autoexec file, you must first specify a valid output directory.");
			return 0;
		}
		using_default_directory[OUTPUT_DIR] = 1;
	}
	*autoexec = fopen(output_file_name, "wb");

	if(*autoexec == NULL)
	{
		if(output_file_name[0] != '\0')
		{
			printf("\nThe program was unable to create the autoexec file with the custom name.\nTrying with \"%s\" instead...", default_output_file_name);
		}
		*autoexec = fopen(default_output_file_name, "wb");
		using_default_output_file_name = 1;
	}
	if(*autoexec == NULL)
	{
		printf("\nThe program was unable to create the autoexec file.");
		return 0;
	}

	return 1;
}

static const char* command_not_found_handler(const char* command_name, int is_a_bind)
{
	static char buffer[50];
	int is_a_valid_key, i, c;

	for(is_a_valid_key = 0, buffer[0] = '\0'; !is_a_valid_key;)
	{
		printf("\nThere is no assigned %s for this command:\t\"%s\"", (is_a_bind) ? "key" : "value", command_name);
		printf("\nType the %s for \"%s\" or just press ENTER to leave it blank:\t", (is_a_bind) ? "key name without spaces" : "value", command_name);
		if(fgets(buffer, sizeof(buffer), stdin) == NULL)
		{
			printf("\nThere was an error while trying to read the stdin\n");
			return NULL;
		}
		if(buffer[0] == '\n')
		{
			break;
		}
		for(i = 0; buffer[i] && buffer[i] != '\n'; i++);
		if(!buffer[i] && (c = getchar()) != '\n')
		{
			printf("\nThe input was to large for the buffer, the maximum length is %lld", sizeof(buffer) - 1);
			clear_stdin();
			continue;
		}
		buffer[i] = '\0';
		if(!is_a_bind)
		{
			is_a_valid_key = 1;
			break;
		}
		if(!buffer[1] && IS_A_LETTER(buffer[0]))
		{
			buffer[0] = TO_LOWER(buffer[0]);
			is_a_valid_key = 1;
			break;
		}
		for(i = 0; buffer[i]; i++)
		{
			buffer[i] = TO_UPPER(buffer[i]);
		}
		for(i = 0; i < ammount_of_keys && !string_compare(Keys[i], buffer); i++);
		if(i != ammount_of_keys)
		{
			is_a_valid_key = 1;
			break;
		}
		printf("\n\"%s\" is not a valid key for a bind.", buffer);
	}

	return (is_a_valid_key) ? buffer : NULL;
}

void print_menu(int menu_index)
{
	if(menu_index < 0 || menu_index >= (sizeof(menu) / sizeof(menu[0])))
		return;

	_print_menu(&menu[menu_index]);
}

void change_default_directory(const char* directory)
{
	default_directory = directory;
}

int main_menu()
{
	int option = selected_option();

	if(option < 0 || option >= menu[main_m].options_ammount)
	{
		printf("Not an option");
		printf("\n%s", menu[main_m].message);
		return main_m;
	}

	return option + 1;
}

int create_autoexec_menu()
{
	int i;
	int option = selected_option();
	FILE* autoexec = NULL;

	if(option < 0 || option >= menu[create_autoexec].options_ammount)
	{
		printf("Not an option.");
		printf("\n%s", menu[create_autoexec].message);
		return create_autoexec;
	}
	if(!option)
		return main_m;

	if(!load_input_files())
	{
		printf("\nReturning to the main menu...\n");
		return main_m;
	}

	if(!create_autoexec_file(&autoexec))
	{
		for(i = (use_only_additional_input_file) ? 3 : 0; i < 4; i++)
		{
			free(config_file_string[i]);
			config_file_string[i] = NULL;
		}
		for(i = 0; use_only_additional_input_file && i < 3; i++)
		{
			config_file_string[i] = NULL;
		}
		printf("\nReturning to the main menu...\n");
		return main_m;
	}

	write_autoexec(autoexec, config_file_string, (enter_missing_commands_values) ? command_not_found_handler : NULL);
	fclose(autoexec);

	for(i = (use_only_additional_input_file) ? 3 : 0; i < 4; i++)
	{
		free(config_file_string[i]);
		config_file_string[i] = NULL;
	}
	for(i = 0; use_only_additional_input_file && i < 3; i++)
	{
		config_file_string[i] = NULL;
	}

	printf("\nAutoexec file \"%s\" created in:\n\t%s\n", (using_default_output_file_name) ? default_output_file_name : output_file_name, (using_default_directory[OUTPUT_DIR]) ? default_directory : output_file_directory);
	return main_m;
}

int set_enter_missing_commands_values_menu()
{
	int option = selected_option();

	if(option < 0 || option >= menu[set_enter_missing_commands_values].options_ammount)
	{
		printf("Not an option");
		printf("\n%s", menu[set_enter_missing_commands_values].message);
		return set_enter_missing_commands_values;
	}

	switch(option)
	{
	case 1:
		enter_missing_commands_values = 1;
		printf("enter_missing_commands_values set to 1\n");
		break;
	case 2:
		enter_missing_commands_values = 0;
		printf("enter_missing_commands_values set to 0\n");
		break;
	}

	return main_m;
}

int set_use_only_additional_input_file_menu()
{
	int option = selected_option();

	if(option < 0 || option >= menu[set_use_only_additional_input_file].options_ammount)
	{
		printf("Not an option");
		printf("\n%s", menu[set_use_only_additional_input_file].message);
		return set_use_only_additional_input_file;
	}

	switch(option)
	{
	case 1:
		use_only_additional_input_file = 1;
		printf("use_only_additional_input_file set to 1\n");
		break;
	case 2:
		use_only_additional_input_file = 0;
		printf("use_only_additional_input_file set to 0\n");
		break;
	}

	return main_m;
}

int change_output_file_name_menu()
{
	return standard_change_name_menu(output_file_name, sizeof(output_file_name), change_output_file_name);
}

int change_input_directory_menu()
{
	return standard_change_name_menu(input_file_directory, sizeof(input_file_directory), change_input_directory);
}

int change_output_directory_menu()
{
	return standard_change_name_menu(output_file_directory, sizeof(output_file_directory), change_output_directory);
}

int add_additional_input_file_menu()
{
	return standard_change_name_menu(additional_file_name, sizeof(additional_file_name), add_additional_input_file);
}