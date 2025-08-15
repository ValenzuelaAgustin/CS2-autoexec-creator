#ifndef CFG_COMMANDS_H
#define CFG_COMMANDS_H

typedef struct
{
	const char* const * sub_menu_title;
	const int* sub_menu_last_config;
	const char* const * config_name;
	const char* const * config;
} cfg_menu_t;

extern const int menu_ammount;
extern const cfg_menu_t cfg_menu[];

enum
{
	AUDIO,
	GAME,
	KEYBOARD_AND_MOUSE,
	OTHER_SETTINGS
};

#endif