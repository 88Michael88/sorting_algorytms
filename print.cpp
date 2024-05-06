#include <iostream>
#include <iomanip>
#include "headers/print.h"

using namespace std;

void array_print(int *arr, int size, const char* title)
/*
    Print the array with a title

    Input:
        *arr - is the array which we want to print
        size - is the size of the array
        title - is the title we want to give went printning the array

    Output:
        void
*/
{

    cout<<title;
    for (int i = 0; i < size; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


void time_print(int size, char* sort, chrono::duration<double> time) {
    cout<<"Size of data is "<<size<<" and using "<<sort<<" it took "<<time.count()<<"s. to sort that array."<<endl;
}

void all_algorytms_print(char **name_array, int data, double *time_array, int rows) {
    // +----------------+-------------+-------------+
    // | Name           | Data        | Time        |
    // +----------------+-------------+-------------+
    // | Insertion Sort |
    // +----------------+-------------+-------------+
    // | Bubble Sort    |
    // +----------------+-------------+-------------+
    // | Selection Sort |
    // +----------------+-------------+-------------+
    // | Quick Sort     |
    // +----------------+-------------+-------------+
    // | Heap Sort      |
    // +----------------+-------------+-------------+
    // | Shell Sort     |
    // +----------------+-------------+-------------+

    char* row =   (char*)"+----------------+-------------+-------------+";
    char* names = (char*)"| Name           | Data        | Time        |";
    cout<<"Warning!"<<endl<<"Assumtion: You have data * "<<rows<<" numbers in the input file."<<endl;
    cout<<row<<endl<<names<<endl<<row<<endl;
    for (int i=0; i<rows; i++) {
        cout<<"| "<<setw(14)<<left<<name_array[i]<<" | "<<setw(11)<<right<<data<<" | "<<setw(11)<<time_array[i]<<" |"<<endl;
        cout<<row<<endl;
    }
}

void progress_print(int done, int todo) {
    if (done >= todo) return;
    int proDone = ((double)done/todo)*100;
    cout<<proDone<<"% \r";
    cout.flush();
}