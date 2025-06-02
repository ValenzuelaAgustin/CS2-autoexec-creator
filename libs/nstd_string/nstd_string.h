#ifndef NSTD_STRING_H
#define NSTD_STRING_H

enum
{
	INVALID_INPUT = (1 << (sizeof(long) * 8 - 1)),
	COULD_NOT_OPEN_FILE,
	STRING_NOT_FOUND
};

#define TO_LOWER(c) ( ((c) >= 'A' && (c) <= 'Z') ? (c) | (1<<5) : (c) )
#define TO_UPPER(c) ( ((c) >= 'a' && (c) <= 'z') ? (c) & ~(1<<5) : (c) )

long strlength(const char* string);

char* copy_file_to_string(const char* file_name);

long search_for_target_string(const char* target_string, const char* string);

long search_string_in_file(const char* target_string, const char* file_name);

#endif