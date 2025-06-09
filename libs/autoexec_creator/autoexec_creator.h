#ifndef AUTOEXEC_CREATOR_H
#define AUTOEXEC_CREATOR_H
#include <stdio.h>

enum
{
	PARAMETER_NOT_FOUND = (1 << (sizeof(long) * 8 - 1))
};

void append_configs_to_file(char** config_file_string, FILE* autoexec);

void write_autoexec(char** config_file_string, FILE* autoexec);

#endif