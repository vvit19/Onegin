#ifndef FILE_WORK_H
#define FILE_WORK_H

#include <cstdio>

int get_file_size(FILE* file);
char* get_file_content(FILE* file, int file_size);
int calc_nlines(char* buffer, int file_size);

#endif