#include <iostream>
#include <fstream>
#include <string>
#include "../../TADS/ArbolBinario/ABIN_H2.0.h"
#include "../../TADS/ArbolBinario/abin_E-S.h"
/*
    * Consiste  en eliminar la descendencia de los nodos que tengan 1 hijo
*/
using namespace std;

template <typename T>
void eliminarDescendenciaRec(Abin<T> &abin, typename Abin<T>::nodo nodo)
{
    if(nodo != Abin<T>::NODO_NULO)
    {
        if(abin.hijoIzqdoB(nodo) != Abin<T>::NODO_NULO && abin.hijoDrchoB(nodo) != Abin<T>::NODO_NULO)
        {
            eliminarDescendenciaRec(abin, abin.hijoIzqdoB(nodo));
            eliminarDescendenciaRec(abin, abin.hijoDrchoB(nodo));
            abin.eliminarHijoIzqdoB(nodo);
            abin.eliminarHijoDrchoB(nodo);
        }
        if(abin.hijoIzqdoB(nodo) != Abin<T>::NODO_NULO)
        {
            eliminarDescendenciaRec(abin, abin.hijoIzqdoB(nodo));
            abin.eliminarHijoIzqdoB(nodo);
        }
        else
        if(abin.hijoDrchoB(nodo) != Abin<T>::NODO_NULO)
        {
            eliminarDescendenciaRec(abin, abin.hijoDrchoB(nodo));
            abin.eliminarHijoDrchoB(nodo);
        }
    }
}

template <typename T>
void transformarAbinRec(Abin<T> &abin, typename Abin<T>::nodo nodo)
{
    if(abin.hijoIzqdoB(nodo) != Abin<T>::NODO_NULO && abin.hijoDrchoB(nodo) == Abin<T>::NODO_NULO)
        eliminarDescendenciaRec(abin, nodo);
    else
    if(abin.hijoIzqdoB(nodo) == Abin<T>::NODO_NULO && abin.hijoDrchoB(nodo) != Abin<T>::NODO_NULO)
        eliminarDescendenciaRec(abin, nodo);
    else
    if(abin.hijoIzqdoB(nodo) != Abin<T>::NODO_NULO && abin.hijoDrchoB(nodo) != Abin<T>::NODO_NULO)
    {
        transformarAbinRec(abin, abin.hijoIzqdoB(nodo));
        transformarAbinRec(abin, abin.hijoDrchoB(nodo));
    }
}

template <typename T>
void transformarAbin(Abin<T> &abin)
{
    if(!abin.arbolVacioB())
        transformarAbinRec(abin, abin.raizB());
}

int main()
{
    char op;
    Abin<float> A{}, B{};
    //-----------------Entradas y salidas
    cout << "desea rellenar? S/N" ;
    cin >> op;
    if(op == 'S')
    {
        cout << "****Lectura del arbol binario A ****\n";
        rellenarAbin<float>(A, -1);

        ofstream fs("abin.dat");
        imprimirAbin<float>(fs, A, -1);
        fs.close();
        cout << "\n *****arbol guardado en abin.dat\n";
    }

    cout << "*****Lectura del arbol binario A desde abin.dat****\n";
    ifstream fe("abin.dat");
    rellenarAbin<float>(fe, B);
    fe.close();
    imprimirAbin(B);

        cout << "transformando arbol" << endl;
    transformarAbin(B);
    imprimirAbin(B);
}
