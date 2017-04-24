#include <iostream>
#include <fstream>
#include "../../TADS/ArbolGeneral/AGEN_H.h"
#include "../../TADS/ArbolGeneral/agen_E-S.h"

using namespace std;

template <typename T>
void podaAgen(Agen<T> &agen, T elto);
template <typename T>
void podaAgenRec(Agen<T> &agen, typename Agen<T>::nodo, T elto);
template <typename T>
void podarNodoAgen(Agen<T> &agen, typename Agen<T>::nodo);

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


    cout << "el arbol con la poda a partir de C es: " ;
    podaAgen(B, 'A');
    imprimirAgen(B);
}

template <typename T>
void podaAgen(Agen<T> &agen, T elemento)
{
    if(!agen.arbolVacio())
        if(agen.elemento(agen.raiz()) == elemento)
            podarNodoAgenRec(agen, agen.raiz());
        else
            podaAgenRec(agen, agen.raiz(), elemento);
}

template <typename T>
void podaAgenRec(Agen<T> &agen, typename Agen<T>::nodo nodo, T elemento)
{
    typename Agen<T>::nodo hijo = agen.hijoIzqdo(nodo);

    while(hijo != Agen<T>::NODO_NULO)
    {
        if(agen.elemento(hijo) == elemento)
            podarNodoAgenRec(agen, hijo);

        podaAgenRec(agen, hijo, elemento);
        hijo = agen.hermDrcho(hijo);
    }
}

template <typename T>
void podarNodoAgenRec(Agen<T> &agen, typename Agen<T>::nodo nodo)
{
    typename Agen<T>::nodo hijo = agen.hijoIzqdo(nodo);

    while(hijo != Agen<T>::NODO_NULO)
    {
        podarNodoAgenRec(agen, hijo);
        hijo = agen.hermDrcho(hijo);
        agen.eliminarHijoIzqdo(nodo);
    }
}

