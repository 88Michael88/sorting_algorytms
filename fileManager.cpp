#include <iostream>
#include <fstream>

#include "headers/fileManager.h"

using namespace std;

bool openFile(ifstream& fileStream, const char* fileName) {
    fileStream.open(fileName);

    if (!fileStream.is_open()) {
        cerr << "Unable to open file" << endl;
        return false;  
    }

    return true;
}


bool openFile(ofstream& fileStream, const char* fileName) {
    fileStream.open(fileName);

    if (!fileStream.is_open()) {
        cerr << "Unable to open file" << endl;
        return false;  
    }

    return true;
}


void closeFile(ifstream& fileStream) {
    fileStream.close();
}


void closeFile(ofstream& fileStream) {
    fileStream.close();
}


void write_line_to_file(ofstream& fileStream, char* text) {
    fileStream << text;
}


void write_array_to_file(ofstream& fileStream, int *array, int size) {
        for (int i = 0; i < size; i++) {
            fileStream << array[i] << " ";
        }
        fileStream << "\n\n\n\n";
}