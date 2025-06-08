#include "cfg_commands.h"

int menu_ammount = 3;

cfg_menu_t cfg_menu[] =
{
	{
		Audio_Settings_Sub_Menu_Titles,
		Audio_Sub_Menu_Last_Config,
		Audio_Settings_Names,
		Audio_Settings
	},
	{
		Game_Settings_Sub_Menu_Titles,
		Game_Sub_Menu_Last_Config,
		Game_Settings_Names,
		Game_Settings
	},
	{
		Keyboard_And_Mouse_Settings_Sub_Menu_Titles,
		Keyboard_And_Mouse_Sub_Menu_Last_Config,
		Keyboard_And_Mouse_Settings_Names,
		Keyboard_And_Mouse_Settings
	}
};