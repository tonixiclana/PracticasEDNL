#ifndef ABIN_VEC1_H
#define ABIN_VEC1_H
#include <cassert>
/*
    * Implementaci�n de �rbol binario con vector de posiciones relativas
*/
template <typename T> class Abin {
public:

    typedef int nodo; // �ndice del vector
    // entre 0 y maxNodos-1
    static const nodo NODO_NULO;
    explicit Abin(size_t maxNodos, const T& e_nulo = T()); //ctor
    void insertarRaizB(const T& e);
    void insertarHijoIzqdoB(nodo n, const T& e);
    void insertarHijoDrchoB(nodo n, const T& e);
    void eliminarHijoIzqdoB(nodo n);
    void eliminarHijoDrchoB(nodo n);
    ~Abin(); // destructor
    bool arbolVacioB() const;
    void eliminarRaizB();
    const T& elemento(nodo n) const; // acceso a elto, lectura
    T& elemento(nodo n); // acceso a elto, lectura/escritura
    nodo raizB() const;
    nodo padreB(nodo n) const;
    nodo hijoIzqdoB(nodo n) const;
    nodo hijoDrchoB(nodo n) const;
    Abin(const Abin<T>& a); // ctor. de copia
    Abin<T>& operator =(const Abin<T>& a); //asignaci�n de �rboles

private:
    T* nodos; // vector de nodos
    int maxNodos; // tama�o del vector
    T ELTO_NULO; // marca celdas vac�as
};


/* Definici�n del nodo nulo */
template <typename T>
const typename Abin<T>::nodo Abin<T>::NODO_NULO(-1);

//Constructor
template <typename T>
Abin<T>::Abin(size_t maxNodos, const T& e_nulo) :
    nodos(new T[maxNodos]),
    maxNodos(maxNodos),
    ELTO_NULO(e_nulo)
{
    // marcar todas las celdas libres
    for (nodo n = 0; n <= maxNodos-1; n++)
    nodos[n] = ELTO_NULO;
}


template <typename T>
inline void Abin<T>::insertarRaizB(const T& e)
{
    assert(nodos[0] == ELTO_NULO); // �rbol vac�o
    nodos[0] = e;
}


template <typename T> inline
void Abin<T>::insertarHijoIzqdoB(Abin<T>::nodo n,const T& e)
{
    assert(n >= 0 && n < maxNodos); // nodo v�lido
    assert(nodos[n] != ELTO_NULO); // nodo del �rbol
    assert(2*n+1 < maxNodos); // hijo izqdo. cabe en el �rbol
    assert(nodos[2*n+1] == ELTO_NULO); // n no tiene hijo izqdo.
    nodos[2*n+1] = e;
}


template <typename T> inline
void Abin<T>::insertarHijoDrchoB(Abin<T>::nodo n,const T& e)
{
    assert(n >= 0 && n < maxNodos); // nodo v�lido
    assert(nodos[n] != ELTO_NULO); // nodo del �rbol
    assert(2*n+2 < maxNodos); // hijo drcho. cabe en el �rbol
    assert(nodos[2*n+2] == ELTO_NULO); // n no tiene hijo drcho.
    nodos[2*n+2] = e;
}
template <typename T> inline
void Abin<T>::eliminarHijoIzqdoB(Abin<T>::nodo n)
{
    assert(n >= 0 && n < maxNodos); // nodo v�lido
    assert(nodos[n] != ELTO_NULO); // nodo del �rbol
    assert(2*n+1 < maxNodos); // hijo izqdo. cabe en el �rbol
    assert(nodos[2*n+1] != ELTO_NULO); // n tiene hijo izqdo.

    if (4*n+4 < maxNodos) // caben los hijos del hijo izqdo. de n
        assert(nodos[4*n+3] == ELTO_NULO && // hijo izqdo. de
        nodos[4*n+4] == ELTO_NULO); // n es hoja
    else if (4*n+3 < maxNodos) //s�lo cabe h. izq. de h. izq. de n
        assert(nodos[4*n+3] == ELTO_NULO); //hijo izq. de n es hoja

    nodos[2*n+1] = ELTO_NULO;
}

