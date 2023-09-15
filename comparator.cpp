#include <cassert>

#include "comparator.h"
#include "str_functions.h"

int char_cmp(void* array, int position, int el_size, void* cmp_element)
{
    assert(array);
    assert(cmp_element); 

    int result = mystrcmp((const char*) (*(void**) ((int) array + position * el_size)), 
                          (const char*) cmp_element);

    return result;
}

int reverse_char_cmp(void* array, int position, int el_size, void* cmp_element)
{
    assert(array);
    assert(cmp_element);

    int result = reverse_strcmp((const char*) (*(void**) ((int) array + position * el_size)), 
                                (const char*) cmp_element);

    return result;
}