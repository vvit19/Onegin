#include <cassert>
#include <cstdio>
#include <cstdlib>
#include "str_functions.h"

const char* ignore_no_letters(const char* string)
{
    assert(string);

    const char* help_ptr = string;

    for ( ; ; help_ptr++)
    {
        if (*help_ptr == '\0')
        {
            return string;
        }

        if (! ((*help_ptr >= 'a' && *help_ptr <= 'z') || 
               (*help_ptr >= 'A' && *help_ptr <= 'Z')))
        {
            continue;
        }

        return help_ptr;
    }
}

int mystrcmp(const char* str1, const char* str2)
{
    assert(str1);
    assert(str2);

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

size_t mystrlen(char* string)
{
    assert(string);

    int len = 0;

    for (; string[len] != '\0'; len++);

    return len;
}