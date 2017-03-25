//
// Created by jimena on 2/15/17.
//

#include <iostream>
namespace ciudad{
    int calle;
}
namespace pueblito{
    int calle = 10;
}

using namespace ciudad;
using namespace std;


int main9(){
    calle = 12;
    cout << pueblito::calle << "\n" << calle <<endl;

    return 0;
}