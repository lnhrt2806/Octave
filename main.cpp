#include <iostream>
#include "pagedArray.h"
#include "sortAlgorithms.h"
#include "filesConverter.h"
#include <string.h>
#include <fstream>
#include <iostream>

string entryFile;
string resultFile;
int algorithm;


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
    switch (algorithm){
        case 1:
            quicksort(intsArray);
        case 2:
            selectionSort(intsArray);
        case 3:
            insertionSort(intsArray);
        default:
            cout <<"Ninguno";
    }
    //quicksort(intsArray);
    //insertionSort(intsArray);
    //selectionSort(intsArray);


    filesConverter::binaryToDecimal(binFile, resultFile);
    remove(binFile.c_str());
}


int main(int argc, char* argv[]) {
    if(argc == 7) {
        if ((strcmp("-i", argv[1]) ==0 && strcmp("-a", argv[3]) ==0 && strcmp("-o", argv[5])==0)){
            string fileName(argv[2]);
            string sortType(argv[4]);
            string fileResult(argv[6]);
            if(fileName.compare(fileResult) !=0) {
                entryFile = fileName;
                resultFile = fileResult;
                if (sortType.compare("QS") == 0 || sortType.compare("SS") == 0 || sortType.compare("IS") == 0) {
                    if (sortType.compare("QS") == 0){cout << "se usara quicksort"; algorithm = 1;}
                    else if (sortType.compare("SS") == 0){cout << "se usara selectionsort"; algorithm = 2;}
                    else if (sortType.compare("IS") == 0){cout << "se usara insertionsort"; algorithm = 3;}
                } else cout << "No se reconoce el tipo de ordenamiento";
            }else{cout <<"El archivo resultado no puede ser igual al de entrada";}
        }else { cout << "No se reconoce el comando" << endl;}
    }else{
        cout <<"Cantidad de argumentos invalidos. Debe ser ./paged-sort -i <archivo> -a {QS|IS|SS} -o <archivo_resultado>"; }
    cout<<endl;
    createPagedArray(entryFile);

 /* createPagedArray("1KB");
    createPagedArray("4KB");
    createPagedArray("8KB");
    createPagedArray("12KB");createPagedArray("24KB");createPagedArray("36KB");*/


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