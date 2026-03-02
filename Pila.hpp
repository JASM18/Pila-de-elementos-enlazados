#ifndef PILA_HPP
#define PILA_HPP

#include <exception>

class Pila {
public:
    /** Default constructor */
    Pila();

    /** Default destructor */
    ~Pila();

    /** Copy constructor
     *  \param pila Object to copy from
     */
    Pila(const Pila& pila);

    /** Assignment operator
     *  \param pila Object to assign from
     *  \return A reference to this
     */
    Pila& operator=(const Pila& pila);

    /** \brief Agrega un elemento al tope de la pila
     *
     * \param valor int
     * \return void
     *
     */
    void Agregar(int valor);

    /** \brief Elimina el tope de la pila
     *
     * \return void
     *
     */
    void Eliminar();

    /** \brief Obtiene el valor del tope de la pila
     *
     * \return int
     *
     */
    int ObtenerTope() const;

    /** \brief Regresa la cantidad de elementos que hay en la pila
     *
     * \return int
     *
     */
    int ObtenerTam() const;

    /** \brief Nos dice si la pila esta vacia o no
     *
     * \return bool
     *
     */
    bool EstaVacia() const;

    /** \brief Vacia toda la pila, pone el tope en -1
     *
     * \return void
     *
     */
    void Vaciar();

    /** \brief Imprime la pila
     *
     * \return void
     *
     */
    void Imprimir();

    class PilaVacia : public std::exception {
    public:
        /** \brief Constructor por defecto de la excepci&oacute;n PilaVacia.
         */
        PilaVacia() throw();

        /** \brief Devuelve una descripci&oacute;n del error al intentar operar con una pila vac&iacute;a.
         *
         * \return Cadena de caracteres con el mensaje de error.
         */
        virtual const char *what() const throw();
    };

    class PilaNoMemoria : public std::exception {
    public:
        /** \brief Constructor por defecto de la excepci&oacute;n PilaVacia.
         */
        PilaNoMemoria() throw();

        /** \brief Devuelve una descripci&oacute;n del error al intentar operar con una pila vac&iacute;a.
         *
         * \return Cadena de caracteres con el mensaje de error.
         */
        virtual const char *what() const throw();
    };

private:

    int numElem; //!< Member variable "numElem"
    struct Elemento{
        int valor;
        Elemento *siguiente;
    } *tope; //!< Member variable "*tope";
};

#endif // PILA_HPP
