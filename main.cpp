#include <iostream>
#include "headers/algortymy.h"
#include "headers/print.h"

#define OPTIONS 7
#define FINISH 6

// FOR TESTING
#define TEST_SIZE 5

using namespace std;

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
    //int size = 0;
    // int *array=nullptr;

    while(option != FINISH) {
        int array[] = {2, 5, 1, 3, 0};

        array_print(array, TEST_SIZE, "Before sorting: \n\t");

        cout<<"Enter array size: "<<endl;
        cout<<TEST_SIZE<<endl;
        // cin>>size;
        // array = new int[size];



        // cout<<array<<endl;
        for(int i=0; i<OPTIONS; i++)
            cout<<i<<". "<<options[i]<<endl;

        cin>>option;
        switch (option)
        {
        case 0:
            insert_sort(array, TEST_SIZE);
            break;
        case 1:
            bubble_sort(array, TEST_SIZE);
            break;
        case 2:
            selection_sort(array, TEST_SIZE);
            break;
        case 3:
            quick_sort(array, 0, TEST_SIZE);
            break;
        case 4:
            heap_sort(array, TEST_SIZE);
            break;
        case 5:
            shell_sort(array, TEST_SIZE);
            break;
        case FINISH:
            break;
        default:
            break;
        }

        array_print(array, TEST_SIZE, "After sorting: \n\t");

        // delete[] array;       
        cout<<endl<<endl;
    }

    return 0;
}