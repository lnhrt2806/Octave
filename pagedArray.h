//
// Created by jimena on 2/17/17.
//

#ifndef OCTAVE_PAGEDARRAY_H
#define OCTAVE_PAGEDARRAY_H

#include <iostream>
using namespace std;



class pagedArray{
private:
    int size;
    int a[10];

public:
    int& operator[](int x){
        return a[x];
    }
    void printArray(){
        for(int i = 0; i < 10; i++){
            cout << "array[" << i << "] = " << a[i] << "\n" << endl;
        }
    }
};






#endif //OCTAVE_PAGEDARRAY_H