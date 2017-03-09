#include "../ABIN_H.h"
#include "../cola_enlazada.h"
#include "../listaEnlazada.h"
#include "../abin_E-S.h"

template <typename T>
bool compRec(typename Abin<T>::nodo n1, const Abin<T>& A, typename Abin<T>::nodo n2, const Abin<T>& B)
{
    if(n1 == Abin<T>::NODO_NULO && n2 == Abin<T>::NODO_NULO)
        return true;
    else
    {
        if( n1 != A.NODO_NULO && n2 != B.NODO_NULO )
            return compRec( A.hijoIzqdoB(n1), A, B.hijoIzqdoB(n2), B) && compRec( A.hijoDrchoB(n1), A, B.hijoDrchoB(n2), B);
        else
            return false;
    }
}

template <typename T>
bool similares(const Abin<T>& A, const Abin<T>& B)
{
    if(A.arbolVacioB() || B.arbolVacioB())
        return ( A.arbolVacioB() && B.arbolVacioB() );
    else
    {
        return compRec(A.raizB(), A, B.raizB(), B);

    }

}

