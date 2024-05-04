#include "headers/algortymy.h"
#include "headers/print.h"
#include <iostream>

using namespace std;

// Extra functions for heap sort
void build_max_heap(int *array, int size);
void heapify(int *array, int size, int i);

// Extra functions for shell sort
void shell_insert(int *array, int size, int knuth);

// Extra functions for insert sort
int binarySearch(int *array, int item, int begin, int end);

/*
    TODO base:
        DONE * Insert sort
        DONE * Bubble sort
        DONE * Selection sort

        DONE * Quick sort
        DONE * Heap sort
        DONE * Shell sort
    
    TODO extra: 
        DONE * Insert sort with guard
        DONE * Insert sort with binarry search

        DONE * Bubble sort - shaker

        * Double Selection sort

        * Quick sort - partition

        * Shell Bubble sort
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

// Insert Sort with Guard
// Assume array = [0, 6, 7, 1, 3, 7, 8, ... ] is filled from index 1.
void insert_sort_with_guard(int *array, int size) {
    int j, guard;
    for (int i=2; i<=size; i++) {
        guard = array[i];
        j = i-1;
        array[0] = guard;
        while(array[j]>guard) {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = guard;
    }
}

// Insert Sort with Binary Search
void insert_sort_with_BinSea(int *array, int size) {
    int j;
 
    for (int i = 1; i < size; ++i) {
        j = i - 1;
        int val = array[i];
 
        // find pos where val should be inserted
        int pos = binarySearch(array, val, j, 0);
 
        // Move all elements after location to create space
        while (j >= pos){
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = val;
    }
}

int binarySearch(int *array, int item, int begin, int end) {
    if (begin <= end)
        return (item > array[end]) ? (end + 1) : end;
 
    int mid = (end + begin) / 2;
 
    if (item == array[mid])
        return mid + 1;
 
    if (item > array[mid])
        return binarySearch(array, item,mid + 1, begin);
    return binarySearch(array, item, end, mid - 1);
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

// Shaker Sort
void shaker_sort(int *array, int size) {
    int l = 0, r = size-2, temp, index=0;
	do{
		for(int i=r; i>=l; i--){
			if (array[i]>array[i+1]) {
			 temp = array[i];
				array[i] = array[i+1];
				array[i+1] = temp;
				index = i;
			}
		}
		l = index+1;
		for(int i=l; i<=r; i++) {
			if (array[i]>array[i+1]) {
			 temp = array[i];
				array[i] = array[i+1];
				array[i+1] = temp;
				index = i;
			}
		}
		r  = index;
	}while(l<=r);
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

// Heap Sort
void heap_sort(int *array, int size) { 
    build_max_heap(array, size);
    for(int i=size-1; i>=0; i--) {
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        heapify(array, i, 0);
    }
}

void build_max_heap(int *array, int size) {
    for(int i=((size/2)-1); i>=0; i--){
        heapify(array, size, i);
    }
}

void heapify(int *array, int size, int i) {
    int largest = i, temp, l_child = 2*i+1, r_child = 2*i+2;

    if (l_child < size && array[l_child] > array[largest])
        largest = l_child;

    if (r_child < size && array[r_child] > array[largest])
        largest = r_child;
    
    if (largest != i) {
        temp = array[i];
        array[i] = array[largest];
        array[largest] = temp;
        heapify(array, size, largest);
    }
}

// Shell Sort
void shell_sort(int *array, int size) {
    int knuthNext, knuth;
    knuthNext = knuth = 1;
    do {
        knuth = knuthNext;
        knuthNext = 3*knuth+1;
    }while(knuthNext<=size);

    while(knuth>0) {
        shell_insert(array, size, knuth);
        knuth/=3;
    }
}

void shell_insert(int *array, int size, int knuth) {
    int temp;
    for(int n=0; n<knuth; n++) {
        for(int i=n+knuth; i<size; i+=knuth) {
            for(int j=i-knuth; j>=0 && array[j]>array[j+knuth]; j-=knuth) {
                temp = array[j+knuth];
                array[j+knuth] = array[j];
                array[j] = temp;
            }
        }
    }
}