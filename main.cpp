#include <iostream>
#include "pagedArray.h"
#include "sortAlgorithms.h"
#include "filesConverter.h"
#include <string.h>
#include <fstream>
/**
 * Global variables that are needed for execution
 */
string entryFile;
string resultFile;
string f1("1KB"), f2("4KB"), f3("8KB"), f4("16KB"), f5("24KB"), f6("36KB");
string filesList[] = {f1, f2, f3, f4, f5, f6};
int algorithm;

/**
 * Function that will count the number of elements in the file to create the array
 * @param file that will be read
 * @return the number of ints in the file
 */
int intCounter(ifstream& file){
    file.seekg(0, ios_base::end);
    return file.tellg()/4;
}
/**
 * Function that creates a binary file to make easier the management of the sorting
 * Creates the paged Array and validates which sorting algorithm will be used
 * @param file that will be read and tranlated into binary
 */
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
            quicksort(intsArray);break;
        case 2:
            selectionSort(intsArray);break;
        case 3:
            insertionSort(intsArray);break;
        default:
            cout <<"Ninguno";
    }
    filesConverter::binaryToDecimal(binFile, resultFile);
    remove(binFile.c_str());
}
/**
 * Function that checks if the entry file is a valid one
 * @param fileToCheck name of the file to check
 * @return true if is a valid name, otherwise false
 */
bool checkFile(string fileToCheck){
    bool result = false;
    for(int i=0; i<6; i++){
        if(filesList[i].compare(fileToCheck)==0){
            result = true; break;
        }
    }
    return result;
}

/**
 * Main function that specifies the entrys of the user and defines the global variables and begins the execution
 * @param argc number of terminal arguments that will be included
 * @param argv array of arguments that are introduced by the user
 * @return
 */
int main(int argc, char* argv[]) {
    if(argc == 7) {
        if ((strcmp("-i", argv[1]) ==0 && strcmp("-a", argv[3]) ==0 && strcmp("-o", argv[5])==0)){
            string fileName(argv[2]);
            string sortType(argv[4]);
            string fileResult(argv[6]);
            if(fileName.compare(fileResult) !=0){
                if(checkFile(fileName)) {
                    entryFile = fileName;
                    resultFile = fileResult;
                    if (sortType.compare("QS") == 0 || sortType.compare("SS") == 0 || sortType.compare("IS") == 0) {
                        if (sortType.compare("QS") == 0) {
                            cout << "se usara quicksort";
                            algorithm = 1;
                        }
                        else if (sortType.compare("SS") == 0) {
                            cout << "se usara selectionsort";
                            algorithm = 2;
                        }
                        else if (sortType.compare("IS") == 0) {
                            cout << "se usara insertionsort";
                            algorithm = 3;
                        }
                    } else cout << "No se reconoce el tipo de ordenamiento";
                }else cout << "No se encontro el archivo";
            }else{cout <<"El archivo resultado no puede ser igual al de entrada";}
        }else { cout << "No se reconoce el comando" << endl;}
    }else{
        cout <<"Cantidad de argumentos invalidos. Debe ser ./paged-sort -i <archivo> -a {QS|IS|SS} -o <archivo_resultado>"; }
    cout<<endl;
    createPagedArray(entryFile);
    cout << "Revise en la carpeta su archivo resultado"<<endl;
            return 0;
    }