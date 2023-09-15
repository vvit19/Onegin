#ifndef STRINGS_SORT_H
#define STRINGS_SORT_H

#include <cstdio>

void quick_sort(void* array, int left, int right, int el_size,
                int (*cmp_function)(const void* s1, const void* s2));

#endif