#include <cassert>
#include <cstring>
#include <cstdio>
#include <cstdlib>

#include "strings_sort.h"
#include "str_functions.h"

static void swap(void* a, void* b, int el_size, void* temp);

void quick_sort(void* array, int low_limit, int high_limit, int el_size,
                int (*cmp_function)(const void* a, const void* b), void* free_memory)
{
    assert(array);
    assert(cmp_function);
    assert(free_memory);

    int left = low_limit;
    int right = high_limit - 1;
    int pivot = (low_limit + high_limit) / 2;

    do
    {
        while (cmp_function( *(void**) ((int) array + left * el_size), 
                             *(void**) ((int) array + pivot * el_size) ) < 0)
        {
            left++;
        }

        while (cmp_function( *(void**) ((int) array + right * el_size), 
                             *(void**) ((int) array + pivot * el_size) ) > 0)
        {
            right--;
        }        

        if (left <= right)
        {
            swap((void*) ((int) array + left * el_size), (void*) ((int) array + right * el_size), el_size, free_memory);
            left++; right--;
        }

    }   while (left <= right);
    
    if (right > 0 && (right + 1 - low_limit) > 2)
    {
        quick_sort(array, low_limit, right + 1, el_size, cmp_function, free_memory);
    }

    if (left < high_limit && (high_limit - left) > 2)
    {
        quick_sort(array, left, high_limit, el_size, cmp_function, free_memory);
    }
}

void bubble_sort(void* array, int array_size, int el_size, 
                 int (*cmp_function)(const void* a, const void* b), void* free_memory)
{
    assert(array);
    assert(cmp_function);
    assert(free_memory);

    for (int i = 0; i < array_size; i++)
    {
        for (int j = 0; j < array_size - i - 1; j++)
        {
            if (cmp_function( *(void**) ((int) array + j * el_size),
                              *(void**) ((int) array + (j + 1) * el_size) ) > 0)
            {
                swap((void*) ((int) array + j * el_size), (void*) ((int) array + (j + 1) * el_size), el_size, free_memory);             
            }
        }
    }
}

static void swap(void* ptr1, void* ptr2, int el_size, void* temp)
{
    assert(ptr1);
    assert(ptr2);
    assert(temp);

    memcpy(temp, ptr1, el_size);
    memcpy(ptr1, ptr2, el_size);
    memcpy(ptr2, temp, el_size);
}