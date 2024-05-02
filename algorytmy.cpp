#include "headers/algortymy.h"
#include "headers/print.h"
#include <iostream>

using namespace std;

/*
    TODO base:
        DONE * Insert sort
        DONE * Bubble sort
        DONE * Selection sort

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

// Bubble Sort
void bubble_sort(int *array, int size) {
    int change, temp;
    do {
        change = 0;
        for(int i=0; i<size-1; i++) {
            if (array[i]>array[i+1]){
                temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
                change = 1;
            }
        }
    }while (change);
}

// Selection Sort
void selection_sort(int *array, int size) {
    int temp;
    for(int i=0; i<size-1; i++) {
        int min_index = i;
        for (int j=i+1; j<size; j++) {
            if (array[j] < array[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            temp = array[i];
            array[i] = array[min_index];
            array[min_index] = temp;
        }
    }
}

// Quick Sort
void quick_sort(int *array, int begin, int end) {
    int i=begin, j=end-1, pivot, temp;
    pivot = array[(i+j)/2];

    do {
        while(array[i]<pivot)
            i++;
        while(array[j]>pivot)
            j--;
        if(i<=j) {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }while(i<=j);

    if(j>begin) quick_sort(array, begin, j);
    if(i<end)   quick_sort(array, i, end);
}