#include <iostream>
#include <fstream>
#include <string>
#include "../../TADS/ArbolBinario/ABIN_H2.0.h"
#include "../../TADS/ArbolBinario/abin_E-S.h"

using namespace std;

template <typename T>
bool iguales(const Abin<T> &abin0, const Abin<T> &abin1);

template <typename T>
bool igualesRec(const Abin<T> &abin0, const Abin<T> &abin1,
                 typename Abin<T>::nodo nodo0, typename Abin<T>::nodo nodo1 );

int main()
{
    Abin<string> abin0, abin1;

    ifstream is("abin0.dat");
    ifstream is2("abin1.dat");
    rellenarAbin(is, abin0);
    rellenarAbin(is2, abin1);
    imprimirAbin(abin0);
    imprimirAbin(abin1);

    cout << iguales(abin0, abin1) << endl;
}

template <typename T>
bool iguales(const Abin<T> &abin0, const Abin<T> &abin1)
{
    igualesRec(abin0, abin1, abin0.raizB(), abin1.raizB());
}

template <typename T>
bool igualesRec(const Abin<T> &abin0, const Abin<T> &abin1,
                 typename Abin<T>::nodo nodo0, typename Abin<T>::nodo nodo1 )
{
    if(nodo0 == Abin<T>::NODO_NULO && nodo1 == Abin<T>::NODO_NULO )
        return true;
    else
        if(nodo0 != Abin<T>::NODO_NULO && nodo1 == Abin<T>::NODO_NULO)
            return false;
        else
            if(nodo0 == Abin<T>::NODO_NULO && nodo1 != Abin<T>::NODO_NULO)
                return false;
            else
                if(nodo0 != Abin<T>::NODO_NULO && nodo1 != Abin<T>::NODO_NULO)
                    return igualesRec(abin0, abin1, abin0.hijoIzqdoB(nodo0),
                            abin1.hijoIzqdoB(nodo1)) && igualesRec(abin0,
                            abin1, abin0.hijoDrchoB(nodo0),abin1.hijoDrchoB(nodo1));
}
