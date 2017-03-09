#include <algorithm>
template <typename T>
int alturaB(const Abin<T>& A, typename Abin<T>::nodo n)
{
    if(n == NULL)
        return -1;
    else
        return 1 + std::max( alturaB(A, A.hijoIzqdoB(n) ), alturaB(A, A.hijoDrchoB(n) ) );
}
