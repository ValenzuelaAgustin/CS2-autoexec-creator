#include "nstd_string.h"
#include <stdio.h>
#include <stdlib.h>

long strlength(const char* string)
{
	int i;
	for (i = 0; string[i]; i++);
	return i;
}

char* copy_file_to_string(const char* file_name)
{
	FILE* file = fopen(file_name, "rb");
	char* string = NULL;
	long size;

	if (file == NULL)
		return NULL;

	fseek(file, 0, SEEK_END);
	size = ftell(file);
	if (size <= 0)
		return NULL;

	string = (char*) calloc(size + 1, 1);
	if (string == NULL)
		return NULL;

	fseek(file, 0, SEEK_SET);
	(void)fread(string, 1, size, file);
	fclose(file);
	string[size] = '\0';

	return string;
}

long search_for_target_string(const char* target_string, const char* string)
{
	if (target_string == NULL || string == NULL)
		return INVALID_INPUT;

	size_t i, j;

	for (i = 0, j = 0; string[i] && target_string[j];)
	{
		for (; string[i] && string[i] != target_string[0]; i++);
		for (j = 0; string[i] && target_string[j] && string[i] == target_string[j]; i++, j++);
	}

	return (target_string[j]) ? STRING_NOT_FOUND : i - j;
}

long search_for_quoted_target_string(const char* target_string, const char* string)
{
	if (target_string == NULL || string == NULL)
		return INVALID_INPUT;

	size_t i, j;

	for (i = 0, j = 0; string[i] && (target_string[j] || string[i] != '\"');)
	{
		for (; string[i] && string[i] != '\"'; i++);
		for (j = 0, i++; string[i] && target_string[j] && string[i] == target_string[j]; i++, j++);
	}

	return (target_string[j]) ? STRING_NOT_FOUND : i - j;
}

long search_string_in_file(const char* target_string, const char* file_name)
{
	if (target_string == NULL || file_name == NULL || *target_string == '\0')
		return INVALID_INPUT;

	FILE* file = fopen(file_name, "rb");

	if (file == NULL)
		return COULD_NOT_OPEN_FILE;

	const size_t buffer_length = 100;
	size_t current_position_in_file;
	size_t elements_readed;
	size_t i, j;
	int has_been_equal, is_equal;
	char buffer[buffer_length];

	for (i = 0, current_position_in_file = 0, has_been_equal = 0, is_equal = 0; !is_equal && (elements_readed = fread(buffer, 1, buffer_length, file));)
	{
		for (j = 0; !is_equal && j < elements_readed;)
		{
			for (; !has_been_equal && j < elements_readed && buffer[j] != target_string[0]; j++);

			if (j == elements_readed)
			{
				continue;
			}

			for (; target_string[i] && j < elements_readed && buffer[j] == target_string[i]; j++, i++);

			if (target_string[i] == '\0')
			{
				is_equal = 1;
			}
			else if (j == elements_readed)
			{
				has_been_equal = 1;
			}
			else
			{
				i = 0;
				has_been_equal = 0;
			}
		}
		current_position_in_file += j;
	}

	fclose(file);
	current_position_in_file -= strlength(target_string);

	return (is_equal) ? current_position_in_file : STRING_NOT_FOUND;
}