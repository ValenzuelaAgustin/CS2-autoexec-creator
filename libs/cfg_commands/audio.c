#include "audio.h"

const char* Audio_Settings[] =
{
	// Audio
	"volume",
	"snd_menumap_volume",
	"sound_device_override",
	"snd_headphone_eq",
	"snd_spatialize_lerp",
	"snd_steamaudio_enable_perspective_correction",
	"snd_mute_losefocus",

	// Voice
	"snd_voipvolume",
	"voice_modenable",
	"voice_device_override",
	"voice_loopback_no_networking",
	"voice_always_sample_mic",
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
	"",					// Competitive_EQ ( TODO: Check ) snd_eq_competitive
	"",					// Casual_EQ ( TODO: Check ) snd_eq_casual
	"",					// Deathmatch_EQ ( TODO: Check ) snd_eq_deathmatch
	""					// Arms_Race_EQ ( TODO: Check ) snd_eq_arms_race
};

const char* Audio_Settings_Names[] =
{
	// Audio
	"Master Volume",
	"Main Menu Ambience Volume",
	"Audio Device",
	"EQ Profile",
	"L/R Isolation",
	"Perspective Correction",
	"Play Audio When Game In Background",

	// Voice
	"Other Player Voice Volume",
	"Voice/Microphone Mode",
	"Voice Input Audio Device",
	"Hear My Own Voice",
	"Streamlined Push To Talk",
	"Microphone Trigger Threshold",

	// Music
	"Main Menu Volume",
	"Round Start Volume",
	"Round Action Volume",
	"Round End Volume",
	"MVP Volume",
	"Bomb/Hostage Volume",
	"Ten Second Warning Volume",
	"Death Camera Volume",
	"Mute MVP Music when players on both teams are alive",

	// Game Mode EQ
	"Competitive EQ",
	"Casual EQ",
	"Deathmatch EQ",
	"Arms Race EQ"
};

const char* Audio_Settings_Sub_Menu_Titles[] =
{
	"Audio",
	"Voice",
	"Music",
	"Game Mode EQ"
};

int Audio_Sub_Menu_Last_Config[] =
{
	Play_Audio_When_Game_In_Background,
	Microphone_Trigger_Threshold,
	Mute_MVP_Music_when_players_on_both_teams_are_alive,
	Arms_Race_EQ,
	-1
};