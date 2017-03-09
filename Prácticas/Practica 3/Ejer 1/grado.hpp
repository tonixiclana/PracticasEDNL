#include <algorithm>


template <typename T>
size_t gradoAgen(const Agen<T>& A)
{
    if(A.arbolVacio())          //comprobar que es arbol vacio
        return 0;
    else
        return gradoAgenRec(A, A.raiz());                   // para todo lo demás, mastercard
}


template <typename T>
size_t gradoAgenRec(const Agen<T>& A, typename Agen<T>::nodo n)
{
    size_t gradoMax;
    typename Agen<T>::nodo hijo;

    gradoMax = numHijosNodo(A, n);
    hijo = A.hijoIzqdo(n);

    if( hijo == Agen<T>::NODO_NULO )
        return 0;
    else
        while( hijo != Agen<T>::NODO_NULO )
        {
            gradoMax = std::max(gradoMax, gradoAgenRec(A, hijo));
            hijo = A.hermDrcho(hijo);
        }
        return gradoMax;
}



template <typename T>
size_t numHijosNodo(const Agen<T>& A, typename Agen<T>::nodo n)
{
    size_t numNodos;
    typename Agen<T>::nodo hijo;

    numNodos = 0;
    hijo = A.hijoIzqdo(n);

    while(hijo != Agen<T>::NODO_NULO)
    {
        hijo = A.hermDrcho(hijo);
        ++numNodos;
    }

    return numNodos;
}
