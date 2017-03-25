//
// Created by jimena on 2/14/17.
//

#include <iostream>
using namespace std;

int main5(){
    char c;
    cout << "Escribe una letra" << endl;
    cin >> c; //Para guardar una entrada del usuario en una variable

    switch(c){
        case 'a':
        case 'b':
        case 'i':
        case 'o':
        case 'u':
            cout << c<<" Es una vocal\n\n" << endl;
            break;
        default:
            cout << "Es una consonante" << endl;
    }
    return 0;

}

