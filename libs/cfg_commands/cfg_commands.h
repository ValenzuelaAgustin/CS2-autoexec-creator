#ifndef CFG_COMMANDS_H
#define CFG_COMMANDS_H

#include "audio.h"
#include "game.h"
#include "keyboard_and_mouse.h"
#include "other_settings.h"

typedef struct
{
	const char** sub_menu_title;
	int* sub_menu_last_config;
	const char** config_name;
	const char** config;
} cfg_menu_t;

extern int menu_ammount;
extern cfg_menu_t cfg_menu[];

#endif