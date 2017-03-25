//
// Created by jimena on 2/14/17.
/*Define hace una sustitucion
suma (a,b) es el identificador, cuando se escribe eso se hace esto -> multiplicar(a,b) que es la secuencia*/

#define sumar(a,b) a+b
#define multiplicar(a,b) a*b

#include <iostream>
using namespace std;
int n1 = 2;
int n2 = 4;
int suma1;

//Funciones deben declararse antes de ser llamadas
int multi(int s, int d){
    return s*d;
}

int main7(){
    suma1 = sumar(n1, n2);
    cout << suma1 << "\n\n" << multi(4,5) << endl;

    return 0;
}

