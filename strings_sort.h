#ifndef STRINGS_SORT_H
#define STRINGS_SORT_H

void bubble_sort(void* array, size_t array_size, size_t el_size, int (*cmp_function)(const void* a, const void* b));
void swap(void* a, void* b, size_t el_size);

#endif