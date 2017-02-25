#include <iostream>
#include "pagedArray.h"
#include "sortAlgorithms.h"
#include "filesConverter.h"
#include <fstream>
#include <iostream>

int intCounter(ifstream& file){
    file.seekg(0, ios_base::end);
    return file.tellg()/4;
}

void createPagedArray(string file){
    string binFile = filesConverter::decimalToBinary(file);
    ifstream sortFile(binFile, ios::binary);
    int numInts = intCounter(sortFile);
    sortFile.seekg(0);
    pagedArray intsArray(numInts, binFile.c_str());
    int v;
    int index = 0;
    while (sortFile.read(reinterpret_cast<char *>(&v), sizeof(v))) {
        intsArray[index] = v;
        index++;
    }
    //quicksort(intsArray);
    //insertionSort(intsArray);
    selectionSort(intsArray);
    filesConverter::binaryToDecimal(binFile, file+"_resultado");
    remove(binFile.c_str());
}


int main() {
  createPagedArray("1KB");
    createPagedArray("4KB");
    createPagedArray("8KB");
    createPagedArray("12KB");createPagedArray("24KB");createPagedArray("36KB");


  //createFile();
    //string binFile = filesConverter::decimalToBinary("binary36KB");
  /*  string binFile = filesConverter::decimalToBinary("1KB");
    ifstream sortFile(binFile, ios::binary);
    int numInts = intCounter(sortFile);
    sortFile.seekg(0);
    int numInts1 = numInts;
    pagedArray intsArray(numInts1, binFile.c_str());

  /* int v;
    int index = 0;
    while (sortFile.read(reinterpret_cast<char *>(&v), sizeof(v))) {
        intsArray[index] = v;
        index++;
    }
        filesConverter::binaryToArray(binFile, intsArray);

        //selectionSort(intsArray);
        //insertionSort(intsArray);
        selectionSort(intsArray);
        //filesConverter::binaryToDecimal(binFile, binFile+"_resultado");


    {
        int v;
        ifstream infile(binFile, ios::binary);
        infile.seekg(0);
        while (infile.read(reinterpret_cast<char *>(&v), sizeof(v))) {
            cout << v << ' ';
        }
    }
*/
            return 0;

    }