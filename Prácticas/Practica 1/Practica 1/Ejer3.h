template <typename T>

int profundidadB(const Abin<T>& A, typename Abin<T>::nodo n)
{
    if( n == A.raizB() )
        return 0;
    else
        return 1 + profundidadB(A, A.padreB(n));
}
