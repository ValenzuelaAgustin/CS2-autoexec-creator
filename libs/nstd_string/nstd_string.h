#ifndef NSTD_STRING_H
#define NSTD_STRING_H

enum
{
	INVALID_INPUT = (1 << (sizeof(long) * 8 - 1)),
	COULD_NOT_OPEN_FILE,
	STRING_NOT_FOUND
};

long strlength(const char* string);

/*
 * @param target_string String that will be searched in the file provided.
 * @param file_name File name and location.
 * @return position of the string in the file.
 */
long search_string_in_file(const char* target_string, const char* file_name);

#endif