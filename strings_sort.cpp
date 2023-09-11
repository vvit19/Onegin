#include <cassert>
#include <cstring>
#include <cstdio>
#include "strings_sort.h"
#include "str_functions.h"

void bubble_sort(void* array, size_t array_size, size_t el_size, 
                 int (*cmp_function)(const void* a, const void* b))
{
    assert(array);
    assert(cmp_function);

    for (size_t i = 0; i < array_size; i++)
    {
        for (size_t j = 0; j < array_size - i - 1; j++)
        {
            if (cmp_function( *(void**) ((char*) array + j * el_size),
                              *(void**) ((char*) array + (j + 1) * el_size) ) > 0)
            {
                swap((char*) array + j * el_size, (char*) array + (j + 1) * el_size, el_size);             
            }
        }
    }
}

void swap(void* ptr1, void* ptr2, size_t el_size)
{
    assert(ptr1);
    assert(ptr2);

    void* temp = (void*) calloc(1, el_size);
    assert(temp);

    memcpy(temp, ptr1, el_size);
    memcpy(ptr1, ptr2, el_size);
    memcpy(ptr2, temp, el_size);

    free(temp);
}


