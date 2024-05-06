#include <iostream>
#include <fstream>

#include "headers/algortymy.h"
#include "headers/print.h"
#include "headers/memoryManager.h"
#include "headers/timeManager.h"
#include "headers/fileManager.h"

#define OPTIONS 8
#define FINISH 7
#define ALL_ALGO 6

using namespace std;

/*
    TODO main: 
        DONE * timer 
        DONE * read from files the numerical data
        DONE * write to files the numerical answers
    
    TODO other:
        * finish algorytmy.cpp
        * 

*/




int get_array_size();
void option_main(int option, int *array, int size, ifstream& inputFile);
void option_insert_sort(int option, int *array, int size);
void option_bubble_sort(int option, int *array, int size);
void option_selection_sort(int option, int *array, int size);
void menu();

int input_data_to_file(ifstream& inputFile, int *array, int size);

char* insertionOptions[] = {
    (char*)"Insertion Sort",
    (char*)"Insertion Sort with Guard",
    (char*)"Insertion Sort Binary Search"
};

char* bubbleOptions[] = {
    (char*)"Bubble Sort",
    (char*)"Shaker Sort",
};

char* selectionOptions[] = {
    (char*)"Selection Sort",
    (char*)"Double Selection Sort"
};

char* options[OPTIONS] = {
    (char*)"Insertion Sort",
    (char*)"Bubble Sort",
    (char*)"Selection Sort",
    (char*)"Quick Sort",
    (char*)"Heap Sort",
    (char*)"Sheall Sort",
    (char*)"All Algorithms", 
    (char*)"Finish"
};

int main() {
    int option = 0;
    // int delay = 0;
    // int size = 1;
    cout<<"Input size of 0 to finish"<<endl;
    ofstream commentFile; openFile(commentFile, "comment.txt");
    ofstream sortedFile; openFile(sortedFile, "sort.txt");

    while(option != FINISH) {
        ifstream inputFile; openFile(inputFile, "dane");

        int size = get_array_size();
        if (size<=0) break;
        
        int *array=allocate_memory_for_array(size);

        int count = input_data_to_file(inputFile, array, size);

        menu(); cin>>option;
        option_main(option, array, size, inputFile);
        
        if (option != ALL_ALGO) {
            time_print(size, options[option], get_time());
        
            string sizeStr = to_string(size);
            string timeStr = to_string(get_time().count());

            commentFile << options[option] << "\t" << sizeStr << "\t" << timeStr <<endl;
            sortedFile << "Size of data is " << sizeStr << " and using " << options[option] << " it took " << timeStr << "s to sort that array.\n";

            write_array_to_file(sortedFile, array, count);
        }

        free_memory_from_array(array);
        
        closeFile(inputFile);

        cout<<endl<<endl;
    }

    closeFile(commentFile);
    closeFile(sortedFile);

    return 0;
}

int get_array_size() {
    int size;
    cout<<"Enter array size: "<<endl;
    cin>>size;
    return size;
}

void menu() {
    for(int i=0; i<OPTIONS; i++)
        cout<<i<<". "<<options[i]<<endl;
}

void option_main(int option, int *array, int size, ifstream& inputFile) {
    switch (option)
        {
        case FINISH:
            break;
        default:
            break;
        case 0:
            start_timer();
            insert_sort(array, size);
            end_timer();
            break;
        case 1:
            start_timer();
            bubble_sort(array, size);
            end_timer();
            break;
        case 2:
            start_timer();
            selection_sort(array, size);
            end_timer();
            break;
        case 3:
            start_timer();
            quick_sort(array, 0, size);
            end_timer();
            break;
        case 4:
            start_timer();
            heap_sort(array, size);
            end_timer();
            break;
        case 5:
            start_timer();
            shell_sort(array, size);
            end_timer();
            break;
        case 6: 
        // I don't like this case; It is to big but I don't know how to make it smaller.
            double time_array[OPTIONS-2] = {0};
            int time_index=0;
            progress_print(time_index,OPTIONS-2);

            start_timer();
            insert_sort(array, size);
            end_timer();
            time_array[time_index++] = get_time().count();
            input_data_to_file(inputFile, array, size);
            progress_print(time_index,OPTIONS-2);

            start_timer();
            bubble_sort(array, size);
            end_timer();
            time_array[time_index++] = get_time().count();
            input_data_to_file(inputFile, array, size);
            progress_print(time_index,OPTIONS-2);

            start_timer();
            selection_sort(array, size);
            end_timer();
            time_array[time_index++] = get_time().count();
            input_data_to_file(inputFile, array, size);
            progress_print(time_index,OPTIONS-2);

            start_timer();
            quick_sort(array, 0, size);
            end_timer();
            time_array[time_index++] = get_time().count();
            input_data_to_file(inputFile, array, size);
            progress_print(time_index,OPTIONS-2);
            
            start_timer();
            heap_sort(array, size);
            end_timer();
            time_array[time_index++] = get_time().count();
            input_data_to_file(inputFile, array, size);
            progress_print(time_index,OPTIONS-2);

            start_timer();
            shell_sort(array, size);
            end_timer();
            time_array[time_index++] = get_time().count();
            progress_print(time_index,OPTIONS-2);

            all_algorytms_print(options, size, time_array, OPTIONS-2);
            break;
        }
}

void option_insert_sort(int option, int *array, int size) {
    switch (option)
        {
        case 0:
            start_timer();
            insert_sort(array, size);
            end_timer();
            break;
        case 1:
            start_timer();
            insert_sort_with_guard(array, size);
            end_timer();
            break;
        case 2:
            start_timer();
            insert_sort_with_BinSea(array, size);
            end_timer();
            break;
        default:
            break;
        }
}

void option_bubble_sort(int option, int *array, int size) {
    switch (option)
        {
        case 0:
            start_timer();
            bubble_sort(array, size);
            end_timer();
            break;
        case 1:
            start_timer();
            shaker_sort(array, size);
            end_timer();
            break;
        default:
            break;
        }
}

void option_selection_sort(int option, int *array, int size) {
    switch (option)
        {
        case 0:
            start_timer();
            selection_sort(array, size);
            end_timer();
            break;
        case 1:
            start_timer();
            double_selection_sort(array, size);
            end_timer();
            break;
        default:
            break;
        }
}

int input_data_to_file(ifstream& inputFile, int *array, int size) {
    int count = 0;
    while (count < size && inputFile >> array[count]) {
        count++;
    }
    return count;
}