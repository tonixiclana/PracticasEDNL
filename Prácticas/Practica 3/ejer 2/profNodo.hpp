#include <algorithm>
template <typename T>
size_t profNodo(const Agen<T>& A, typename Agen<T>::nodo n)
{
    if(A.arbolVacio())
        return 0;
    else
        return profNodoRec(A, n);
}

template <typename T>
size_t profNodoRec(const Agen<T>& A, typename Agen<T>::nodo n)
{
    if(n == A.raiz())
        return 0;
    else
        return 1 + profNodoRec(A, A.padre(n));
}

//Anexo: averigua la altura del subarbol expresado por el nodo pasado

template <typename T>
size_t alturaNodo(const Agen<T>& A, typename Agen<T>::nodo n)
{
    if(A.arbolVacio())
        return 0;
    else
        return alturaNodoRec(A, n);
}

template <typename T>
size_t alturaNodoRec(const Agen<T>& A, typename Agen<T>::nodo n)
{
    if( A.hijoIzqdo(n) == Agen<T>::NODO_NULO)
        return 0;
    else
    {
        size_t alturaMax;
        typename Agen<T>::nodo hijo;

        alturaMax = 0;
        hijo = A.hijoIzqdo(n);

        while(hijo != Agen<T>::NODO_NULO)
        {
            alturaMax = std::max(alturaMax, alturaNodoRec(A, hijo)+1);
            hijo = A.hermDrcho(hijo);
        }
        return alturaMax;
    }

}
