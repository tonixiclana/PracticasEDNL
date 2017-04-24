#include <iostream>
#include <fstream>
#include <vector>
#include "../../TADS/ArbolBinarioBusqueda/ABB_H.hpp"
#include "../../TADS/ArbolBinarioBusqueda/abb_E-S.h"

using namespace std;

template <typename T>
Abb<T> unionAbb(const Abb<T>& abb0, const Abb<T>& abb1);
template <typename T>
void unionAbbRec(Abb<T>& abb, const Abb<T>& abb0, const Abb<T>& abb1);
template <typename T>
Abb<T> equilibrarAbb(const Abb<T>& abb);
template <typename T>
void equilibrarAbbRec(Abb<T>& abb, vector<T> vectorElto);
template <typename T>
void obtenerElementos(const Abb<T>& abb, vector<T> &vectorElto);

int main()
{
    Abb<int> A ,B, C;

    rellenarAbb(A, -1);
    rellenarAbb(B, -1);

    cout << "arbol A:" << endl;
    imprimirAbb(A);
    cout << "arbol B:" << endl;
    imprimirAbb(B);

    C = unionAbb(A, B);

    cout << "Union:" << endl;
    imprimirAbb(C);

}

template <typename T>
Abb<T> unionAbb(const Abb<T>& abb0, const Abb<T>& abb1)
{
    Abb<T> abb;

    if(abb0.vacio())
        return abb1;
    else
    if(abb1.vacio())
        return abb0;
    else
    {
        unionAbbRec(abb, abb0, abb1);
        return equilibrarAbb(abb);
    }
}

template <typename T>
void unionAbbRec(Abb<T>& abb, const Abb<T>& abb0, const Abb<T>& abb1)
{
    if(!abb0.vacio() && !abb1.vacio())
    {
        abb.insertar(abb0.elemento());
        abb.insertar(abb1.elemento());
        unionAbbRec(abb,abb0.izqdo(), abb1.izqdo());
        unionAbbRec(abb,abb0.drcho(), abb1.drcho());
    }
    else
    if(abb0.vacio() && !abb1.vacio())
    {
         abb.insertar(abb1.elemento());
         unionAbbRec(abb, abb0, abb1.izqdo());
         unionAbbRec(abb, abb0, abb1.drcho());
    }
    else
    if(!abb0.vacio() && abb1.vacio())
    {
         abb.insertar(abb0.elemento());
         unionAbbRec(abb, abb0.izqdo(), abb1);
         unionAbbRec(abb, abb0.drcho(), abb1);
    }
}

template <typename T>
Abb<T> equilibrarAbb(const Abb<T>& abb)
{
    vector<T> vectorElto;
    Abb<T> abbRet;
    obtenerElementos(abb, vectorElto);
    equilibrarAbbRec(abbRet, vectorElto);
    return abbRet;
}

template <typename T>
void equilibrarAbbRec(Abb<T>& abb, vector<T> vectorElto)
{
    if(vectorElto.size() == 1)
        abb.insertar(vectorElto.front());
    else
    if(!vectorElto.empty())
    {
        vector<T> izq, der;
        int mediana = (vectorElto.size() / 2) + 1 - 1; //suma 1 para quedarse con valor central, resta uno para usarlo en el array
        abb.insertar(vectorElto[mediana]);

        for(int i = 0; i < mediana; i++)
            izq.push_back(vectorElto[i]);
        for(int i = mediana + 1; i < vectorElto.size(); i++)
            der.push_back(vectorElto[i]);

        equilibrarAbbRec(abb, izq);
        equilibrarAbbRec(abb, der);
    }
}

template <typename T>
void obtenerElementos(const Abb<T>& abb, vector<T> &vectorElto)
{
    if(!abb.vacio())
    {
        obtenerElementos(abb.izqdo(), vectorElto);
        vectorElto.push_back(abb.elemento());
        obtenerElementos(abb.drcho(), vectorElto);
    }
}
