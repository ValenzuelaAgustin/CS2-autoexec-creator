#ifndef GAME_H
#define GAME_H

const char* Game_Settings[] =
{
	// Game
	"con_enable",	// Launched_With_Developer_Console ( TODO: Check )
	"mm_dedicated_search_maxping",
	"rate",
	"cl_net_buffer_ticks",
	"install_dlc_workshoptools_cvar", // Install_Counter_Strike_Workshop_Tools ( TODO: Check )

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
	"", // Text_Filtering ( It is not configured inside CS2 )
	"cl_allow_animated_avatars",
	"cl_hide_avatar_images",
	"cl_sanitize_player_names",

	// Spectator / Scoreboard
	"spec_usenumberkeys_nobinds",
	"cl_scoreboard_mouse_enable_binding",
	"eom_local_player_defeat_anim_enabled",
	"cl_scoreboard_survivors_always_on",
	"cl_obs_interp_enable",
	Smooth_Spectator_Camera_Speed,

	// Item
	Delay_Sniper_Rifle_UnScope_after_Shot,
	Auto_ReZoom_Sniper_Rifle_after_Shot,
	Detach_Silencer_on_M4A1S_and_USPS,
	Viewmodel_Position,
	Preferred_Viewmodel_Left_Right_Handedness,
	First_Person_Tracers,
	Always_Show_Inventory,
	Open_Buy_Menu_With_Use_Key,
	Buy_Menu_Number_Keys,
	Buy_Menu_Donation_Key,
	Last_Weapon_on_Radial_Weapon_Tap,

	// Radar / Tablet
	Radar_Centers_The_Player,
	Radar_Is_Rotating,
	Radar_Hud_Map_Blends_With_Background,
	Radar_Hud_Background_Opacity,
	Radar_Hud_Size,
	Radar_Map_Zoom,
	Radar_Map_Alternate_Zoom,
	Toggle_Shape_With_Scoreboard,
	Radar_Is_Zooming_Dynamically,

	// Crosshair
	Crosshair_Style,
	Friendly_Fire_Reticle_Warning,
	Follow_Recoil,
	Center_Dot,
	Length,
	Thickness,
	Gap,
	Outline,
	Red,
	Green,
	Blue,
	Alpha,
	T_style,
	Deployed_Weapon_Gap,
	Use_crosshair_color_for_scope_dot,
	Show_Player_Crosshairs,
	Show_my_crosshair_when_spectating_bots,

	// Grenade Line-up Reticle
	Keep_Regular_Crosshair,
	Flashbangs,
	HE_grenades,
	Molotov_cocktails_Incendiary_grenades,
	Smoke_grenades,
	Decoy_grenades,

	// Damage Prediction
	Predict_Body_Shot_Effects,
	Predict_Head_Shot_Effects,
	Predict_Kill_Ragdolls,

	// Telemetry
	Show_frame_time_and_FPS,
	Frame_time_warning_threshold,
	Show_ping,
	Show_network_problems,
	Network_tick_miss_rate_warning_threshold,
	Show_network_jitter_misdelivery_graph,
	Use_the_detailed_network_quality_display
};

enum
{
	// Game
	Launched_With_Developer_Console,
	Max_Acceptable_Matchmaking_Ping,
	Max_Acceptable_Game_Traffic_Bandwidth,
	Buffering_to_smooth_over_packet_loss_jitter,
	Install_Counter_Strike_Workshop_Tools,

	// Hud
	HUD_Scale,
	HUD_Color,
	Large_Player_Count,
	Community_Notification_Location,
	Community_Notification_Horizontal_Offset,
	Community_Notification_Vertical_Offset,
	Glow_Weapon_with_Rarity_Color,

	// Team
	Show_Team_ID_Through_Walls,
	Show_Player_Colors_in_Competitive,
	Use_Player_Colors_on_Team_ID,
	Friends_Lobby_Default_Permissions,
	Looking_to_Play_when_Counter_Strike_Starts,

	// Communication
	Player_Pings,
	Mute_Enemy_Team,
	Mute_All_But_Friends,
	Text_Filtering,
	Allow_Animated_Avatars,
	Hide_Avatar_Images_and_Customized_Items,
	Clean_Player_Names,

	// Spectator / Scoreboard
	Spectator_Map_Vote_Number_Selection_Method,
	Scoreboard_Mouse_Enable_End_of_Match_Scoreboard_Toggle,
	End_of_Match_Local_Player_Defeat_Animation,
	Survivors_Always_On,
	Smooth_Spectator_Camera,
	Smooth_Spectator_Camera_Speed,

	// Item
	Delay_Sniper_Rifle_UnScope_after_Shot,
	Auto_ReZoom_Sniper_Rifle_after_Shot,
	Detach_Silencer_on_M4A1S_and_USPS,
	Viewmodel_Position,
	Preferred_Viewmodel_Left_Right_Handedness,
	First_Person_Tracers,
	Always_Show_Inventory,
	Open_Buy_Menu_With_Use_Key,
	Buy_Menu_Number_Keys,
	Buy_Menu_Donation_Key,
	Last_Weapon_on_Radial_Weapon_Tap,

	// Radar / Tablet
	Radar_Centers_The_Player,
	Radar_Is_Rotating,
	Radar_Hud_Map_Blends_With_Background,
	Radar_Hud_Background_Opacity,
	Radar_Hud_Size,
	Radar_Map_Zoom,
	Radar_Map_Alternate_Zoom,
	Toggle_Shape_With_Scoreboard,
	Radar_Is_Zooming_Dynamically,

	// Crosshair
	Crosshair_Style,
	Friendly_Fire_Reticle_Warning,
	Follow_Recoil,
	Center_Dot,
	Length,
	Thickness,
	Gap,
	Outline,
	Red,
	Green,
	Blue,
	Alpha,
	T_style,
	Deployed_Weapon_Gap,
	Use_crosshair_color_for_scope_dot,
	Show_Player_Crosshairs,
	Show_my_crosshair_when_spectating_bots,

	// Grenade Line-up Reticle
	Keep_Regular_Crosshair,
	Flashbangs,
	HE_grenades,
	Molotov_cocktails_Incendiary_grenades,
	Smoke_grenades,
	Decoy_grenades,

	// Damage Prediction
	Predict_Body_Shot_Effects,
	Predict_Head_Shot_Effects,
	Predict_Kill_Ragdolls,

	// Telemetry
	Show_frame_time_and_FPS,
	Frame_time_warning_threshold,
	Show_ping,
	Show_network_problems,
	Network_tick_miss_rate_warning_threshold,
	Show_network_jitter_misdelivery_graph,
	Use_the_detailed_network_quality_display
};

#endif