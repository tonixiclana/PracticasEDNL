#include "../ABIN_H.h"
#include "../abin_E-S.h"

template <typename T>
void reflejadoRec(const Abin<T>& A, typename Abin<T>::nodo n1, Abin<T>& B, typename Abin<T>::nodo n2)
{
    if(A.hijoIzqdoB(n1) != A.NODO_NULO)
    {
        B.insertarHijoDrchoB(n2, A.elemento( A.hijoIzqdoB(n1) ) );
        reflejadoRec(A, A.hijoIzqdoB(n1), B, B.hijoDrchoB(n2) );
    }


    if(A.hijoDrchoB(n1) != A.NODO_NULO)
    {
        B.insertarHijoIzqdoB(n2, A.elemento( A.hijoDrchoB(n1) ) );
        reflejadoRec(A, A.hijoDrchoB(n1), B, B.hijoIzqdoB(n2) );
    }

}


template <typename T>
Abin<T> reflejado(const Abin<T>& A)
{
    Abin<T> B;

    if( !A.arbolVacioB() )
    {
        B.insertarRaizB( A.elemento( A.raizB() ) );
        reflejadoRec(A, A.raizB(), B, B.raizB());
    }
    return B;
}
