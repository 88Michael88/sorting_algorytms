#ifndef __algorytmy_h__
#define __algorytmy_h__

void insert_sort(int *array, int size);

void bubble_sort(int *array, int size);

void selection_sort(int *array, int size);

void quick_sort(int *array, int begin, int end);

void heap_sort(int *array, int size);

void shell_sort(int *array, int size);

//Extra functions:
void insert_sort_with_guard(int *array, int size);

void insert_sort_with_BinSea(int *array, int size);

void shaker_sort(int *array, int size);

#endif //__algorytmy_h__