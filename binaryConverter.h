//
// Created by jimena on 2/18/17.
//

#ifndef OCTAVE_BINARYCONVERTER_H
#define OCTAVE_BINARYCONVERTER_H
#include <iostream>
#include <fstream>
using namespace std;






void binaryConversion(){
    cout << "f contains: " << ifstream("f").rdbuf() ;

  /*  ifstream firstRead("f") ;
    int i;
    int j=0;
    int quantityInt =0;
    //primer recorrido para ver la cantidad de enteros del archivo total
    while(firstRead >> i){
        quantityInt++;
        cout << i << endl;
    }
    int c[quantityInt];
    cout << "sd"<< endl;
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
        ofstream binaryFile("binaryf.bin", ios::binary);
        for (int k = 0; k < quantityInt; k++) {
            binaryFile.write(reinterpret_cast<const char *>(&c[k]), sizeof(c[k]));
        }
      /*  //Sobreescribe los bytes en una posicion especifica
        cout << "pos" <<binaryFile.tellp()<< endl;
        binaryFile.write(reinterpret_cast<const char *>(&c[5]), sizeof(c[5]));
        cout << "pos" <<binaryFile.tellp()<< endl;
        binaryFile.seekp(4);
        cout << "pos" <<binaryFile.tellp()<< endl;
        binaryFile.write(reinterpret_cast<const char *>(&c[5]), sizeof(c[5]));
    }*/


    // obtiene los datos del archivo binario y los traduce a decimal
    {
        ifstream infile("binaryf.bin", ios::binary ) ;
        ofstream outfile("f2") ;
        int v ;
        while( infile.read( reinterpret_cast<char*>(&v), sizeof(v) ))
            outfile << v << ' ' ;
        outfile << '\n' ;
    }
    cout << "f2 contains: " << ifstream("f2").rdbuf() ;

    ifstream firstRead("f2") ;
      int i;
      int j=0;
      int quantityInt =0;
      //primer recorrido para ver la cantidad de enteros del archivo total
      while(firstRead >> i){
          quantityInt++;
          cout << i << endl;
      }
      int c[quantityInt];
      cout << "sd"<< endl;
      ifstream toCopyInBin("f") ;
      while( toCopyInBin >> i ) {
          c[j] = i;
          j++;
      }

      for(int k=0; k<quantityInt; k++){
          cout <<"c["<<k<<"] = "<< c[k] <<endl;
      }

      // write the integers in the array in binary form
    {
        ofstream binaryFileCopy("binaryfCopy.bin", ios::binary);
        for (int k = 0; k < quantityInt; k++) {
            binaryFileCopy.write(reinterpret_cast<const char *>(&c[k]), sizeof(c[k]));
        }
        cout << "succes" << endl;
    }
      return;
  }



  #endif //OCTAVE_BINARYCONVERTER_H
