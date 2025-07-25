CC := gcc
CFLAGS := -Wall -O3
OBJDIR := obj

MAIN_OBJ := ${OBJDIR}\main.o
AUTOEXEC_OBJ := ${OBJDIR}\autoexec_creator.o
NSTD_STRING_OBJ := ${OBJDIR}\nstd_string.o
AUDIO_OBJ := ${OBJDIR}\audio.o
GAME_OBJ := ${OBJDIR}\game.o
KEYBOARD_AND_MOUSE_OBJ := ${OBJDIR}\keyboard_and_mouse.o
OTHER_SETTINGS_OBJ := ${OBJDIR}\other_settings.o
CFG_COMMANDS_OBJ := ${OBJDIR}\cfg_commands.o
MENU_OBJ := ${OBJDIR}\menu.o

autoexec-creator.exe: ${MAIN_OBJ} ${AUTOEXEC_OBJ} ${NSTD_STRING_OBJ} ${AUDIO_OBJ} ${GAME_OBJ} ${KEYBOARD_AND_MOUSE_OBJ} ${OTHER_SETTINGS_OBJ} ${CFG_COMMANDS_OBJ} ${MENU_OBJ}
	${CC} ${CFLAGS} -o autoexec-creator.exe ${MAIN_OBJ} ${AUTOEXEC_OBJ} ${NSTD_STRING_OBJ} ${AUDIO_OBJ} ${GAME_OBJ} ${KEYBOARD_AND_MOUSE_OBJ} ${OTHER_SETTINGS_OBJ} ${CFG_COMMANDS_OBJ} ${MENU_OBJ}

${MAIN_OBJ}: main.c libs\menu\menu.h
	${CC} ${CFLAGS} -c main.c -o ${MAIN_OBJ}

${AUTOEXEC_OBJ}: libs\autoexec_creator\autoexec_creator.c libs\autoexec_creator\autoexec_creator.h libs\nstd_string\nstd_string.h libs\cfg_commands\cfg_commands.h libs\cfg_commands\audio.h libs\cfg_commands\game.h libs\cfg_commands\keyboard_and_mouse.h libs\cfg_commands\other_settings.h
	${CC} ${CFLAGS} -c libs\autoexec_creator\autoexec_creator.c -o ${AUTOEXEC_OBJ}

${NSTD_STRING_OBJ}: libs\nstd_string\nstd_string.c libs\nstd_string\nstd_string.h
	${CC} ${CFLAGS} -c libs\nstd_string\nstd_string.c -o ${NSTD_STRING_OBJ}

${AUDIO_OBJ}: libs\cfg_commands\audio.c libs\cfg_commands\audio.h
	${CC} ${CFLAGS} -c libs\cfg_commands\audio.c -o ${AUDIO_OBJ}

${GAME_OBJ}: libs\cfg_commands\game.c libs\cfg_commands\game.h
	${CC} ${CFLAGS} -c libs\cfg_commands\game.c -o ${GAME_OBJ}

${KEYBOARD_AND_MOUSE_OBJ}: libs\cfg_commands\keyboard_and_mouse.c libs\cfg_commands\keyboard_and_mouse.h
	${CC} ${CFLAGS} -c libs\cfg_commands\keyboard_and_mouse.c -o ${KEYBOARD_AND_MOUSE_OBJ}

${OTHER_SETTINGS_OBJ}: libs\cfg_commands\other_settings.c libs\cfg_commands\other_settings.h
	${CC} ${CFLAGS} -c libs\cfg_commands\other_settings.c -o ${OTHER_SETTINGS_OBJ}

${CFG_COMMANDS_OBJ}: libs\cfg_commands\cfg_commands.c libs\cfg_commands\cfg_commands.h libs\cfg_commands\audio.h libs\cfg_commands\game.h libs\cfg_commands\keyboard_and_mouse.h libs\cfg_commands\other_settings.h
	${CC} ${CFLAGS} -c libs\cfg_commands\cfg_commands.c -o ${CFG_COMMANDS_OBJ}

${MENU_OBJ}: libs\menu\menu.c libs\menu\menu.h libs\nstd_string\nstd_string.h libs\autoexec_creator\autoexec_creator.h
	${CC} ${CFLAGS} -c libs\menu\menu.c -o ${MENU_OBJ}

clean:
	rm ${OBJDIR}\*.o