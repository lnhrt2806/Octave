#include <iostream>
#include "pagedArray.h"
#include "sortAlgorithms.h"
#include <fstream>
#include <iostream>
#include "binaryConverter.h"

char* file1 = "binaryfCopy.bin";

using namespace std;
//int c[] = {1,2,3,4,5};

int intCounter(ifstream& file){
    file.seekg(0, ios_base::end);
    return file.tellg()/4;
}

int main(){
    ifstream sortFile(file1, ios::binary);
    int numInts = intCounter(sortFile);
    int numInts1 = numInts;
    cout << "El archivo tiene "<< numInts1<< " enteros "<<endl;


    sortFile.seekg(0);
    pagedArray intsArray(numInts1, file1);
    int v ;
    int index=0;
    while( sortFile.read( reinterpret_cast<char*>(&v), sizeof(v) )){
        intsArray[index] = v;
        index++;
    }


   // for(int i=0; i<25; i++){
     //   intsArray[i] = i+1;
    //}
    intsArray.printArray();
    quickSort(intsArray);












    /*for(int i=25; i>0; i--){
        cout << i << " ";
    }*/
/*
    pagedArray array;
    for(int i =0; i<20; i++){
        array[i] = i*2;
    }
    array.printArray();
    quickSort(c);
*/
   // binaryConversion();










    return 0;
    }

