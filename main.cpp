#include <iostream>
#include <fstream>

#include "headers/algortymy.h"
#include "headers/print.h"
#include "headers/memoryManager.h"
#include "headers/timeManager.h"
#include "headers/fileManager.h"

#define OPTIONS 7
#define FINISH 6

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
void menu();

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
    // int delay = 0;
    // int size = 1;

    ofstream commentFile; openFile(commentFile, "comment.txt");
    ofstream sortedFile; openFile(sortedFile, "sort.txt");

    while(option != FINISH) {
        ifstream inputFile; openFile(inputFile, "dane");

        int size = get_array_size();
        if (size<=0) break;
        
        int *array=allocate_memory_for_array(size);

        // delay++;

        int count = 0;
        while (count < size && inputFile >> array[count]) {
            count++;
        }

        menu();
        cin>>option;

        switch (option)
        {
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
        case FINISH:
            break;
        default:
            break;
        }

        time_print(size, options[option], get_time());
        
        string sizeStr = to_string(size);
        string timeStr = to_string(get_time().count());

        commentFile << options[option] << "\t" << sizeStr << "\t" << timeStr <<endl;
        sortedFile << "Size of data is " << sizeStr << " and using " << options[option] << " it took " << timeStr << "s to sort that array.\n";

        write_array_to_file(sortedFile, array, count);

        // array_print(array, size, "After sorting: \n\t");


        // This is for testing all of the funtions with different amounts of data.
        // if (delay%2==0)
        //     size *= 2;
        // else
        //     size *= 5;

        // if (option < 3) {
        //     if (delay==12) {
        //         delay = 0;
        //         size = 1;
        //         option++;
        //         commentFile << "\n\n\n\n";
        //     }
        // }else {
        //     if (delay==17) {
        //         delay = 0;
        //         size = 1;
        //         option++;
        //         commentFile << "\n\n\n\n";
        //     }
        // }
        

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