//
// Created by jimena on 2/17/17.
//

#ifndef OCTAVE_SORTALGORITHMS_H
#define OCTAVE_SORTALGORITHMS_H

#include "pagedArray.h"
#include <fstream>



void quicksortAux(pagedArray array,int izq, int der ){
    int i, j, x , aux;
    i = izq;
    j = der;
    x = array[(izq + der) /2];
    do{
        while( (array[i] < x) && (j <= der) ){i++;}
        while( (x < array[j]) && (j > izq) ){j--;}
        if( i <= j ){
            aux = array[i];
            array[i] = array[j]; array[j] = aux;
            i++;  j--;
        }
    }while( i <= j );
    if( izq < j ) quicksortAux( array, izq, j );
    if( i < der ){quicksortAux( array, i, der );}
    array[-1];
}

void quicksort(pagedArray array){
    int izq = 0;
    int der = array.size-1;
    return quicksortAux(array, izq, der);
}

void insertionSort(pagedArray array){
    int i, j, aux;
    for(i=0; i<array.size; i++) {
        j=i;
        while( j>0 && array[j] < array[j-1]){
            aux = array[j];
            array[j] = array[j-1];
            array[j-1] = aux;
            j--;
        }
    }
    array[-1];
}


void selectionSort(pagedArray array) {
    int temp;
    for(int i=0; i<array.size; i++){
        for(int j=i+1; j<array.size; j++){
            if(array[i]>array[j]){
                temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    }
    array[-1];
}







#endif //OCTAVE_SORTALGORITHMS_H
