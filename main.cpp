#include <iostream>
#include "headers/algortymy.h"
#include "headers/print.h"
#include "headers/memoryManager.h"

#define OPTIONS 7
#define FINISH 6

using namespace std;

/*
    TODO main: 
        * timer 
        * read from files the numerical data
        * write to files the numerical answers
        *  
    
    TODO other:
        * finish algorytmy.cpp
        * 

*/




int get_array_size();

char* options[OPTIONS] = {
    (char*)"Insertion Sort",
    (char*)"Bubble Sort",
    (char*)"Selection Sort",
    (char*)"Quick Sort",
    (char*)"Heap Sort",
    (char*)"Sheall Sort",
    (char*)"Finish"
};

int main() {
    int option = 0;

    while(option != FINISH) {
        int size = get_array_size();
        int *array=allocate_memory_for_array(size);
        array_print(array, size, "Before sorting: \n\t");



        for(int i=0; i<OPTIONS; i++)
            cout<<i<<". "<<options[i]<<endl;

        cin>>option;
        switch (option)
        {
        case 0:
            insert_sort(array, size);
            break;
        case 1:
            bubble_sort(array, size);
            break;
        case 2:
            selection_sort(array, size);
            break;
        case 3:
            quick_sort(array, 0, size);
            break;
        case 4:
            heap_sort(array, size);
            break;
        case 5:
            shell_sort(array, size);
            break;
        case FINISH:
            break;
        default:
            break;
        }

        array_print(array, size, "After sorting: \n\t");

        free_memory_from_array(array);
        cout<<endl<<endl;
    }

    return 0;
}

int get_array_size() {
    int size;
    cout<<"Enter array size: "<<endl;
    cin>>size;
    return size;
}