#include "../ABIN_H2.0.h"
#include "../abin_E-S.h"

template <typename T>
int comprobarReveldeRec(typename Abin<T>::nodo n,typename Abin<T>::nodo acusado, const Abin<T>& A)
{
    if(A.padreB(n) == Abin<T>::NODO_NULO)
        return 0;
    else
        if(A.elemento(acusado) == A.elemento(A.padreB(n)) )
        {
            return 1 + comprobarReveldeRec(A.padreB(n), acusado, A);
        }
        else
        {
            return -1 + comprobarReveldeRec(A.padreB(n), acusado, A);
        }

}

template <typename T>
bool esRevelde(typename Abin<T>::nodo acusado, const Abin<T>& A)
{
    if(comprobarReveldeRec(acusado, acusado, A) < 0)
    {
        return true;
    }
    else
    {
        return false;
    }

}

template <typename T>
int nodosReveldesRec(typename Abin<T>::nodo n, const Abin<T>& A)
{
    if(n == Abin<T>::NODO_NULO)
        return 0;
    else
        if(esRevelde(n,A))
            return 1 + nodosReveldesRec(A.hijoIzqdoB(n), A) + nodosReveldesRec(A.hijoDrchoB(n), A);
        else
            return nodosReveldesRec(A.hijoIzqdoB(n), A) + nodosReveldesRec(A.hijoDrchoB(n), A);
}

template <typename T>
int nodosReveldes(const Abin<T>& A)
{
    if(A.arbolVacioB())
        return 0;
    else
        return nodosReveldesRec(A.raizB(),A);

}

