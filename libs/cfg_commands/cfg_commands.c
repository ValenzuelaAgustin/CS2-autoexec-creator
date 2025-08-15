#include "cfg_commands.h"
#include "audio.h"
#include "game.h"
#include "keyboard_and_mouse.h"
#include "other_settings.h"

const cfg_menu_t cfg_menu[] =
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
	},
	{
		Other_Settings_Sub_Menu_Titles,
		Other_Settings_Sub_Menu_Last_Config,
		Other_Settings_Names,
		Other_Settings
	}
};

const int menu_ammount = sizeof(cfg_menu) / sizeof(cfg_menu[0]);