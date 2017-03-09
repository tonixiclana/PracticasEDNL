

template <typename T>
int ejer1(const Abin<T>& A, typename Abin<T>::nodo n)

    if(n == NULL)
    {
        return NULL;
    }
    return 1 + ejer1( A, A.hijoIzqdoB(n) ) + ejer1( A, A.hijoDrchoB(n) );
}
