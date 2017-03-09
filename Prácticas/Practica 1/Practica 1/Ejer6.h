#include <algorithm>
template <typename T>
int diferenciaAltura(const Abin<T>& A, typename Abin<T>::nodo n )
{
    if(n != Abin<T>::NODO_NULO)
        return abs( A.alturaB(A.hijoIzqdoB(n))-A.alturaB(A.hijoDrchoB(n)) );
    else
        return 0;
}
template <typename T>
int ejer6(const Abin<T>& A, typename Abin<T>::nodo n)
{
    if(n == Abin<T>::NODO_NULO)
        return 0;
    else
        return std::max( std::max( diferenciaAltura(A, n), ejer6(A, A.hijoIzqdoB(n)) ), ejer6(A, A.hijoDrchoB(n)) );
}
