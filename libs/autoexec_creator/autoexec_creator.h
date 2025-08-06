#ifndef AUTOEXEC_CREATOR_H
#define AUTOEXEC_CREATOR_H
#include <stdio.h>

void write_autoexec(FILE* autoexec, char** config_file_string, const char* (*command_not_found_handler)(const char* command_name, int is_a_bind));

#endif