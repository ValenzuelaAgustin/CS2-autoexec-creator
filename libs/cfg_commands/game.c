#include "game.h"

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
	"cl_hud_telemetry_net_detailed"
};

const char* const Game_Settings_Names[] =
{
	// Game
	"Launched With Developer Console",
	"Max Acceptable Matchmaking Ping",
	"Max Acceptable Game Traffic Bandwidth",
	"Buffering to smooth over packet loss / jitter",
	"Install Counter-Strike Workshop Tools",

	// Hud
	"HUD Scale",
	"HUD Color",
	"Large Player Count",
	"Community Notification Location",
	"Community Notification Horizontal Offset",
	"Community Notification Vertical Offset",
	"Glow Weapon with Rarity Color",

	// Team
	"Show Team ID Through Walls",
	"Show Player Colors in Competitive",
	"Use Player Colors on Team ID",
	"Friends Lobby Default Permissions",
	"Looking to Play when Counter-Strike Starts",

	// Communication
	"Player Pings",
	"Mute Enemy Team",
	"Mute All But Friends",
	"Text Filtering",
	"Allow Animated Avatars",
	"Hide Avatar Images and Customized Items",
	"Clean Player Names",

	// Spectator / Scoreboard
	"Spectator/Map Vote Number Selection Method",
	"Scoreboard Mouse Enable / End of Match Scoreboard Toggle",
	"End of Match Local Player Defeat Animation",
	"Survivors Always On",
	"Smooth Spectator Camera",
	"Smooth Spectator Camera Speed",

	// Item
	"Delay Sniper Rifle Un-Scope after Shot",
	"Auto Re-Zoom Sniper Rifle after Shot",
	"Detach Silencer on M4A1-S and USPS",
	"Viewmodel Position",
	"Preferred Viewmodel Left/Right Handedness",
	"First Person Tracers",
	"Always Show Inventory",
	"Open Buy Menu With Use Key",
	"Buy Menu Number Keys",
	"Buy Menu Donation Key",
	"Last Weapon on Radial Weapon Tap",

	// Radar / Tablet
	"Radar Centers The Player",
	"Radar IS Rotating",
	"Radar Hud Map Blends With Background",
	"Radar Hud Background Opacity",
	"Radar Hud Size",
	"Radar Map Zoom",
	"Radar Map Alternate Zoom",
	"Toggle Shape With Scoreboard",
	"Radar Is Zooming Dynamically",

	// Crosshair
	"Crosshair Style",
	"Friendly Fire Reticle Warning",
	"Follow Recoil",
	"Center Dot",
	"Length",
	"Thickness",
	"Gap",
	"Draw Outline",
	"Outline Thickness",
	"Red",
	"Green",
	"Blue",
	"Use Alpha",
	"Alpha",
	"T style",
	"Deployed Weapon Gap",
	"Use crosshair color for scope dot",
	"Show Player Crosshairs",
	"Show my crosshair when spectating bots",

	// Grenade Line-up Reticle
	"Keep Regular Crosshair",
	"Flashbangs Crosshair",
	"Flashbangs Crosshair Delay",
	"HE grenades Crosshair",
	"HE grenades Crosshair Delay",
	"Molotov cocktails / Incendiary grenades Crosshair",
	"Molotov cocktails / Incendiary grenades Crosshair Delay",
	"Smoke grenades Crosshair",
	"Smoke grenades Crosshair Delay",
	"Decoy grenades Crosshair",
	"Decoy grenades Crosshair Delay",

	// Damage Prediction
	"Predict Body Shot Effects",
	"Predict Head Shot Effects",
	"Predict Kill Ragdolls",

	// Telemetry
	"Show frame time and FPS",
	"Frame time warning threshold",
	"Show ping",
	"Show network problems (ticks missed due to loss / jitter)",
	"Network tick miss rate warning threshold",
	"Show network jitter / misdelivery graph",
	"Use the detailed network quality display"
};

const char* const Game_Settings_Sub_Menu_Titles[] =
{
	"Game",
	"Hud",
	"Team",
	"Communication",
	"Spectator / Scoreboard",
	"Item",
	"Radar / Tablet",
	"Crosshair",
	"Grenade Line-up Reticle",
	"Damage Prediction",
	"Telemetry"
};

const int Game_Sub_Menu_Last_Config[] =
{
	Install_Counter_Strike_Workshop_Tools,
	Glow_Weapon_with_Rarity_Color,
	Looking_to_Play_when_Counter_Strike_Starts,
	Clean_Player_Names,
	Smooth_Spectator_Camera_Speed,
	Last_Weapon_on_Radial_Weapon_Tap,
	Radar_Is_Zooming_Dynamically,
	Show_my_crosshair_when_spectating_bots,
	Decoy_grenades_Crosshair_Delay,
	Predict_Kill_Ragdolls,
	Use_the_detailed_network_quality_display,
	-1
};