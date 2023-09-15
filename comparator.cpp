#include <cassert>

#include "comparator.h"
#include "str_functions.h"

int char_cmp(const void* s1, const void* s2)
{
    assert(s1);
    assert(s2); 

    int result = mystrcmp(*(const char*const*) (const void*const*) s1, 
                          *(const char*const*) (const void*const*) s2);

    return result;
}

int reverse_char_cmp(const void* s1, const void* s2)
{
    assert(s1);
    assert(s2);

    int result = reverse_strcmp(*(const char*const*) (const void*const*) s1, 
                                *(const char*const*) (const void*const*) s2);

    return result;
}