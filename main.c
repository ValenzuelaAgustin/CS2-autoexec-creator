#include "libs\menu\menu.h"
#include <stdio.h>

int main()
{
	int current_menu = -1;
	int next_menu = main_m;

	while(next_menu != QUIT)
	{
		if(current_menu != next_menu)
		{
			print_menu(next_menu);
			current_menu = next_menu;
		}
		switch(current_menu)
		{
		case main_m:
			next_menu = main_menu();
			break;
		case create_autoexec:
			next_menu = create_autoexec_menu();
			break;
		case change_output_file_name:
			next_menu = change_output_file_name_menu();
			break;
		case change_input_directory:
			next_menu = change_input_directory_menu();
			break;
		case change_output_directory:
			next_menu = change_output_directory_menu();
			break;
		case add_aditional_input_file:
			next_menu = add_aditional_input_file_menu();
			break;
		}
	}
	return 0;
}