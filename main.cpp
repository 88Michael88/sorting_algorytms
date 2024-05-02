#include <iostream>
#include "headers/algortymy.h"

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
    int size = 0;
    // int *array=nullptr;
    int array[] = {2, 5, 1, 3, 0};

    while(option != FINISH) {
        cout<<"Podaj rozmiar tablicy: "<<endl;
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
            insert_sort(array, size);
            break;
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case FINISH:
            break;
        default:
            break;
        }

        // delete[] array;       
        cout<<endl<<endl;
    }

    return 0;
}