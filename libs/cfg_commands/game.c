#include "game.h"
#include <stdlib.h>

const char* const Game_Settings[] =
{
	// Game
	"con_enable",
	"mm_dedicated_search_maxping",
	"rate",
	"cl_net_buffer_ticks",
	"install_dlc_workshoptools_cvar",

	// Hud
	"hud_scaling",
	"cl_hud_color",
	"cl_teamcounter_playercount_instead_of_avatars",
	"ui_steam_overlay_notification_position",
	"ui_steam_overlay_notification_position_horz",
	"ui_steam_overlay_notification_position_vert",
	"cl_weapon_selection_rarity_color",

	// Team
	"cl_teamid_overhead_mode",
	"cl_teammate_colors_show",
	"cl_teamid_overhead_colors_show",
	"lobby_default_privacy_bits2",
	"ui_setting_advertiseforhire_auto",

	// Communication
	"cl_player_ping_mute",
	"cl_mute_enemy_team",
	"cl_mute_all_but_friends_and_party",
	"",							// Text_Filtering ( It is not configured inside CS2 )
	"cl_allow_animated_avatars",
	"cl_hide_avatar_images",
	"cl_sanitize_player_names",

	// Spectator / Scoreboard
	"spec_usenumberkeys_nobinds",
	"cl_scoreboard_mouse_enable_binding",
	"eom_local_player_defeat_anim_enabled",
	"cl_scoreboard_survivors_always_on",
	"cl_obs_interp_enable",
	"cl_obs_interp_pos_rate",

	// Item
	"cl_sniper_delay_unscope",
	"cl_sniper_auto_rezoom",
	"cl_silencer_mode",
	"viewmodel_presetpos",
	"cl_prefer_lefthanded",
	"r_drawtracers_firstperson",
	"cl_showloadout",
	"cl_use_opens_buy_menu",
	"cl_buywheel_nonumberpurchasing",
	"cl_buywheel_donate_key",
	"",							// Last_Weapon_on_Radial_Weapon_Tap

	// Radar / Tablet
	"cl_radar_always_centered",
	"cl_radar_rotate",
	"cl_hud_radar_map_additive",
	"cl_hud_radar_background_alpha",
	"cl_hud_radar_scale",
	"cl_radar_scale",
	"cl_radar_scale_alternate",
	"cl_radar_square_with_scoreboard",
	"cl_radar_scale_dynamic",

	// Crosshair
	"cl_crosshairstyle",
	"cl_crosshair_friendly_warning",
	"cl_crosshair_recoil",
	"cl_crosshairdot",
	"cl_crosshairsize",
	"cl_crosshairthickness",
	"cl_crosshairgap",
	"cl_crosshair_drawoutline",
	"cl_crosshair_outlinethickness",
	"cl_crosshaircolor_r",
	"cl_crosshaircolor_g",
	"cl_crosshaircolor_b",
	"cl_crosshairusealpha",
	"cl_crosshairalpha",
	"cl_crosshair_t",
	"cl_crosshairgap_useweaponvalue",
	"cl_ironsight_usecrosshaircolor",
	"cl_show_observer_crosshair",
	"cl_observed_bot_crosshair",

	// Grenade Line-up Reticle
	"cl_grenadecrosshair_keepusercrosshair",
	"cl_grenadecrosshair_flash",
	"cl_grenadecrosshairdelay_flash",
	"cl_grenadecrosshair_explosive",
	"cl_grenadecrosshairdelay_explosive",
	"cl_grenadecrosshair_fire",
	"cl_grenadecrosshairdelay_fire",
	"cl_grenadecrosshair_smoke",
	"cl_grenadecrosshairdelay_smoke",
	"cl_grenadecrosshair_decoy",
	"cl_grenadecrosshairdelay_decoy",

	// Damage Prediction
	"cl_predict_body_shot_fx",
	"cl_predict_head_shot_fx",
	"cl_predict_kill_ragdolls",

	// Telemetry
	"cl_hud_telemetry_frametime_show",
	"cl_hud_telemetry_frametime_poor",
	"cl_hud_telemetry_ping_show",
	"cl_hud_telemetry_net_misdelivery_show",
	"cl_hud_telemetry_net_misdelivery_poor",
	"cl_hud_telemetry_net_quality_graph_show",
	"cl_hud_telemetry_net_detailed",
	NULL
};