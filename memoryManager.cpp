#include "headers/memoryManager.h"

int* allocate_memory_for_array(int size) {
    return new int[size];
}

void free_memory_from_array(int *array) {
    delete [] array;
}