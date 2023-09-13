#include <cassert>
#include <cstring>
#include <cstdio>
#include <cstdlib>

#include "strings_sort.h"
#include "str_functions.h"

static void swap(void* a, void* b, int el_size, void* temp);
/*
void quick_sort(void* array, int left, int right, int el_size,
                int (*cmp_function)(const void* a, const void* b))
{
    assert(array);
    assert(cmp_function);

    static void* free_memory = (void*) calloc(1, el_size); 
    assert(free_memory);   

    if (right <= left || right <= 0 || left < 0 || (right - left) < 3) 
    {
        free(free_memory);
        return;
    }

    int low_limit  = left;
    int high_limit = right;

    int pivot = (left + right) / 2;

    while (left <= right)
    {
        while ((cmp_function( *(void**) ((char*) array + left * el_size), 
                              *(void**) ((char*) array + pivot * el_size) ) < 0))
        {
            left++;
        }

        while ((cmp_function( *(void**) ((char*) array + right * el_size), 
                              *(void**) ((char*) array + pivot * el_size) ) > 0))
        {
            right--;
        }

        if (left >= right)
        {
            break;
        }

        swap((char*) array + left * el_size, (char*) array + right * el_size, el_size, free_memory);

        left++; right--;
    }

    quick_sort(array, low_limit, left, el_size, cmp_function);
    quick_sort(array, right, high_limit, el_size, cmp_function);
}
*/


void bubble_sort(void* array, int array_size, int el_size, 
                 int (*cmp_function)(const void* a, const void* b))
{
    assert(array);
    assert(cmp_function);

    void* temp = (void*) calloc(1, el_size);
    printf("%d\n", el_size);
    printf("%p\n", temp);
    assert(temp);

    for (int i = 0; i < array_size; i++)
    {
        for (int j = 0; j < array_size - i - 1; j++)
        {
            if (cmp_function( *(void**) ((char*) array + j * el_size),
                              *(void**) ((char*) array + (j + 1) * el_size) ) > 0)
            {
                swap((char*) array + j * el_size, (char*) array + (j + 1) * el_size, el_size, temp);             
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

    free(temp);
}