//
// Created by jimena on 2/17/17.
//

#ifndef OCTAVE_SORTALGORITHMS_H
#define OCTAVE_SORTALGORITHMS_H

#include "pagedArray.h"
#include <fstream>


void quickSortAux(pagedArray array, int left, int right){
    int pivote = array[(left+right)/2];
    int i = left;
    int j = right;
    int aux;
    while(i<=j){
        while((array[i] < pivote) && (j <=right)){i++;}
        while((pivote<array[j]) && (j > left)){j--;}
        if(i <= j){
            aux = array[i];
            array[i] = array[j];
            array[j] =aux;
            i++;
            j--;
        }
    }
    if(left < j)quickSortAux(array, left, j);
    if(i < right)quickSortAux(array, i, right);
    cout <<"termino"<<endl;
    array[-1];
    return;
}


void quickSort(pagedArray array){
    int left = 0;
    int right = array.size -1;
    quickSortAux(array, left, right);
    array[-1];
    return;
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
}








#endif //OCTAVE_SORTALGORITHMS_H
