#include <algorithm>

template <typename T>
size_t desequilibrioAgen(const Agen<T>& A)
{
    if(A.arbolVacio())
        return 0;
    else
    {
        size_t desequilibrioMax;
        typename Agen<T>::nodo hijo;

        desequilibrioMax =0;
        hijo = A.hijoIzqdo(A.raiz());

        while(hijo != Agen<T>::NODO_NULO)
        {

            desequilibrioMax = std::max(desequilibrioMax, ramLarga(A, hijo)- ramCorta(A, hijo));
            hijo = A.hermDrcho(hijo);

        }
    return desequilibrioMax;
    }
}

template <typename T>
size_t ramLarga(const Agen<T>& A, typename Agen<T>::nodo n)
{

    if(A.hijoIzqdo(n) == Agen<T>::NODO_NULO)
    {
        return 0;
    }
    else
    {

        size_t alturaMax;
        typename Agen<T>::nodo hijo;

        alturaMax =0;
        hijo = A.hijoIzqdo(n);

        while(hijo != Agen<T>::NODO_NULO)
        {

            alturaMax = std::max(alturaMax, ramLarga(A, hijo)+1);
            hijo = A.hermDrcho(hijo);
        }
    return alturaMax;
    }
}

template <typename T>
size_t ramCorta(const Agen<T>& A, typename Agen<T>::nodo n)
{
    if(A.hijoIzqdo(n) == Agen<T>::NODO_NULO)
        return 0;
    else
    {
        size_t profMin;
        typename Agen<T>::nodo hijo;

        profMin = -1;
        hijo = A.hijoIzqdo(n);

        while(hijo != Agen<T>::NODO_NULO)
        {
            profMin = std::min(profMin, ramCorta(A, hijo)+1);
            hijo = A.hermDrcho(hijo);
        }
    return profMin;
    }
}
