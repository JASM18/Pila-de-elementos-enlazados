#include <iostream>
#include "Pila.hpp"

using namespace std;

int main()
{
    try{

        Pila a;

        a.Agregar(67);

        a.Imprimir();

    }catch(...){
    }

    return 0;
}
