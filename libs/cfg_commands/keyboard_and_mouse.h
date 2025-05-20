#ifndef KEYBOARD_AND_MOUSE_H
#define KEYBOARD_AND_MOUSE_H

extern const char* const Keyboard_And_Mouse_Settings[];

enum
{
	// Keyboard_&_Mouse_Settings
	Reverse_Mouse,
	Duck_Mode,
	Walk_Mode,
	Zoom_Button_Hold,
	Mouse_Sensitivity,
	Zoom_Sensitivity_Multiplier,

	// Movement_Keys
	Toggle_Inventory_Display,
	Move_Forward,
	Move_Backward,
	Move_Left_strafe,
	Move_Right_strafe,
	Walk,
	Duck,
	Jump,

	// Weapon_Keys
	Use,
	Fire,
	Secondary_Fire,
	Reload,
	Radial_Weapon_Menu,
	Select_Previous_Weapon,
	Select_Next_Weapon,
	Last_Weapon_Used,
	Drop_Weapon,
	Inspect_Weapon,
	Switch_Viewmodel_Left_Right_Hand,
	Buy_Menu,
	Autobuy,
	Rebuy,
	Primary_Weapon,
	Secondary_Weapon,
	Melee_Weapons,
	Cycle_Grenades,
	Explosives_And_Traps,
	HE_Grenade,
	Flashbang,
	Smoke_Grenade,
	Decoy_Grenade,
	Molotov_Cocktail_Incendiary_Grenade,
	Zeus_x27,
	Healthshot,
	Utility_Items,
	Graffiti_Menu,

	// Ul_Keys
	Scoreboard,
	Show_Team_Equipment,
	Toggle_Radar_Zoom,
	Call_Vote,
	Choose_Team,
	Toggle_Console,

	// Communication_Options
	Player_Ping,
	Radio_Message,
	Command_Radio_Message,
	Standard_Radio_Message,
	Report_Radio_Message,
	Team_Message,
	Chat_Message,
	Use_Microphone,
	Temporarily_Disable_Incoming_Chat,

	// Chat_Wheel_Keys
	Chat_Wheel_1,
	Chat_Wheel_2,
	Chat_Wheel_3,

	// Chat Wheel phrases
	Chat_Wheel_1_Text_1,
	Chat_Wheel_1_Text_2,
	Chat_Wheel_1_Text_3,
	Chat_Wheel_1_Text_4,
	Chat_Wheel_1_Text_5,
	Chat_Wheel_1_Text_6,
	Chat_Wheel_1_Text_7,
	Chat_Wheel_1_Text_8,

	Chat_Wheel_2_Text_1,
	Chat_Wheel_2_Text_2,
	Chat_Wheel_2_Text_3,
	Chat_Wheel_2_Text_4,
	Chat_Wheel_2_Text_5,
	Chat_Wheel_2_Text_6,
	Chat_Wheel_2_Text_7,
	Chat_Wheel_2_Text_8,

	Chat_Wheel_3_Text_1,
	Chat_Wheel_3_Text_2,
	Chat_Wheel_3_Text_3,
	Chat_Wheel_3_Text_4,
	Chat_Wheel_3_Text_5,
	Chat_Wheel_3_Text_6,
	Chat_Wheel_3_Text_7,
	Chat_Wheel_3_Text_8,
};

#endif