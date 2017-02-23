//
// Created by jimena on 2/17/17.
//

#ifndef OCTAVE_SORTALGORITHMS_H
#define OCTAVE_SORTALGORITHMS_H

#include "pagedArray.h"
#include <fstream>

void quicksort(pagedArray array,int izq, int der ) {
    int i, j, x , aux;
    i = izq;
    j = der;
    x = array[(izq + der) /2];
    do{
        while( (array[i] < x) && (j <= der) )
        {
            i++;
        }

        while( (x < array[j]) && (j > izq) )
        {
            j--;
        }

        if( i <= j )
        {
            aux = array[i];
            array[i] = array[j]; array[j] = aux;
            i++;  j--;
        }

    }while( i <= j );

    if( izq < j )
        quicksort( array, izq, j );
    if( i < der ){
        quicksort( array, i, der );}
    array[-1];
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

void selectionSort(pagedArray array){
    int min,temp;
    for (int i=0; i < array.size-1; i++)
    {
        min = i;//set pos_min to the current index of array

        for (int j=i+1; j < array.size; j++)
        {

            if (array[j] < array[min])
                min=j;
            //pos_min will keep track of the index that min is in, this is needed when a swap happens
        }

        //if pos_min no longer equals i than a smaller value must have been found, so a swap must occur
        if (min != i)
        {
            temp = array[i];
            array[i] = array[min];
            array[min] = temp;
        }
    }
    array[-1];
}








#endif //OCTAVE_SORTALGORITHMS_H
