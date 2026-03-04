#include <iostream>

//*****************************************
// CONSTRUCTORES
//*****************************************

template <typename T>
Pila<T>::Pila() : numElem(0), tope(nullptr)
{

}

//*****************************************

template <typename T>
Pila<T>::~Pila()
{
    Vaciar();
}

//*****************************************

template <typename T>
Pila<T>::Pila(const Pila& pila) : numElem(0), tope(nullptr)
{
    *this = pila;
}

//*****************************************

template <typename T>
Pila<T>& Pila<T>::operator=(const Pila& pila)
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

    }catch(const std::bad_alloc&){
        this->Vaciar();
        throw PilaNoMemoria();
    }

    return *this;
}

//*****************************************
// MÉTODOS DE CLASE
//*****************************************

template <typename T>
void Pila<T>::Agregar(T nuevoValor)
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

template <typename T>
void Pila<T>::Eliminar()
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

template <typename T>
T Pila<T>::ObtenerTope() const
{
    if(EstaVacia()){
        // PENDIENTE: Lanzar una excepcion propia de la pila
        throw PilaVacia();
    }

    return tope->valor;
}

//*****************************************

template <typename T>
int Pila<T>::ObtenerTam() const
{
    return numElem;
}

//*****************************************

template <typename T>
bool Pila<T>::EstaVacia() const
{
    if(numElem == 0){
        return true;
    }

    return false;
}

//*****************************************

template <typename T>
void Pila<T>::Vaciar()
{
    while(!EstaVacia()){
        Eliminar();
    }
}

//*****************************************

template <typename T>
void Pila<T>::Imprimir()
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

template <typename T>
Pila<T>::Elemento::Elemento(T v, Elemento *sig /*=nullptr*/) : valor(v), siguiente(sig){}

//***********************************
// Implementación de la clase PilaVacia
//***********************************

template <typename T>
Pila<T>::PilaVacia::PilaVacia() throw() {}

//***********************************

template <typename T>
Pila<T>::PilaNoMemoria::PilaNoMemoria() throw(){}

//***********************************

template <typename T>
const char *Pila<T>::PilaVacia::what() const throw()
{
    return "La pila se encuentra vac\241a.";
}

//***********************************

template <typename T>
const char *Pila<T>::PilaNoMemoria::what() const throw()
{
    return "No hay memoria disponible.";
}
