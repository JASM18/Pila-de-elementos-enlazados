#include <iostream>
#include "Pila.hpp"

using namespace std;

int main()
{
    try{

        cout << "Probando la excepci\242n de pila vac\241a:\n";

        Pila a;
        a.ObtenerTope();

        cout << "Probando la excepci\242n de memoria no disponible:\n";
        cout <<"no esa no";




    }catch(Pila::PilaVacia &errorVacio){
        cerr << "Error en la pila: " << errorVacio.what() << endl;
    }catch(...){
        cerr << "Ocurri\242 un error inesperado." << endl;
    }

    return 0;
}
