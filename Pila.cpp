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

    if (this == &pila) return *this; // Evita la auto-asignación (Pila A = Pila A)

    this->Vaciar();

    if(pila.EstaVacia()){
        return *this;
    }

    try{
        // Se va a crear el elemento de tope de forma manual (paso inicial)
        // visitaPila va a ser un puntero que recorre todos los elementos de &pila
        // visitaThis va a ser un puntero que recorre todos los elementos de *this
        // Ejemplo: Pila a = b -----> en este contexto, *this es la pila a y &pila es la pila b

        Elemento *visitaPila = pila.tope; // Puntero auxuliar que recorre &pila
        this->tope = new Elemento(visitaPila->valor, nullptr); // Creamos el nuevo tope de *this

        this->numElem = 1;
        // Hasta ahora solamente hemos copiado el elemento tope

        Elemento *visitaThis = this->tope; // Puntero que apunta al tope de la pila *this
        visitaPila = visitaPila->siguiente; // Visitamos el siguiente elemento de &pila

        while(visitaPila != nullptr){ // Se ejecuta hasta que el puntero sea nulo, osea hasta que recorremos toda la pila &pila

            // Creamos el siguiente elemento de *this
            visitaThis->siguiente = new Elemento(visitaPila->valor, nullptr);

            // Bajamos el puntero de *this
            visitaThis = visitaThis->siguiente;
            this->numElem++;

            // Bajamos el puntero de &pila
            visitaPila = visitaPila->siguiente;

        }

        /*
        Elemento **aux = &tope;
        Elemento *visitado = p.tope;
        while(visitado !=  nullptr){
            *aux = new Elemento(visitado->valor);
            visitado = visitado->siguiente;
            aux = *(*aux)->siguiente;
        }
        */  <

    }catch(const std::bad_alloc&){
        this->Vaciar();
        throw PilaNoMemoria();
    }

    /*

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
    */
    return *this;
}

//*****************************************
// MÉTODOS DE CLASE
//*****************************************

void Pila::Agregar(int nuevoValor)
{
    try{
        Elemento *nuevo = new Elemento(nuevoValor, tope); // Vamos a crear un nuevo elemento
        //nuevo->valor = nuevoValor;
        //nuevo->siguElementoiente = tope;
        tope = nuevo;
        ++numElem;

    }catch(std::bad_alloc&){
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
// Métodos de la estructura Elemento
//***********************************

Pila::Elemento::Elemento(int v, Elemento *sig /*=nullptr*/) : valor(v), siguiente(sig){}

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
