#include "../ABIN_H.h"
#include "../abin_E-S.h"

template <typename T>
int nodosCon4Descendientes(const Abin<T>& A)
{
    if(A.arbolVacioB())
        return 0;
    else
        return nodosCon4DescendientesRec(A.raizB(), A);
}

template <typename T>
int nodosCon4DescendientesRec(typename Abin<T>::nodo n, const Abin<T>& A)
{
    if(n == Abin<T>::NODO_NULO)
        return 0;
    else
        if(contarDescendientes(n, A) == 4)
            return 1 + nodosCon4DescendientesRec(A.hijoIzqdoB(n), A) + nodosCon4DescendientesRec(A.hijoDrchoB(n), A);
        else
            return nodosCon4DescendientesRec(A.hijoIzqdoB(n), A) + nodosCon4DescendientesRec(A.hijoDrchoB(n), A);

}

template <typename T>
int contarDescendientes(typename Abin<T>::nodo n, const Abin<T>& A)
{
    if(n == Abin<T>::NODO_NULO)
        return 0;
    else
        return 1+ contarDescendientes(A.hijoIzqdoB(n), A) + contarDescendientes(A.hijoDrchoB(n), A);
}
