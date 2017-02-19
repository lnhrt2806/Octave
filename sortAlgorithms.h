//
// Created by jimena on 2/17/17.
//

#ifndef OCTAVE_SORTALGORITHMS_H
#define OCTAVE_SORTALGORITHMS_H

#include "pagedArray.h"
#include <fstream>
#include <iterator>

template<typename T, std::size_t N>
constexpr std::size_t size(T(&)[N]) { return N; }



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
    return;
}


void quickSort(pagedArray array){
    int left = 0;
    int right = array.size -1;
    return quickSortAux(array, left, right);
}








#endif //OCTAVE_SORTALGORITHMS_H
