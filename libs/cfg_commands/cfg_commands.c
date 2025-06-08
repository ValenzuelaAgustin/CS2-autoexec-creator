#include "cfg_commands.h"

int ammount_of_menu = 3;

cfg_menu_t config_menu[] =
{
	{
		"Audio",
		Audio_Settings_Sub_Menu_Titles,
		Audio_Sub_Menu_Last_Config,
		Audio_Settings_Names,
		Audio_Settings
	},
	{
		"Game",
		Game_Settings_Sub_Menu_Titles,
		Game_Sub_Menu_Last_Config,
		Game_Settings_Names,
		Game_Settings
	},
	{
		"Keyboard / Mouse",
		Keyboard_And_Mouse_Settings_Sub_Menu_Titles,
		Keyboard_And_Mouse_Sub_Menu_Last_Config,
		Keyboard_And_Mouse_Settings_Names,
		Keyboard_And_Mouse_Settings
	}
};