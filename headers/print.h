#ifndef __print_h__
#define __print_h__

#include <chrono>
using namespace std;

void array_print(int *arr, int size, const char* title="");

void time_print(int size, char* sort, chrono::duration<double> time);

void all_algorytms_print(char **name_array, int data, double *time_array, int rows);

void progress_print(int done, int todo);

#endif //__print_h__