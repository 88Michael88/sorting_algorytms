#ifndef __file_Manager_h__
#define __file_Manager_h__

#include <fstream>
using namespace std;

bool openFile(ifstream& fileStream, const char* fileName);

bool openFile(ofstream& fileStream, const char* fileName);

void closeFile(ifstream& fileStream);

void closeFile(ofstream& fileStream);

void write_line_to_file(ofstream& fileStream, char* text);

void write_array_to_file(ofstream& fileStream, int *array, int size);


#endif //__file_Manager_h__