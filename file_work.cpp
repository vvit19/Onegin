#include <cstdlib>
#include <cassert>
#include <cstdio>
#include "file_work.h"

int get_file_size(FILE* file)
{
    assert(file);
    
    fseek(file, 0, SEEK_END);
    int position = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    return position;
}

char* get_file_content(FILE* file, int file_size)
{
    assert(file);
    
    char* buffer = (char*) calloc(file_size + 1, sizeof(char));
    buffer[file_size] = '\n'; //help in cycle finds '\n'
    fread(buffer, sizeof(char), file_size, file);

    return buffer;
}

int calc_nlines(char* buffer, int buffer_size)
{
    assert(buffer);

    int nlines = 1;
    for (int i = 0; i < buffer_size; i++)
    {
        if (buffer[i] == '\n')
        {
            nlines++;
        }
    }

    return nlines;
}
