#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Pila.hpp"

using namespace std;

int main()
{
    try{
        srand(time(nullptr));

        Pila a;
        int valor, n = 10+rand()%11;

        cout << "Agregando " << n << " valores a la pila..." << endl;

        for(int i = 1 ; i <= n ; ++i){
            valor = 1 + rand()%100;
            cout << "Agregando " << valor << " a la pila p..." << endl;
            a.Agregar(valor);
            a.Imprimir();
        }

        n = 5 + rand()%6;

        cout << "Eliminando " << n << " valores de la pila p..." << endl;
        for(int i = 1 ; i <= n ; ++i){
            cout << "\nEliminando un valor de la pila p\n";
            a.Eliminar();
            a.Imprimir();
        }

    }catch(const char *msn){

    }catch(Pila::PilaVacia &errorVacio){
        cerr << "Error en la pila: " << errorVacio.what() << endl;
    }catch(...){
        cerr << "Ocurri\242 un error inesperado." << endl;
    }

    return 0;
}
