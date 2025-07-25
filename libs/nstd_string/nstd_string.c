#include "nstd_string.h"
#include <stdio.h>
#include <stdlib.h>

long strlength(const char* string)
{
	if (string == NULL)
		return 0;
	long i;
	for (i = 0; string[i]; i++);
	return i;
}

char* copy_file_to_string(const char* file_name)
{
	if (file_name == NULL)
		return NULL;

	FILE* file = fopen(file_name, "rb");
	char* string;
	long size;

	if (file == NULL)
		return NULL;

	(void)fseek(file, 0, SEEK_END);
	size = ftell(file);
	if (size <= 0)
	{
		(void)fclose(file);
		return NULL;
	}

	string = (char*) calloc(size + 1, 1);
	if (string == NULL)
	{
		(void)fclose(file);
		return NULL;
	}

	(void)fseek(file, 0, SEEK_SET);
	(void)fread(string, 1, size, file);
	(void)fclose(file);
	string[size] = '\0';

	return string;
}

long search_for_target_string(const char* target_string, const char* string)
{
	if (target_string == NULL || string == NULL)
		return INVALID_INPUT;

	long i, j, start;

	for (i = 0, j = 0, start = 0; string[i] && target_string[j]; i = start + 1)
	{
		for (; string[i] && string[i] != target_string[0]; i++);
		if (string[i] == '\0')
			return STRING_NOT_FOUND;
		start = i;
		for (j = 0; string[i] && target_string[j] && string[i] == target_string[j]; i++, j++);
	}

	return (target_string[j]) ? STRING_NOT_FOUND : start;
}

long search_for_quoted_target_string(const char* target_string, const char* string)
{
	if (target_string == NULL || string == NULL)
		return INVALID_INPUT;

	long i, j;

	for (i = 0, j = 0; string[i] && (target_string[j] || string[i] != '\"');)
	{
		for (; string[i] && string[i] != '\"'; i++);
		if (string[i] == '\0')
			return STRING_NOT_FOUND;
		for (j = 0, i++; string[i] && target_string[j] && string[i] == target_string[j]; i++, j++);
	}

	return (target_string[j] || !string[i]) ? STRING_NOT_FOUND : i - j;
}