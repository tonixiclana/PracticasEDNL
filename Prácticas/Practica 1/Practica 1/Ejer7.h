#include <algorithm>

//pre: el nodo pasado debe ser de penúltimo nivel
template <typename T>
bool pseudocompleto(const Abin<T>& A, typename Abin<T>::nodo n )
{
    if(A.hijoIzqdoB(n) != Abin<T>::NODO_NULO && A.hijoDrchoB(n) != Abin<T>::NODO_NULO)
        return true;
    else
        if(A.hijoIzqdoB(n) == Abin<T>::NODO_NULO && A.hijoDrchoB(n) == Abin<T>::NODO_NULO)
            return true;
        else
            return false;
}

template <typename T>
bool ejer7Rec(const Abin<T>& A, typename Abin<T>::nodo n )
{
    if(A.profundidadB(n) == A.alturaB(A.raizB()) - 1)       //hayar nodos de penultimo nivel
        return pseudocompleto( A, n );
    else                                            // llamadas recursivas para buscar  a nodos de penultimo nivel
    {
        if( A.alturaB(A.hijoIzqdoB(n)) > A.alturaB(A.hijoDrchoB(n)) )
            return ejer7Rec(A, A.hijoIzqdoB(n));
        else
            if( A.alturaB(A.hijoIzqdoB(n)) < A.alturaB(A.hijoDrchoB(n)) )
                return ejer7Rec(A, A.hijoDrchoB(n));
            else
                return ejer7Rec(A, A.hijoIzqdoB(n)) && ejer7Rec(A, A.hijoDrchoB(n));
    }
}





template <typename T>
bool ejer7(const Abin<T>& A)
{
    if(A.arbolVacioB())                         //si es árbol está vacio es pseudocompleto
        return true;
    else
        if(A.hijoDrchoB( A.raizB()) == Abin<T>::NODO_NULO && A.hijoIzqdoB( A.raizB()) == Abin<T>::NODO_NULO ) //si el nodo raiz no tiene hijos también es pseudp
            return true;
        else
            return ejer7Rec(A, A.raizB());      //en otro caso llamamos a la recursiva
}

