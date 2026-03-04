#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Pila.hpp"

using namespace std;

int main()
{
    try{
        srand(time(nullptr));

        Pila<int> p;
        int valor, n = 10+rand()%11;

        cout << "Agregando " << n << " valores a la pila..." << endl;

        for(int i = 1 ; i <= n ; ++i){
            valor = 1 + rand()%100;
            cout << "\nAgregando " << valor << " a la pila p..." << endl;
            p.Agregar(valor);
            p.Imprimir();
        }

        n = 5 + rand()%6;

        cout << "\n\nLa pila tiene " << p.ObtenerTam() << " elementos" << endl;

        cout << "\n\nEliminando " << n << " valores de la pila p..." << endl;
        for(int i = 1 ; i <= n ; ++i){
            cout << "\nEliminando el valor " << p.ObtenerTope() << " de la pila p\n";
            p.Eliminar();
            p.Imprimir();
        }
        cout << "\n\nLa pila tiene " << p.ObtenerTam() << " elementos" << endl;

        cout << "\nLa pila" << (p.EstaVacia()? " " : " no ") << "est\240 vac\241a" << endl;

        //cout << "\nVaciando la pila..." << endl;
        //p.Vaciar();
        //cout << "\nLa pila" << (p.EstaVacia()? " " : " no ") << "est\240 vac\241a" << endl;


        Pila<int> q = p;

        q.Agregar(10);
        q.Agregar(-5);
        q.Agregar(0);

        cout << "\nPila q...";
        q.Imprimir();

        cout << "\nCopiando la pila p en q..." << endl;
        q = p;

        cout << "\nPila p:";
        p.Imprimir();
        cout << "\nPila q:";
        q.Imprimir();

        cout << "\n\nVaciando la pila p..." << endl;
        p.Vaciar();

        cout << "\nLa pila" << (p.EstaVacia()? " " : " no ") << "est\240 vac\241a" << endl;

        cout << "\nPila p: ";
        p.Imprimir();
        cout << "\nPila q: ";
        q.Imprimir();



    }catch(const char *msn){

    }catch(Pila<int>::PilaVacia &errorVacio){
        cerr << "Error en la pila: " << errorVacio.what() << endl;
    }catch(...){
        cerr << "Ocurri\242 un error inesperado." << endl;
    }

    return 0;
}
