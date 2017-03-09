#include "aritmetico.h"

template <typename T>
void aritmeticaRec(typename Abin<T>::nodo n, const Abin<T>& A )
{
    if( A.alturaB() == 0)
        return A.elemento(n).operando;
    else
        switch(A.elemento(n).opdor)
        {
            case '+':
                return aritmeticaRec(A.hijoIzqdoB(n), A) + aritmeticaRec(A.hijoDrchoB(n), A);
        }


}
template <typename T>
float aritmetica(const Abin<T>& A)
{
    if( A.arbolVacioB())
        return 0;
    else
        return aritmeticaRec( A.raizB(), A);
}



