#include <iostream>
#include <stdlib.h>
#include <cassert>
#include "ArBinBus.h"
#ifndef _E_S_BUS_
#define _E_S_BUS_

using namespace std;
template <typename T>  void leeAbb(Abb<T>& A, const T& fin);
template <typename T> void imprimirAbb (const Abb<T>& A);
template <typename T> void imprimirDescendientes (typename Abb<T>::nodo r, const Abb<T>& A);
template <typename T> void leerAbb(Abb<T>& A, T fin)
{
    T e;
    cout << "Introduzca elemento (" << fin << " si quiere detener la insercion)" << endl;
    cin >> e;
    while(e!=fin){
        A.insertar(e);
        cout << "Introduzca elemento" << endl;
        cin >> e;
    }
}
template <typename T> void imprimirAbb(const Abb<T>& A)
{
	if (!A.vacio()) {
		//std::cout << "Raíz del árbol: " <<
		//A.elemento(A.raizB()) << std::endl;
		//imprimirDescendientes(A.raizB(), A);
	}
	else std::cout << "Árbol vacío\n";
}

template <typename T>
void imprimirDescendientes (typename Abb<T>::nodo r, const Abb<T>& A)
{
	if (A.hijoIzqdoB(r) != Abb<T>::NODO_NULO) {
		std::cout << "Hijo izqdo de " << A.elemento(r) << ": "
		<< A.elemento(A.hijoIzqdoB(r)) << std::endl;
		imprimirDescendientes(A.hijoIzqdoB(r), A);
	}
	if (A.hijoDrchoB(r) != Abb<T>::NODO_NULO) {
		std::cout << "Hijo derecho de " << A.elemento(r) << ": "
		<< A.elemento(A.hijoDrchoB(r)) << std::endl;
		imprimirDescendientes(A.hijoDrchoB(r), A);
	}
}
#endif
