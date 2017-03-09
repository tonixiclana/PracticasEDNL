#include "../ABIN_H.h"
#include "../cola_enlazada.h"
#include "../listaEnlazada.h"
#include "../abin_E-S.h"
struct nodoArit
{
    char operador;
    float operando;
    nodoArit(char opr = ' ', float opo = 0): operador(opr), operando(opo){}
};

template <typename T>
float aritmeticaRec(typename Abin<T>::nodo n, const Abin<T>& A )
{
    //if( A.alturaB(n) == 0)
    if(A.hijoIzqdoB(n) == Abin<T>::NODO_NULO)
        return A.elemento(n).operando;
    else
        switch(A.elemento(n).operador)
        {
            case '+':
                return aritmeticaRec(A.hijoIzqdoB(n), A) + aritmeticaRec(A.hijoDrchoB(n), A);
            break;
            case '-':
                return aritmeticaRec(A.hijoIzqdoB(n), A) - aritmeticaRec(A.hijoDrchoB(n), A);
            break;
            case '*':
                return aritmeticaRec(A.hijoIzqdoB(n), A) * aritmeticaRec(A.hijoDrchoB(n), A);
            break;
            case '/':
                return aritmeticaRec(A.hijoIzqdoB(n), A) / aritmeticaRec(A.hijoDrchoB(n), A);
            break;

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
