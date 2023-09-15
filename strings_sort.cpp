#include <cassert>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <random>

#include "strings_sort.h"
#include "str_functions.h"

static void swap(void* ptr1, void* ptr2, int el_size);
static int partition(void* array, int low_limit, int high_limit, int el_size,
                     int (*cmp_function)(const void* s1, const void* s2));

void quick_sort(void* array, int low_limit, int high_limit, int el_size,
                int (*cmp_function)(const void* s1, const void* s2))
{
    if (low_limit < high_limit)
    {
        int pivot_num = partition(array, low_limit, high_limit, el_size, cmp_function);

        quick_sort(array, low_limit,  pivot_num - 1, el_size, cmp_function);
        quick_sort(array, pivot_num + 1, high_limit, el_size, cmp_function);
    }
}

static int partition(void* array, int low_limit, int high_limit, int el_size,
                     int (*cmp_function)(const void* s1, const void* s2))
{
    int pivot_num = rand() % (high_limit - low_limit) + low_limit;
    swap((void*) ((int) array + pivot_num * el_size), (void*) ((int) array + high_limit * el_size), el_size);

    void* pivot = (void*) ((char*) array + high_limit * el_size);

    int cnt_for_greater = low_limit - 1;
    int cnt_for_smaller = low_limit;

    for (; cnt_for_smaller < high_limit; cnt_for_smaller++)
    {
        if (cmp_function( (void*) ((char*) array + cnt_for_smaller * el_size), pivot ) <= 0)
        {
            cnt_for_greater++;

            swap((void*) ((int) array + cnt_for_greater * el_size), 
                 (void*) ((int) array + cnt_for_smaller * el_size), el_size);
        }
    }

    swap((void*) ((int) array + (cnt_for_greater + 1) * el_size), 
         (void*) ((int) array +  high_limit * el_size), el_size);       

    return cnt_for_greater + 1;
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