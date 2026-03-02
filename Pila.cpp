#include <iostream>

#include "Pila.hpp"

//*****************************************
// CONSTRUCTORES
//*****************************************

Pila::Pila() : numElem(0), tope(nullptr)
{

}

//*****************************************

Pila::~Pila()
{
    Vaciar();
}

//*****************************************

Pila::Pila(const Pila& pila) : numElem(0), tope(nullptr)
{
    *this = pila;
}

//*****************************************

Pila& Pila::operator=(const Pila& pila)
{
    if (this == &pila) return *this;

    this->Vaciar();

    Pila pilaAux;
    Elemento *visitado = pila.tope;

    while(visitado != nullptr){
        pilaAux.Agregar(visitado->valor);
        visitado = visitado->siguiente;
    }

    visitado = pilaAux.tope;
    while(visitado != nullptr){
        this->Agregar(visitado->valor);
        visitado = visitado->siguiente;
    }

    return *this;
}

//*****************************************
// MÉTODOS DE CLASE
//*****************************************

void Pila::Agregar(int nuevoValor)
{
    try{
        Elemento *nuevo = new Elemento; // Vamos a crear un nuevo elemento
        nuevo->valor = nuevoValor;
        nuevo->siguiente = tope;
        tope = nuevo;
        ++numElem;

    }catch(std::bad_alloc&){
        // PENDIENTE: Lanzar una excepcion propia de la
        throw PilaNoMemoria();
    }
}

//*****************************************

void Pila::Eliminar()
{
    if(EstaVacia()){
        // PENDIENTE: Lanzar una excepcion propia de la pila
        throw PilaVacia();
    }
    Elemento *porBorrar = tope;
    tope = tope->siguiente;
    delete porBorrar;
    --numElem;
}

//*****************************************

int Pila::ObtenerTope() const
{
    if(EstaVacia()){
        // PENDIENTE: Lanzar una excepcion propia de la pila
        throw PilaVacia();
    }

    return tope->valor;
}

//*****************************************

int Pila::ObtenerTam() const
{
    return numElem;
}

//*****************************************

bool Pila::EstaVacia() const
{
    if(numElem == 0){
        return true;
    }

    return false;


//    if(tope == nullptr){
//        return true;
//    }
//
//    return false;
}

//*****************************************

void Pila::Vaciar()
{
    while(!EstaVacia()){
        Eliminar();
    }
}

//*****************************************

void Pila::Imprimir()
{
    Elemento *visitado = tope;
    std::cout << "Tope-> ";

    while(visitado != nullptr){
        std::cout << visitado->valor << ", ";
        visitado = visitado->siguiente;
    }

    if(!EstaVacia()) std::cout << "\b\b <- Inicio";
}

//***********************************
// Implementación de la clase PilaVacia
//***********************************

Pila::PilaVacia::PilaVacia() throw() {}

//***********************************

Pila::PilaNoMemoria::PilaNoMemoria() throw(){}

//***********************************

const char *Pila::PilaVacia::what() const throw()
{
    return "La pila se encuentra vac\241a.";
}


const char *Pila::PilaNoMemoria::what() const throw()
{
    return "No hay memoria disponible.";
}
