#include "keyboard_and_mouse.h"
#include <stdlib.h>

const char* const Keyboard_And_Mouse_Settings[] =
{
	// Keyboard_&_Mouse_Settings
	"mouse_inverty",
	"option_duck_method",
	"option_speed_method",
	"cl_debounce_zoom",
	"sensitivity",
	"zoom_sensitivity_ratio",

	// Movement_Keys
	"show_loadout_toggle",
	"+forward",
	"+back",
	"+left",
	"+right",
	"+sprint",
	"+duck",
	"+jump",

	// Weapon_Keys
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

	// Ul_Keys
	"+showscores",
	"+cl_show_team_equipment",
	"toggleradarscale",
	"callvote",
	"teammenu",
	"toggleconsole",

	// Communication_Options
	"player_ping",
	"radio",
	"radio1",
	"radio2",
	"radio3",
	"messagemode2",
	"messagemode",
	"+voicerecord",
	"clutch_mode_toggle",

	// Chat_Wheel_Keys
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
	"cl_radial_radio_tab_2_text_8",
	NULL
};

char* input_bindings[] =
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

    // Mouse buttons
    "mouse1", "mouse2", "mouse3", "mouse4", "mouse5",
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