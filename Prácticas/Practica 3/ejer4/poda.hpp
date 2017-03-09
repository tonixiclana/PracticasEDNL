#include <algorithm>


template <typename T>
typename Agen<T>::nodo buscarNodoRec(Agen<T>& A, const T elto, typename Agen<T>::nodo n)
{
    typename Agen<T>::nodo hijo, nodoCandidato;

    if (n == Agen<T>::NODO_NULO)
    {
        return Agen<T>::NODO_NULO;
    }
    else
    {
        if(A.elemento(n) == elto)
            return n;
        else
        {
            nodoCandidato = Agen<T>::NODO_NULO;
            hijo = A.hijoIzqdo(n);

            while (hijo != Agen<T>::NODO_NULO && nodoCandidato == Agen<T>::NODO_NULO )
            {
                nodoCandidato = buscarNodoRec(A, elto, hijo);
                hijo = A.hermDrcho(hijo);
            }

        return nodoCandidato;
        }
    }

}
template <typename T>
typename Agen<T>::nodo buscarNodo(Agen<T>& A, const T elto)
{
    if(A.arbolVacio())
        return Agen<T>::NODO_NULO;
    else
        return buscarNodoRec(A, elto, A.raiz());

}


template <typename T>
void eliminarHijos(Agen<T>& A,typename Agen<T>::nodo n)
{
    while(A.hijoIzqdo(n) != Agen<T>::NODO_NULO )
    {
        eliminarHijos(A, A.hijoIzqdo(n) );
        A.eliminarHijoIzqdo( n );
    }
}

template <typename T>
void eliminarNodo(Agen<T>& A,typename Agen<T>::nodo n)
{
    typename Agen<T>::nodo hijo;

    if(n == A.raiz())
        A.eliminarRaiz();
    else
        if( A.hijoIzqdo( A.padre(n) ) == n )
            A.eliminarHijoIzqdo(A.padre(n));
        else
        {
            hijo = A.hijoIzqdo(A.padre(n));
            while( A.hermDrcho(hijo) != n )
            {
                hijo = A.hermDrcho(hijo);
            }
            A.eliminarHermDrcho(hijo);
        }
}

template <typename T>
void podarNodo(Agen<T>& A, const T elto)
{
    typename Agen<T>::nodo buscado;

    if(!A.arbolVacio())
        buscado = buscarNodo(A, elto);
        if( buscado != Agen<T>::NODO_NULO )
        {
            eliminarHijos(A, buscado);
            eliminarNodo(A, buscado);
        }

}
