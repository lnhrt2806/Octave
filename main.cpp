#include <iostream>
#include "pagedArray.h"
#include "sortAlgorithms.h"
#include <fstream>
#include <iostream>
#include "binaryConverter.h"

char* file1 = "binaryfCopy.bin";

using namespace std;

int c[] = {25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};

int intCounter(ifstream& file){
    file.seekg(0, ios_base::end);
    return file.tellg()/4;
}

void insertion_sort (int arr[], int length){
    int j, temp;

    for (int i = 0; i < length; i++){
        j = i;

        while (j > 0 && arr[j] < arr[j-1]){
            temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
    }
}
void selectSort(int arr[], int n)
{
//pos_min is short for position of min
    int pos_min,temp;

    for (int i=0; i < n-1; i++)
    {
        pos_min = i;//set pos_min to the current index of array

        for (int j=i+1; j < n; j++)
        {

            if (arr[j] < arr[pos_min])
                pos_min=j;
            //pos_min will keep track of the index that min is in, this is needed when a swap happens
        }

        //if pos_min no longer equals i than a smaller value must have been found, so a swap must occur
        if (pos_min != i)
        {
            temp = arr[i];
            arr[i] = arr[pos_min];
            arr[pos_min] = temp;
        }
    }
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
        ofstream binaryFile("binaryf15.bin", ios::binary);
        for (int k = 0; k < quantityInt; k++) {
            binaryFile.write(reinterpret_cast<const char *>(&c[k]), sizeof(c[k]));
        }}
    {
        ifstream infile("binaryf15.bin", ios::binary);
        infile.seekg(0);
        int v;
        while (infile.read(reinterpret_cast<char *>(&v), sizeof(v))) {
            cout << v << ' ';
        }
    }
}




int main() {
   //createFile();
   ifstream sortFile(file1, ios::binary);
    int numInts = intCounter(sortFile);
    int numInts1 = numInts;
    cout << "El archivo tiene " << numInts1 << " enteros " << endl;


    sortFile.seekg(0);
    pagedArray intsArray(numInts1, file1);
    int v;
    int index = 0;
    while (sortFile.read(reinterpret_cast<char *>(&v), sizeof(v))) {
        intsArray[index] = v;
        index++;
    }


    // for(int i=0; i<25; i++){
    //   intsArray[i] = i+1;
    //}
    //intsArray.printArray();
    //quickSort(intsArray);
    //cout <<19/2<<"ejej";
    //insertionSort(intsArray);

    {
        int v;
    ifstream infile("binaryfCopy.bin", ios::binary);
        infile.seekg(0);
    while (infile.read(reinterpret_cast<char *>(&v), sizeof(v))){
        cout << v << ' ';}

}














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








    return 0;}



