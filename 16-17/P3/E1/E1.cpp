#include <iostream>
#include <fstream>
#include "../../TADS/ArbolGeneral/AGEN_H.h"
#include "../../TADS/ArbolGeneral/agen_E-S.h"

using namespace std;

template <typename T>
int gradoAgen(const Agen<T> &agen);
template <typename T>
int gradoAgenRec(const Agen<T> &agen, const typename Agen<T>::nodo nodo);

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

    cout << "el grado de B es: " << gradoAgen(B);
}

template <typename T>
int gradoAgen(const Agen<T> &agen)
{
    if(agen.arbolVacio())
        return 0;
    else
        return gradoAgenRec(agen, agen.raiz());
}

template <typename T>
int gradoAgenRec(const Agen<T> &agen, const typename Agen<T>::nodo nodo)
{
    int gradoMax = numHijosNodo(agen, nodo);

    typename Agen<T>::nodo hijo = agen.hijoIzqdo(nodo);

    while(hijo != Agen<T>::NODO_NULO)
    {
        gradoMax = max(gradoMax, gradoAgenRec(agen, hijo));
        hijo = agen.hermDrcho(nodo);
    }

    return gradoMax;
}

template <typename T>
unsigned numHijosNodo(const Agen<T> &agen, const typename Agen<T>::nodo nodo)
{
    typename Agen<T>::nodo hijo = agen.hijoIzqdo(nodo);
    unsigned hijos = 0;

    while(hijo != Agen<T>::NODO_NULO)
    {
        hijos++;
        hijo = agen.hermDrcho(hijo);
    }
    return hijos;
}
