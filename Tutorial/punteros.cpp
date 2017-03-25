//
// Created by jimena on 2/15/17.
//

#include <iostream>
using namespace std;

int nu = 12;
int *puntero = &nu;
int array[5];
int *p;



struct mystruct{
    int a;
}myStruct, *punteroStruct;




int main10(){

    p = array;
    cout << *puntero << "\n\n\n" << endl;// * Transforma la direccion de memoria en el valor que esta guardado en esa direccion
    cout << "Direccion array[0] " << &array << endl;
    cout << "puntero " << p << endl;
    p++;//pasa a la siguiente direccion de memoria
    cout << "puntero " << p << "\n\n"<<endl;

    myStruct.a = 14;
    punteroStruct = &myStruct;

    cout << punteroStruct <<"\n"<<&myStruct.a<< endl; // -> Apunta a un atributo de la estructura

    return 0;
}
