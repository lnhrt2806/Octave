//
// Created by jimena on 2/17/17.
//

#include <iostream>
using namespace std;

class cuentas{
public:
    //Se puede definir un metodo desde adentro
    int sumaDos(int num){
        resultado = num + 2;
        return resultado;
    }
    int sumaTres(int num);

private:
    int resultado;

};

//Se puede definir un metodo desde afuera
int cuentas::sumaTres(int num) {
    resultado = num + 3;
    return resultado;
}


int main(){
    cuentas cuenta;
    cout << cuenta.sumaDos(5) << "\n" <<cuenta.sumaTres(5) <<endl;

    return 0;
}