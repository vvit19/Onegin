#include <cassert>
#include <cstring>
#include <cstdio>
#include <cstdlib>

#include "strings_sort.h"
#include "str_functions.h"

static void swap(void* ptr1, void* ptr2, int el_size);

void quick_sort(void* array, int low_limit, int high_limit, int el_size,
                int (*cmp_function)(const void* a, const void* b))
{
    assert(array);
    assert(cmp_function);

    if (low_limit >= high_limit)
    {
        return;
    }

    int left = low_limit;
    int right = high_limit;

    int pivot_num = (low_limit + high_limit) / 2;
    void* pivot = *(void**) ((int) array + pivot_num * el_size);

    do
    {
        while (cmp_function( *(void**) ((int) array + left  * el_size), pivot ) < 0)
        {
            left++;
        }

        while (cmp_function( *(void**) ((int) array + right * el_size), pivot ) > 0)
        {
            right--;
        }        

        if (left <= right)
        {
            swap((void*) ((int) array + left * el_size), (void*) ((int) array + right * el_size), el_size);
            left++; right--;
        }

    }   while (left < right);

    quick_sort(array, low_limit, right, el_size, cmp_function);
    quick_sort(array, left, high_limit, el_size, cmp_function);
}

void bubble_sort(void* array, int array_size, int el_size, 
                 int (*cmp_function)(const void* a, const void* b))
{
    assert(array);
    assert(cmp_function);

    for (int i = 0; i < array_size; i++)
    {
        for (int j = 0; j < array_size - i - 1; j++)
        {
            if (cmp_function( *(void**) ((int) array + j * el_size),
                              *(void**) ((int) array + (j + 1) * el_size) ) > 0)
            {
                swap((void*) ((int) array + j * el_size), (void*) ((int) array + (j + 1) * el_size), el_size);             
            }
        }
    }
}

static void swap(void* ptr1, void* ptr2, int el_size)
{
    assert(ptr1);
    assert(ptr2);

    char* p1  = (char*) ptr1;
    char* p2  = (char*) ptr2;
    char temp = 0;

    for (int i = 0; i < el_size; i++)
    {
        memcpy(&temp, p1, sizeof(char));
               memcpy(p1, p2, sizeof(char));
                   memcpy(p2, &temp, sizeof(char));

        p1++; p2++;
    }    
}