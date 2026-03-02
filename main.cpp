#include <iostream>
#include "Pila.hpp"

using namespace std;

int main()
{
    try{

        Pila a;

        a.ObtenerTope();

    }catch(Pila::PilaVacia &errorVacio){
        cerr << "Error en la pila: " << errorVacio.what() << endl;
    }catch(...){
        cerr << "Ocurri\242 un error inesperado." << endl;
    }

    return 0;
}
