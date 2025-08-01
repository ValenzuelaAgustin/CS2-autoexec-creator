#include "menu.h"
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

//static const char error_message_1[] = "ERROR: Could not find .vcfg file";
static const char defuault_message[] = "Enter the number corresponding to the desired option:\t";
static const char default_select_file_name_message[] = "Enter the desired file name or \'r\' to return to the main menu:\t";
static const char default_change_directory_message[] = "Enter the desired directory or \'r\' to return to the main menu:\t";

static const char* const menu_name[] =
{
	"Main menu",
	"Create autoexec file",
	"Change output file name",
	"Change input directory",
	"Change output directory",
	"Add an additional input file"
};

static const char* const main_menu_options[] =
{
	menu_name[create_autoexec],
	menu_name[change_output_file_name],
	menu_name[change_input_directory],
	menu_name[change_output_directory],
	menu_name[add_additional_input_file],
	"Quit program"
};
static const int main_menu_options_ammount = sizeof(main_menu_options) / sizeof(main_menu_options[0]);

static const char* const create_autoexec_menu_options[] =
{
	menu_name[main_m],
	"Start"
};
static const int create_autoexec_menu_options_ammount = sizeof(create_autoexec_menu_options) / sizeof(create_autoexec_menu_options[0]);

static const char** const change_output_file_name_menu_options = NULL;
static const int change_output_file_name_menu_options_ammount = 0;
static const char** const change_input_directory_menu_options = NULL;
static const int change_input_directory_menu_options_ammount = 0;
static const char** const change_output_directory_menu_options = NULL;
static const int change_output_directory_menu_options_ammount = 0;
static const char** const add_additional_input_file_menu_options = NULL;
static const int add_additional_input_file_menu_options_ammount = 0;

static const menu_t menu[] =
{
	{
		menu_name[main_m],
		defuault_message,
		main_menu_options,
		main_menu_options_ammount
	},
	{
		menu_name[create_autoexec],
		defuault_message,
		create_autoexec_menu_options,
		create_autoexec_menu_options_ammount
	},
	{
		menu_name[change_output_file_name],
		default_select_file_name_message,
		change_output_file_name_menu_options,
		change_output_file_name_menu_options_ammount
	},
	{
		menu_name[change_input_directory],
		default_change_directory_message,
		change_input_directory_menu_options,
		change_input_directory_menu_options_ammount
	},
	{
		menu_name[change_output_directory],
		default_change_directory_message,
		change_output_directory_menu_options,
		change_output_directory_menu_options_ammount
	},
	{
		menu_name[add_additional_input_file],
		default_select_file_name_message,
		add_additional_input_file_menu_options,
		add_additional_input_file_menu_options_ammount
	}
};

static const char default_output_file_name[] = "autoexec.cfg";

static char additional_file_name[40] = "";
static const char* const file_name[] =
{
	"cs2_machine_convars.vcfg",
	"cs2_user_convars_0_slot0.vcfg",
	"cs2_user_keys_0_slot0.vcfg",	// THIS HAS TO BE IN THE THIRD POSITION OF THIS STRING
	additional_file_name
};

static char* config_file_string[5];
static char output_file_name[30];
static char output_file_directory[255];
static char input_file_directory[255];

static void clear_stdin();
static int selected_option();
static int standard_change_name_menu(char* const string, const int string_length, const int menu_index);
static int load_input_files();
static int create_autoexec_file(FILE** autoexec);

static void clear_stdin()
{
	int c = 0;
	while((c = getchar()) != '\n' && c != EOF);
}

static int selected_option()
{
	int c = getchar();
	clear_stdin();

	if((c -= '0') < 0)
		return -1;

	return c;
}

static int standard_change_name_menu(char* const string, const int string_length, const int menu_index)
{
	char buffer[3];

	if(fgets(buffer, sizeof(buffer), stdin) == NULL)
	{
		printf("\nThere was an error while trying to read the stdin\n");
		return main_m;
	}
	if(TO_UPPER(buffer[0]) == 'R' && buffer[1] == '\n')
	{
		return main_m;
	}

	if(fgets(string + 2, string_length - 2, stdin) == NULL)
	{
		printf("\nThere was an error while trying to read the stdin\n");
		return main_m;
	}
	string[0] = buffer[0];
	string[1] = buffer[1];

	int i;
	for(i = 0; string[i] && string[i] != '\n'; i++);

	if(string[i] == '\0')
	{
		switch(menu_index)
		{
		case change_input_directory:
		case change_output_directory:
			printf("The directory name is too large (max length = %d)\n", string_length - 2);
			break;

		case change_output_file_name:
		case add_additional_input_file:
			printf("The file name is too large (max length = %d)\n", string_length - 2);
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

	if(!SetCurrentDirectory(input_file_directory))
	{
		printf("\nBefore creating an autoexec file, you must first specify a valid input directory.");
		return 0;
	}

	for(i = 0; i < 4; i++)
	{
		free(config_file_string[i]);
 		config_file_string[i] = copy_file_to_string(file_name[i]);
	}
 	config_file_string[4] = NULL;

	if (config_file_string[0] == NULL || config_file_string[1] == NULL || config_file_string[2] == NULL)
	{
		printf("\nOne of the following files could not be open:");
		for(i = 0; i < 3; i++)
		{
			free(config_file_string[i]);
			config_file_string[i] = NULL;
			printf("\n\t%s", file_name[i]);
		}
		free(config_file_string[3]);
		config_file_string[3] = NULL;
		return 0;
	}

	return 1;
}

static int create_autoexec_file(FILE** autoexec)
{
	int default_name = 0;

	if(!SetCurrentDirectory(output_file_directory))
	{
		printf("\nBefore creating an autoexec file, you must first specify a valid output directory.");
		return 0;
	}
	*autoexec = fopen(output_file_name, "wb");

	if(*autoexec == NULL)
	{
		if(output_file_name[0] != '\0')
		{
			printf("\nThe program was unable to create the autoexec file with the custom name.\nTrying with \"%s\" instead...", default_output_file_name);
		}
		*autoexec = fopen(default_output_file_name, "wb");
		default_name = 1;
	}
	if(*autoexec == NULL)
	{
		printf("\nThe program was unable to create the autoexec file.");
		return 0;
	}

	printf("\nAutoexec file \"%s\" created in:\n\t%s", (default_name) ? default_output_file_name : output_file_name, output_file_directory);
	return 1;
}

void print_menu(int menu_index)
{
	if(menu_index < 0 || menu_index >= (sizeof(menu) / sizeof(menu[0])))
		return;

	unsigned int i;
	printf("\n%s", menu[menu_index].name);
	for (i = 0; i < menu[menu_index].options_ammount; i++)
	{
		printf("\n[%d] %s", i, menu[menu_index].options[i]);
	}
	printf("\n%s", menu[menu_index].message);
	fflush(stdout);
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
		for(i = 0; i < 4; i++)
		{
			free(config_file_string[i]);
			config_file_string[i] = NULL;
		}
		printf("\nReturning to the main menu...\n");
		return main_m;
	}

	write_autoexec(autoexec, config_file_string);
	fclose(autoexec);

	for(i = 0; i < 4; i++)
	{
		free(config_file_string[i]);
		config_file_string[i] = NULL;
	}

	printf("\nAutoexec created succesfully\n");
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