template <typename T> inline
void Abin<T>::eliminarHijoDrchoB(Abin<T>::nodo n)
{
    assert(n >= 0 && n < maxNodos); // nodo v�lido
    assert(nodos[n] != ELTO_NULO); // nodo del �rbol
    assert(2*n+2 < maxNodos); // hijo drcho. cabe en el �rbol
    assert(nodos[2*n+2] != ELTO_NULO); // n tiene hijo drcho.

    if (4*n+6 < maxNodos) // caben los hijos del hijo drcho. de n
        assert(nodos[4*n+5] == ELTO_NULO && // hijo drcho. de
        nodos[4*n+6] == ELTO_NULO); // n es hoja
    else if (4*n+5 < maxNodos) //s�lo cabe h. izq. de h. drch de n
        assert(nodos[4*n+5] == ELTO_NULO); //hijo drch de n es hoja

    nodos[2*n+2] = ELTO_NULO;
}


template <typename T>
inline void Abin<T>::eliminarRaizB()
{
    assert(nodos[0] != ELTO_NULO); // �rbol no vac�o
    assert(nodos[1] == ELTO_NULO &&
    nodos[2] == ELTO_NULO); // la ra�z es hoja
    nodos[0] = ELTO_NULO;
}


template <typename T>
inline Abin<T>::~Abin()
{
    delete[] nodos;
}


template <typename T>
inline bool Abin<T>::arbolVacioB() const
{
    return (nodos[0] == ELTO_NULO);
}

template <typename T>
inline const T& Abin<T>::elemento(Abin<T>::nodo n) const
{
    assert(n >= 0 && n < maxNodos); // nodo v�lido
    assert(nodos[n] != ELTO_NULO); // nodo del �rbol
    return nodos[n];
}


template <typename T>
inline T& Abin<T>::elemento(Abin<T>::nodo n)
{
    assert(n >= 0 && n < maxNodos); // nodo v�lido
    assert(nodos[n] != ELTO_NULO); // nodo del �rbol
    return nodos[n];
}


template <typename T>
inline typename Abin<T>::nodo Abin<T>::raizB() const
{
    return (nodos[0] == ELTO_NULO) ? NODO_NULO : 0;
}


template <typename T> inline
typename Abin<T>::nodo Abin<T>::padreB(Abin<T>::nodo n) const
{
    assert(n >= 0 && n < maxNodos); // nodo v�lido
    assert(nodos[n] != ELTO_NULO); // nodo del �rbol
    return (n == 0) ? NODO_NULO : (n-1)/2;
}


template <typename T> inline
typename Abin<T>::nodo Abin<T>::hijoIzqdoB(Abin<T>::nodo n) const
{
    assert(n >= 0 && n < maxNodos); // nodo v�lido
    assert(nodos[n] != ELTO_NULO); // nodo del �rbol
    return (2*n+1 >= maxNodos || nodos[2*n+1] == ELTO_NULO) ?
    NODO_NULO : 2*n+1;
}

template <typename T> inline
typename Abin<T>::nodo Abin<T>::hijoDrchoB(Abin<T>::nodo n) const
{
    assert(n >= 0 && n < maxNodos); // nodo v�lido
    assert(nodos[n] != ELTO_NULO); // nodo del �rbol
    return (2*n+2 >= maxNodos || nodos[2*n+2] == ELTO_NULO) ?
    NODO_NULO : 2*n+2;
}


template <typename T>
Abin<T>::Abin(const Abin<T>& a) :
    nodos(new T[a.maxNodos]),
    maxNodos(a.maxNodos),
    ELTO_NULO(a.ELTO_NULO)
{
    // copiar el vector
    for (nodo n = 0; n <= maxNodos-1; n++)
    nodos[n] = a.nodos[n];
}

template <typename T>
Abin<T>& Abin<T>::operator =(const Abin<T>& a)
{
    if (this != &a) // evitar autoasignaci�n
    {
        // Destruir el vector y crear uno nuevo si es necesario
        if (maxNodos != a.maxNodos)
        {
            delete[] nodos;
            maxNodos = a.maxNodos;
            nodos = new T[maxNodos];
        }

        ELTO_NULO = a.ELTO_NULO;

        // Copiar el vector
        for (nodo n = 0; n <= maxNodos-1; n++)
        nodos[n] = a.nodos[n];
    }

return *this;
}
#endif // ABIN_VEC1_H
