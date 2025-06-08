#ifndef AUDIO_H
#define AUDIO_H

extern const char* Audio_Settings[];
extern const char* Audio_Settings_Names[];
extern const char* Audio_Settings_Sub_Menu_Titles[];
extern int Audio_Sub_Menu_Last_Config[];

enum
{
	// Audio
	Master_Volume,
	Main_Menu_Ambience_Volume,
	Audio_Device,
	EQ_Profile,
	LR_Isolation,
	Perspective_Correction,
	Play_Audio_When_Game_In_Background,

	// Voice
	Other_Player_Voice_Volume,
	Voice_Microphone_Mode,
	Voice_Input_Audio_Device,
	Hear_My_Own_Voice,
	Streamlined_Push_To_Talk,
	Microphone_Trigger_Threshold,

	// Music
	Main_Menu_Volume,
	Round_Start_Volume,
	Round_Action_Volume,
	Round_End_Volume,
	MVP_volume,
	Bomb_Hostage_Volume,
	Ten_Second_Warning_Volume,
	Death_Camera_Volume,
	Mute_MVP_Music_when_players_on_both_teams_are_alive,

	// Game Mode EQ
	Competitive_EQ,
	Casual_EQ,
	Deathmatch_EQ,
	Arms_Race_EQ
};

#endif