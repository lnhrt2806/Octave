#include <iostream>
#include "pagedArray.h"
#include "sortAlgorithms.h"
#include <fstream>
#include <iostream>

int intCounter(ifstream& file){
    file.seekg(0, ios_base::end);
    return file.tellg()/4;
}

void createFile(){
    ifstream firstRead("f") ;
    int i;
    int j=0;
    int quantityInt =0;
    //primer recorrido para ver la cantidad de enteros del archivo total
    while(firstRead >> i){
        quantityInt++;
        cout << i << endl;
    }
    int c[quantityInt];
    ifstream secondRead("f") ;
    while( secondRead >> i ) {
        c[j] = i;
        j++;
    }

    for(int k=0; k<quantityInt; k++){
        cout <<"c["<<k<<"] = "<< c[k] <<endl;
    }

    // write the integers in the array in binary form
    {
        ofstream binaryFile("binary36KB.bin", ios::binary);
        for (int k = 0; k < quantityInt; k++) {
            binaryFile.write(reinterpret_cast<const char *>(&c[k]), sizeof(c[k]));
        }}

}
int main() {
   //createFile();

   ifstream sortFile("binary36KB.bin", ios::binary);
    int numInts = intCounter(sortFile);
    int numInts1 = numInts;
    cout << "El archivo tiene " << numInts1 << " enteros " << endl;


    sortFile.seekg(0);
    pagedArray intsArray(numInts1, "binary36KB.bin");
    int v;
    int index = 0;
    while (sortFile.read(reinterpret_cast<char *>(&v), sizeof(v))) {
        intsArray[index] = v;
        index++;
    }

    //selectionSort(intsArray);
    //insertionSort(intsArray);
    quicksort(intsArray, 0, intsArray.size-1);


    {
        int v;
        ifstream infile("binary36KB.bin", ios::binary);
        infile.seekg(0);
        while (infile.read(reinterpret_cast<char *>(&v), sizeof(v))) {
            cout << v << ' ';
        }


        return 0;
    }}