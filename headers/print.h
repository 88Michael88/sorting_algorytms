#ifndef __print_h__
#define __print_h__

#include <chrono>
using namespace std;

void array_print(int *arr, int size, const char* title="");

void time_print(int size, char* sort, chrono::duration<double> time);

#endif //__print_h__