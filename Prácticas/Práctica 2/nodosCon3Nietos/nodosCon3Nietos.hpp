#include "../ABIN_H.h"
#include "../abin_E-S.h"
using namespace std;

template <typename T>
int contarNietosRec(typename Abin<T>::nodo n, const Abin<T>& A, int prof)
{
    if(prof == 2 || n == Abin<T>::NODO_NULO )                       //
        if(prof == 2 && n != Abin<T>::NODO_NULO)            // hemos encontrado un nieto
            return 1;
        else
            return 0;                                       // no hay nieto devolvemos 0
    else

        return contarNietosRec(A.hijoIzqdoB(n), A, prof+1) + contarNietosRec(A.hijoDrchoB(n), A, prof+1);
}

template<typename T>
int contarNietos(typename Abin<T>::nodo n, const Abin<T>& A)
{
    return contarNietosRec(n, A, 0);
}

template<typename T>
int nodosCon3NietosRec(typename Abin<T>::nodo n, const Abin<T>& A)
{
    if(n == Abin<T>::NODO_NULO)
        return 0;
    else
        if(contarNietos(n,A) == 3)                                      //contar el numero de nodos que tienen 3 nietos

            return 1 + nodosCon3NietosRec(A.hijoIzqdoB(n), A) + nodosCon3NietosRec(A.hijoDrchoB(n), A);
        else
            return nodosCon3NietosRec(A.hijoIzqdoB(n), A) + nodosCon3NietosRec(A.hijoDrchoB(n), A);
}


template<typename T>
int nodosCon3Nietos(const Abin<T>& A)
{
    if(A.arbolVacioB())
        return 0;
    else
        return nodosCon3NietosRec(A.raizB(), A);
}



