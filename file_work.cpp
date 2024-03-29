#include <cstdlib>
#include <cassert>
#include <cstdio>
#include <cstring>

#include "file_work.h"
#include "comparator.h"
#include "str_functions.h"
#include "strings_sort.h"

static int get_file_size(FILE* file);
static char* get_file_content(FILE* file, int* file_size);
static int calc_nlines(char* buffer);
static void fprint_sorted(FILE* file, char** text, int nlines);
static void fprint_default(FILE* file, char* buffer, int nlines);

File_to_Buffer* get_buffer_from_file(const char* filename)
{
    FILE* file = fopen(filename, "rb");
    assert(file);

    File_to_Buffer* file_and_buffer = (File_to_Buffer*) calloc(1, sizeof(File_to_Buffer));
    assert(file_and_buffer);

    file_and_buffer->file_size = get_file_size(file);

    file_and_buffer->buffer = get_file_content(file, 
                                               &file_and_buffer->file_size);

    file_and_buffer->nlines = calc_nlines(file_and_buffer->buffer);

    file_and_buffer->text = parse_buffer(file_and_buffer->buffer,
                                         file_and_buffer->nlines, 
                                         file_and_buffer->file_size);

    fclose(file);
    return file_and_buffer;
}


static int get_file_size(FILE* file)
{
    assert(file);
    
    fseek(file, 0, SEEK_END);
    int position = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    return position;
}

static char* get_file_content(FILE* file, int* file_size)
{
    assert(file);
    
    char* buffer = (char*) calloc(*file_size + 1, sizeof(char));
    assert(buffer);

    buffer[*file_size] = '\n'; 
    *file_size = fread(buffer, sizeof(char), *file_size, file);

    return buffer;
}

static int calc_nlines(char* buffer)
{
        
    assert(buffer);

    int nlines = 0;
    char* temp = buffer;

    while ((temp = strchr(temp, '\n')) != nullptr)
    {
        nlines++;
        temp++;
    }

    return nlines;
}

void print_to_file(File_to_Buffer* file_and_buffer, const char* filename)
{
    assert(file_and_buffer);

    FILE* file = fopen(filename, "w");
    assert(file);

    qsort(file_and_buffer->text, file_and_buffer-> nlines - 1, sizeof(char*), &char_cmp);
//  quick_sort(file_and_buffer->text, 0, file_and_buffer->nlines - 1, sizeof(char*), &char_cmp);
    fprintf(file, "------------------Alphabet sorted text:-------------------\n\n");
    fprint_sorted(file, file_and_buffer->text, file_and_buffer->nlines);

    quick_sort(file_and_buffer->text, 0, file_and_buffer->nlines - 1, sizeof(char*), &reverse_char_cmp);
    fprintf(file, "\n\n    ------------------Text sorted by endings-------------------    \n\n\n");      
    fprint_sorted(file, file_and_buffer->text, file_and_buffer->nlines);

    fprintf(file, "\n\n    ------------------And you can read true Hamlet text------------------    \n\n\n");
    fprint_default(file, file_and_buffer->buffer, file_and_buffer->nlines);
    
    fclose(file);
}

static void fprint_sorted(FILE* file, char** text, int nlines)
{
    assert(file);
    assert(text);

    for (int i = 0; i <= nlines; i++)
    {
        fputs(text[i], file);
    }
}

static void fprint_default(FILE* file, char* buffer, int nlines)
{
    assert(file);
    assert(buffer);

    int shift = 0;

    for (int i = 0; i <= nlines; i++)
    {
        fprintf(file, "%s", buffer + shift);

        while (buffer[shift++] != '\0')
            {   }     
    }
}
