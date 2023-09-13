#ifndef STRINGS_SORT_H
#define STRINGS_SORT_H

#include <cstdio>

void quick_sort(void* array, int left, int right, int el_size,
                int (*cmp_function)(const void* a, const void* b), void* free_memory);
void bubble_sort(void* array, int array_size, int el_size, 
                 int (*cmp_function)(const void* a, const void* b), void* free_memory);

#endif