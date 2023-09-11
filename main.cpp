#include <cstdio>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include "file_work.h"
#include "strings_sort.h"
#include "str_functions.h"
#include "comparator.h"

static char** parse_buffer(char* buffer, int nlines, int file_size);

int main()
{
    FILE* file = fopen("hamlet.txt", "rb");
    assert(file);

    int file_size = get_file_size(file);
    char* buffer = get_file_content(file, file_size);
    int nlines = calc_nlines(buffer, file_size);
    char** text = parse_buffer(buffer, nlines + 1, file_size);

    FILE* out = fopen("hamlet_sorted.txt", "w");

    bubble_sort(text, nlines, sizeof(char*), &char_cmp);
    fprintf(out, "\n\nDefault text sort\n\n");
    for (int i = 0; i <= nlines; i++)
    {
        fputs(text[i], out);
    }

    bubble_sort(text, nlines, sizeof(char*), &reverse_char_cmp);
    fprintf(out, "\n\nText sort by string endings\n\n");
    for (int i = 0; i <= nlines; i++)
    {
        fputs(text[i], out);
    }

    fprintf(out, "\n\nAnd you can read true Hamlet text!!!\n\n\n");
    size_t shift = 0;
    for (int i = 0; i <= nlines; i++)
    {
        fprintf(out, "%s", buffer + shift);
        while (buffer[shift] != '\0')
        {
            shift++;
        }     
        shift++;   
    }

    free(buffer);
    free(text);
    fclose(file);
    fclose(out);

    return 0;
}

static char** parse_buffer(char* buffer, int nlines, int file_size)
{
    assert(buffer);

    char** text = (char**) calloc(nlines + 1, sizeof(char*));
    assert(text);
    text[0] = buffer;

    for (int i = 0, j = 0; i < file_size; i++)
    {
        if (buffer[i] == '\n')
        {
            text[++j] = &buffer[i + 1];
            buffer[i] = '\0';
        }

        if (buffer[i] == '\r')
        {
           buffer[i] = '\n';
        }
    }

    return text;
}


