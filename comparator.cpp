#include <cassert>
#include "comparator.h"
#include "str_functions.h"

int int_cmp(const void* a, const void* b)
{
    assert(a);
    assert(b);

    return *(const int*) a - *(const int*) b;
}

int double_cmp(const void* a, const void* b)
{
    assert(a);
    assert(b);

    return (int) (*(const double*) a - *(const double*) b);
}

int char_cmp(const void* str1, const void* str2)
{
    assert(str1);
    assert(str2); 

    int result = mystrcmp((const char*) str1, (const char*) str2);

    return result;
}

int reverse_char_cmp(const void* str1, const void* str2)
{
    assert(str1);
    assert(str2);

    int result = reverse_strcmp((const char*) str1, (const char*) str2);

    return result;
}