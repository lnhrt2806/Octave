//
// Created by jimena on 2/18/17.
//

#ifndef OCTAVE_BINARYCONVERTER_H
#define OCTAVE_BINARYCONVERTER_H
#include <iostream>
#include <fstream>
#include "pagedArray.h"
using namespace std;

class filesConverter{
public:
    static string decimalToBinary(string txtFile);
    static void binaryToDecimal(string file, string resultFile);

};

#endif //OCTAVE_BINARYCONVERTER_H
