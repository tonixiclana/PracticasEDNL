#include <iostream>
#include <fstream>
#include "../../TADS/ArbolGeneral/AGEN_H.h"
#include "../../TADS/ArbolGeneral/agen_E-S.h"

using namespace std;

template <typename T>
int profNodo(const Agen<T> &agen, const typename Agen<T>::nodo nodo);

int main()
{
   Agen<char> A, B;
   char op;
   //-----------------Entradas y salidas
    cout << "desea rellenar? S/N" ;
    cin >> op;
    if(op == 'S')
    {
        cout << "****Lectura del arbol general A ****\n";
        rellenarAgen<char>(A, '#');

        ofstream fs("abin.dat");
        imprimirAgen<char>(fs, A, '#');
        fs.close();
        cout << "\n *****arbol guardado en abin.dat\n";
    }

    cout << "*****Lectura del arbol binario A desde abin.dat****\n";
    ifstream fe("abin.dat");
    rellenarAgen<char>(fe, B);
    fe.close();
    cout << "el arbol leido de abin.dat es: " << endl;
    imprimirAgen(B);

    cout << "El nodo: "<< B.elemento(B.hijoIzqdo(B.hijoIzqdo(B.raiz())))<< "esta en profundidad: " << profNodo(B, B.hijoIzqdo(B.hijoIzqdo(B.raiz())));
}

template <typename T>
int profNodo(const Agen<T> &agen, const typename Agen<T>::nodo nodo)
{
    if(nodo == agen.raiz())
        return 0;
    else
        return 1 + profNodo(agen, agen.padre(nodo));
}

