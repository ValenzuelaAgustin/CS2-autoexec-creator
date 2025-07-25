#ifndef NSTD_STRING_H
#define NSTD_STRING_H

enum
{
	INVALID_INPUT = (1 << (sizeof(long) * 8 - 1)),
	COULD_NOT_OPEN_FILE,
	STRING_NOT_FOUND
};

#define IS_A_LETTER(c) ( ((c) >= 'a' && (c) <= 'z') || ((c) >= 'A' && (c) <= 'Z') )
#define TO_LOWER(c) ( ((c) >= 'A' && (c) <= 'Z') ? (c) | (1<<5) : (c) )
#define TO_UPPER(c) ( ((c) >= 'a' && (c) <= 'z') ? (c) & ~(1<<5) : (c) )

#define IS_A_DIGIT(c) ( (c) <= '9' && (c) >= '0' )
#define IS_A_SIGN(c) ( (c) == '-' || (c) == '+' )
#define IS_A_POINT(c) ( (c) == '.' )
#define IS_AN_INTEGER_NUMBER(c) ( IS_A_DIGIT(c) || IS_A_SIGN(c) )
#define IS_A_REAL_NUMBER(c) ( IS_A_DIGIT(c) || IS_A_POINT(c) || IS_A_SIGN(c) )

long strlength(const char* string);

char* copy_file_to_string(const char* file_name);

long search_for_target_string(const char* target_string, const char* string);

long search_for_quoted_target_string(const char* target_string, const char* string);

#endif