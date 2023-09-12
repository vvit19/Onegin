#ifndef STR_FUNCTIONS_H
#define STR_FUNCTIONS_H

#include <cstdlib>

int mystrcmp(const char* s1, const char* s2);
int reverse_strcmp(const char* s1, const char* s2);
char** parse_buffer(char* buffer, int nlines, int file_size);

#endif