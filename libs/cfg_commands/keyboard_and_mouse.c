#include "keyboard_and_mouse.h"
#include <stdlib.h>

const char* Keyboard_And_Mouse_Settings[] =
{
	// Keyboard & Mouse Settings
	"mouse_inverty",
	"option_duck_method",
	"option_speed_method",
	"cl_debounce_zoom",
	"sensitivity",
	"zoom_sensitivity_ratio",
	"yaw",
	"pitch",

	// Movement Keys
	"show_loadout_toggle",
	"+forward",
	"+back",
	"+left",
	"+right",
	"+sprint",
	"+duck",
	"+jump",

	// Weapon Keys
	"+use",
	"+attack",
	"+attack2",
	"+reload",
	"+quickinv",
	"invprev",
	"invnext",
	"lastinv",
	"drop",
	"+lookatweapon",
	"switchhands",
	"buymenu",
	"autobuy",
	"rebuy",
	"slot1",
	"slot2",
	"slot3",
	"slot4",
	"slot5",
	"slot6",
	"slot7",
	"slot8",
	"slot9",
	"slot10",
	"slot11",
	"slot12",
	"slot13",
	"+spray_menu",

	// UI Keys
	"+showscores",
	"+cl_show_team_equipment",
	"toggleradarscale",
	"callvote",
	"teammenu",
	"toggleconsole",

	// Communication Options
	"player_ping",
	"radio",
	"radio1",
	"radio2",
	"radio3",
	"messagemode2",
	"messagemode",
	"+voicerecord",
	"clutch_mode_toggle",

	// Chat Wheel Keys
	"+radialradio",
	"+radialradio2",
	"+radialradio3",

	// Chat Wheel phrases
	"cl_radial_radio_tab_0_text_1",
	"cl_radial_radio_tab_0_text_2",
	"cl_radial_radio_tab_0_text_3",
	"cl_radial_radio_tab_0_text_4",
	"cl_radial_radio_tab_0_text_5",
	"cl_radial_radio_tab_0_text_6",
	"cl_radial_radio_tab_0_text_7",
	"cl_radial_radio_tab_0_text_8",

	"cl_radial_radio_tab_1_text_1",
	"cl_radial_radio_tab_1_text_2",
	"cl_radial_radio_tab_1_text_3",
	"cl_radial_radio_tab_1_text_4",
	"cl_radial_radio_tab_1_text_5",
	"cl_radial_radio_tab_1_text_6",
	"cl_radial_radio_tab_1_text_7",
	"cl_radial_radio_tab_1_text_8",

	"cl_radial_radio_tab_2_text_1",
	"cl_radial_radio_tab_2_text_2",
	"cl_radial_radio_tab_2_text_3",
	"cl_radial_radio_tab_2_text_4",
	"cl_radial_radio_tab_2_text_5",
	"cl_radial_radio_tab_2_text_6",
	"cl_radial_radio_tab_2_text_7",
	"cl_radial_radio_tab_2_text_8"
};

