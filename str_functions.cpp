#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cctype>

#include "str_functions.h"

static const char* ignore_no_letters(const char* string);
static const char* reverse_ignore_no_letters(const char* string);

static const char* ignore_no_letters(const char* string)
{
    assert(string);

    for ( ; ; string++)
    {
        if (*string == '\0')
        {
            return string;
        }

        if (!isalpha(*string))
        {
            continue;
        }

        return string;
    }
}

static const char* reverse_ignore_no_letters(const char* string)
{
    assert(string);

    if (*string == '\n')
    {
        return string;
    }

    while (*string != '\0')
    {
        string++;
    }

    while (!isalpha(*string))
    {
        string--;
    }

    return string;
}

int mystrcmp(const char* str1, const char* str2)
{
    assert(str1);
    assert(str2);

    if (str1 == str2)
    {
        return 0;
    }

    str1 = ignore_no_letters(str1);
    str2 = ignore_no_letters(str2);

    int i = 0;
    for (; str1[i] == str2[i]; i++)
    {
        if (str1[i] == '\0')
        {
            return 0;
        }
    }

    return str1[i] - str2[i];
}

int reverse_strcmp(const char* str1, const char* str2)
{
    assert(str1);
    assert(str2);

    if (str1 == str2)
    {
        return 0;
    }

    const char* start_ptr1 = str1;
    const char* start_ptr2 = str2;

    str1 = reverse_ignore_no_letters(str1);
    str2 = reverse_ignore_no_letters(str2);    

    for ( ; *str1 == *str2; )
    {
        if (str1 == start_ptr1)
        {
            if (str2 == start_ptr2)
            {
                return 0;
            }

            return -1;
        }

        if (str2 == start_ptr2)
        {
            return 1;
        }

        str1--; str2--;
    }

    return *str1 - *str2;
}

char** parse_buffer(char* buffer, int nlines, int file_size)
{
    assert(buffer);

    char** text = (char**) calloc(nlines + 1, sizeof(char*));
    assert(text);
    text[0] = buffer;

    for (int buffer_index = 0, text_index = 0; buffer_index < file_size; buffer_index++)
    {
        if (buffer[buffer_index] == '\n')
        {
            text[++text_index] = &buffer[buffer_index + 1];
            buffer[buffer_index] = '\0';
        }

        if (buffer[buffer_index] == '\r')
        {
           buffer[buffer_index] = '\n';
        }
    }

    return text;
}