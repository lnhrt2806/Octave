//
// Created by jimena on 2/25/17.
//
#include "filesConverter.h"
using namespace std;
string bin (".bin");

/**
 * Function that creates the new file where all the numbers are sorted
 * @param txtfile binary file that will be translated
 * @param resultFile file that will have the sorted numbers
 */
void filesConverter::binaryToDecimal(string txtfile, string resultFile){
    ifstream infile(txtfile, ios::binary ) ;
    ofstream outfile(resultFile);
    int v;
    while(infile.read( reinterpret_cast<char*>(&v), sizeof(v) ))
        outfile << v << ' ' ;
    outfile << '\n' ;
}
/**
 * Function that will translate the numbers into a binary file to manage the sorting
 * @param txtFile original file from where the numbers will be copied
 * @return the name of the binary file
 */
string filesConverter::decimalToBinary(string txtFile) {
    ifstream firstRead(txtFile) ;
    int i; int j=0; int quantityInt =0;
    //primer recorrido para ver la cantidad de enteros del archivo total
    while(firstRead >> i){quantityInt++;}
    int c[quantityInt];
    ifstream secondRead(txtFile) ;
    while(secondRead >> i) {c[j] = i; j++;}
    // write the integers in the array in binary form
    ofstream binFile(txtFile+bin, ios::binary);
    for (int k = 0; k < quantityInt; k++) {
        binFile.write(reinterpret_cast<const char *>(&c[k]), sizeof(c[k]));
    }
    return txtFile+bin;
}


