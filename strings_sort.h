#ifndef STRINGS_SORT_H
#define STRINGS_SORT_H

#include <cstdio>

void quick_sort(void* array, int left, int right, int el_size,
                 int (*cmp_function)(void* array, int position, int el_size, void* cmp_element));

#endif