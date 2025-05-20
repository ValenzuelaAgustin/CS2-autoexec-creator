#ifndef AUDIO_H
#define AUDIO_H

//	https://steamcommunity.com/sharedfiles/filedetails/?id=3046217806

const char* Audio_Settings[] =
{
	// Audio
	"volume",
	"snd_menumap_volume",
	"voice_device_override",
	"snd_headphone_eq",
	"snd_spatialize_lerp",
	"snd_steamaudio_enable_perspective_correction",
	"snd_mute_losefocus",

	// Voice
	"snd_voipvolume",
	"voice_modenable",
	"voice_device_override",
	"voice_loopback_no_networking",				// Hear_My_Own_Voice ( TODO: Check )
	"voice_always_sample_mic",				// Streamlined_Push_To_Talk ( TODO: Check )
	"voice_threshold",

	// Music
	"snd_menumusic_volume",
	"snd_roundstart_volume",
	"snd_roundaction_volume",
	"snd_roundend_volume",
	"snd_mvp_volume",
	"snd_mapobjective_volume",
	"snd_tensecondwarning_volume",
	"snd_deathcamera_volume",
	"snd_mute_mvp_music_live_players",

	// Game Mode EQ
	"snd_eq_competitive",					// Competitive_EQ ( TODO: Check )
	"snd_eq_casual",					// Casual_EQ ( TODO: Check )
	"snd_eq_deathmatch",					// Deathmatch_EQ ( TODO: Check )
	"snd_eq_arms_race"					// Arms_Race_EQ ( TODO: Check )
};

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