#include <iostream>
#include <fstream>
#include <vector>
#include "../../TADS/ArbolBinarioBusqueda/ABB_H.hpp"
#include "../../TADS/ArbolBinarioBusqueda/abb_E-S.h"
using namespace std;

template <typename T>
Abb<T> equilibrarAbb(const Abb<T>& abb);
template <typename T>
void equilibrarAbbRec(Abb<T>& abb, vector<T> vectorElto);
template <typename T>
void obtenerElementos(const Abb<T>& abb, vector<T> &vectorElto);

int main()
{
    Abb<int> A , B;

    rellenarAbb(A, -1);

    B = equilibrarAbb(A);

    cout << "arbol sin equilibrar:" << endl;
    imprimirAbb(A);
    cout << "arbol equilibrado:" << endl;
    imprimirAbb(B);

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
