#include <iostream>
#include "headers/algortymy.h"
#include "headers/print.h"
#include "headers/memoryManager.h"
#include "headers/timeManager.h"

#define OPTIONS 7
#define FINISH 6

using namespace std;

/*
    TODO main: 
        DONE * timer 
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
            start_timer();
            insert_sort(array, size);
            end_timer();
            time_print(size, options[option], get_time());
            break;
        case 1:
            start_timer();
            bubble_sort(array, size);
            end_timer();
            time_print(size, options[option], get_time());
            break;
        case 2:
            start_timer();
            selection_sort(array, size);
            end_timer();
            time_print(size, options[option], get_time());
            break;
        case 3:
            start_timer();
            quick_sort(array, 0, size);
            end_timer();
            time_print(size, options[option], get_time());
            break;
        case 4:
            start_timer();
            heap_sort(array, size);
            end_timer();
            time_print(size, options[option], get_time());
            break;
        case 5:
            start_timer();
            shell_sort(array, size);
            end_timer();
            time_print(size, options[option], get_time());
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