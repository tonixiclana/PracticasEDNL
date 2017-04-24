#include <iostream>
#include <fstream>
#include <vector>
#include "../../TADS/ArbolBinarioBusqueda/ABB_H.hpp"
#include "../../TADS/ArbolBinarioBusqueda/abb_E-S.h"

using namespace std;

template <typename T>
T infimo(const Abb<T>& abb0, T x);
template <typename T>
T supremoRec(const Abb<T>& abb0, T x, T supremo);
template <typename T>
T supremo(const Abb<T>& abb0, T x);

int main()
{
    Abb<int> A;

    rellenarAbb(A, -1);

    cout << "arbol A:" << endl;
    imprimirAbb(A);
    cout << "el infimo de 29 es: " << infimo(A, 29);
    cout << "el supremo de 29 es: " << supremo(A, 29);
}

template <typename T>
T infimo(const Abb<T>& abb0, T x)
{
    if(x < abb0.elemento())
    {
        if(abb0.izqdo().vacio())
            return abb0.elemento();
        else
            return infimo(abb0.izqdo(), x);
    }
    else
    if(x > abb0.elemento())
    {
        if(abb0.drcho().vacio())
            return abb0.elemento();
        else
            return infimo(abb0.drcho(), x);
    }
    else
        return x;
}

template <typename T>
T supremo(const Abb<T>& abb0, T x)
{
    return supremoRec(abb0, x, abb0.elemento());
}

template <typename T>
T supremoRec(const Abb<T>& abb0, T x, T supremo)
{
    if(x < abb0.elemento())
    {
        if(x < supremo)
            supremo = x;
        if(abb0.izqdo().vacio())
            return supremo;
        else
            return supremoRec(abb0.izqdo(), x, supremo);
    }
    else
    if(x > abb0.elemento())
    {
        if(abb0.drcho().vacio())
            return abb0.elemento();
        else
            return supremoRec(abb0.drcho(), x, supremo);
    }
    else
        return x;
}

