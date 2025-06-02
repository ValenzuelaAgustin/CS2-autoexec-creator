#include "audio.h"
#include <stdlib.h>

const char* const Audio_Settings[] =
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
	"",					// Arms_Race_EQ ( TODO: Check ) snd_eq_arms_race
	NULL
};