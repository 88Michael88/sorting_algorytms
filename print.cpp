#include <iostream>
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