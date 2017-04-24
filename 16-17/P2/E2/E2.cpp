#include <iostream>
#include <fstream>
#include <string>
#include "../../TADS/ArbolBinario/ABIN_H2.0.h"
#include "../../TADS/ArbolBinario/abin_E-S.h"

using namespace std;

template <typename T>
Abin<T> reflejadoAbin(const Abin<T> &abin);

template <typename T>
void reflejadoAbinRec(const Abin<T> &abin0, typename Abin<T>::nodo nodo0,
                      Abin<T> abin1, typename Abin<T>::nodo nodo1);

int main()
{
    Abin<string> abin;

    ifstream is("abin.dat");
    rellenarAbin(is, abin);
    imprimirAbin(abin);
    imprimirAbin(reflejadoAbin(abin));


}

template <typename T>
Abin<T> reflejadoAbin(const Abin<T> &abin0)
{
    Abin<T> abin1;

    if(abin0.arbolVacioB())
        return abin1;
    else
    {
        abin1.insertarRaizB(abin0.elemento(abin0.raizB()));
        if(abin0.hijoIzqdoB(abin0.raizB()) == Abin<T>::NODO_NULO &&
           abin0.hijoDrchoB(abin0.raizB()) == Abin<T>::NODO_NULO)
            return abin1;
        else
        {
            reflejadoAbinRec(abin0, abin0.raizB(), abin1, abin1.raizB());
            return abin1;
        }
    }
}


template <typename T>
void reflejadoAbinRec(const Abin<T> &abin0, typename Abin<T>::nodo nodo0,
                      Abin<T> abin1, typename Abin<T>::nodo nodo1)
{
    if(nodo0 == Abin<T>::NODO_NULO)
    {

    }
    else
    {
        if(abin0.hijoIzqdoB(nodo0) != Abin<T>::NODO_NULO &&
           abin0.hijoDrchoB(nodo0) == Abin<T>::NODO_NULO)
        {
            abin1.insertarHijoDrchoB(nodo1, abin0.elemento(abin0.hijoIzqdoB(nodo0)));
            reflejadoAbinRec(abin0,abin0.hijoIzqdoB(nodo0), abin1, abin1.hijoDrchoB(nodo1));
        }
        else
        if(abin0.hijoIzqdoB(nodo0) == Abin<T>::NODO_NULO &&
           abin0.hijoDrchoB(nodo0) != Abin<T>::NODO_NULO)
        {
            abin1.insertarHijoIzqdoB(nodo1, abin0.elemento(abin0.hijoDrchoB(nodo0)));
            reflejadoAbinRec(abin0,abin0.hijoDrchoB(nodo0), abin1, abin1.hijoIzqdoB(nodo1));
        }
        else
        if(abin0.hijoIzqdoB(nodo0) != Abin<T>::NODO_NULO &&
           abin0.hijoDrchoB(nodo0) != Abin<T>::NODO_NULO)
        {
            abin1.insertarHijoDrchoB(nodo1, abin0.elemento(abin0.hijoIzqdoB(nodo0)));
            abin1.insertarHijoIzqdoB(nodo1, abin0.elemento(abin0.hijoDrchoB(nodo0)));
            reflejadoAbinRec(abin0,abin0.hijoIzqdoB(nodo0), abin1, abin1.hijoDrchoB(nodo1));
            reflejadoAbinRec(abin0,abin0.hijoDrchoB(nodo0), abin1, abin1.hijoIzqdoB(nodo1));
        }
    }
}
