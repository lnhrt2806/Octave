//
// Created by jimena on 2/
#include <iostream>
using namespace std;

int main8(){

    struct Personaje{
        int edad;
        int tel;
        Personaje(){edad = 0; tel =0;}
        int verTel() {return tel;}

    }
            Jimena, Tavo, Daniel;
    Jimena.edad = 17;
    Jimena.tel = 4684648;

    Tavo.tel = Jimena.tel;
    Tavo.edad = 20;

    cout << Jimena.tel <<"\n"<<Tavo.tel << Daniel.verTel()<< endl;


    return 0;

}
