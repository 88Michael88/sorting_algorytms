#include "headers/algortymy.h"
#include "headers/print.h"
#include <iostream>

using namespace std;

/*
    TODO base:
        DONE * Insert sort
        * Bubble sort
        * Selection sort

        * Quick sort
        * Heap sort
        * Shell sort

    
    TODO extra: 
        * Insert sort with guard
        * Insert sort with binarry search

        * Bubble sort - shaker

        * Double Selection sort

        * Quick sort - partition
*/


// Insert Sort
void insert_sort(int *array, int size) {
    int j;
    for (int i=1; i<size; i++) {
        int val = array[i];
        j = i - 1;
        while (j>=0 && array[j] > val) {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = val;
    }
}
