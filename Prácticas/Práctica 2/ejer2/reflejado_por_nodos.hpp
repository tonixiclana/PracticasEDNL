#include "../ABIN_H.h"
#include "../abin_E-S.h"
#include "../cola_enlazada.h"
//no terminador
template <typename T>
void reflejadoRec(const Abin<T>& A, typename Abin<T>::nodo n1, Abin<T>& B, typename Abin<T>::nodo n2)
{
    if(A.hijoIzqdoB(n1) == A.NODO_NULO && A.hijoDrchoB(n1) == A.NODO_NULO)
    {

    }else
    {

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