const char* Keyboard_And_Mouse_Settings_Names[] =
{
	// Keyboard & Mouse Settings
	"Reverse Mouse",
	"Duck Mode",
	"Walk Mode",
	"Zoom Button Hold",
	"Mouse Sensitivity",
	"Zoom Sensitivity Multiplier",
	"Yaw",
	"Pitch",

	// Movement Keys
	"Toggle Inventory Display",
	"Move Forward",
	"Move Backward",
	"Move Left (strafe)",
	"Move Right (strafe)",
	"walk",
	"Duck",
	"Jump",

	// Weapon Keys
	"Use",
	"Fire",
	"Secondary Fire",
	"Reload",
	"Radial Weapon Menu",
	"Select previous Weapon",
	"Select Next Weapon",
	"Last Weapon Used",
	"Drop Weapon",
	"Inspect Weapon",
	"Switch Viewmodel Left/Right Hand",
	"Buy Menu",
	"Autobuy",
	"Rebuy",
	"Primary Weapon",
	"Secondary Weapon",
	"Melee Weapons",
	"Cycle Grenades",
	"Explosives & Traps",
	"HE Grenade",
	"Flashbang",
	"Smoke Grenade",
	"Decoy Grenade",
	"Molotov Cocktail / Incendiary Grenade",
	"Zeus x27",
	"Healthshot",
	"Utility Items",
	"Graffiti Menu",

	// UI Keys
	"Scoreboard",
	"Show Team Equipment",
	"Toggle Radar Zoom",
	"Call Vote",
	"Choose Team",
	"Toggle Console",

	// Communication Options
	"Player Ping",
	"Radio Message",
	"Command Radio Message",
	"Standard Radio Message",
	"Report Radio Message",
	"Team Message",
	"Chat Message",
	"Use Microphone",
	"Temporarily Disable Incoming Chat",

	// Chat Wheel Keys
	"Chat Wheel 1",
	"Chat Wheel 2",
	"Chat Wheel 3",

	// Chat Wheel phrases
	"Chat Wheel 1 Text 1",
	"Chat Wheel 1 Text 2",
	"Chat Wheel 1 Text 3",
	"Chat Wheel 1 Text 4",
	"Chat Wheel 1 Text 5",
	"Chat Wheel 1 Text 6",
	"Chat Wheel 1 Text 7",
	"Chat Wheel 1 Text 8",

	"Chat Wheel 2 Text 1",
	"Chat Wheel 2 Text 2",
	"Chat Wheel 2 Text 3",
	"Chat Wheel 2 Text 4",
	"Chat Wheel 2 Text 5",
	"Chat Wheel 2 Text 6",
	"Chat Wheel 2 Text 7",
	"Chat Wheel 2 Text 8",

	"Chat Wheel 3 Text 1",
	"Chat Wheel 3 Text 2",
	"Chat Wheel 3 Text 3",
	"Chat Wheel 3 Text 4",
	"Chat Wheel 3 Text 5",
	"Chat Wheel 3 Text 6",
	"Chat Wheel 3 Text 7",
	"Chat Wheel 3 Text 8"
};

const char* Keyboard_And_Mouse_Settings_Sub_Menu_Titles[] =
{
	"Keyboard & Mouse Settings",
	"Movement Keys",
	"Weapon Keys",
	"UI Keys",
	"Communication Options",
	"Chat Wheel Keys",
	"Chat Wheel phrases"
};

int Keyboard_And_Mouse_Sub_Menu_Last_Config[] =
{
	Pitch,
	Jump,
	Graffiti_Menu,
	Toggle_Console,
	Temporarily_Disable_Incoming_Chat,
	Chat_Wheel_3,
	Chat_Wheel_3_Text_8,
	-1
};

/*
const char* input_bindings[] =
{
	// Alphabet keys
	"a", "b", "c", "d", "e", "f", "g", "h", "i", "j",
	"k", "l", "m", "n", "o", "p", "q", "r", "s", "t",
	"u", "v", "w", "x", "y", "z",

	// Number keys
	"0", "1", "2", "3", "4", "5", "6", "7", "8", "9",

	// Function keys
	"f1", "f2", "f3", "f4", "f5", "f6",
	"f7", "f8", "f9", "f10", "f11", "f12",

	// Control keys
	"shift", "ctrl", "alt", "tab", "capslock", "esc", "enter", "space",
	"backspace", "delete", "insert", "home", "end", "pgup", "pgdn",

	// Arrow keys
	"uparrow", "downarrow", "leftarrow", "rightarrow",

	// Mouse
	"mouse_x", "mouse_y", "mouse1", "mouse2", "mouse3", "mouse4", "mouse5",
	"mwheelup", "mwheeldown",

	// Numpad keys
	"kp_ins", "kp_end", "kp_downarrow", "kp_pgdn",
	"kp_leftarrow", "kp_5", "kp_rightarrow",
	"kp_home", "kp_uparrow", "kp_pgup",
	"kp_slash", "kp_multiply", "kp_minus",
	"kp_plus", "kp_enter", "kp_del",

	// Miscellaneous
	"`", "-", "=", "[", "]", "\\", ";", "'", ",", ".", "/",
	NULL
};
*/