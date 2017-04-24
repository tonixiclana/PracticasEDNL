#include <iostream>
#include <fstream>
#include "../../TADS/ArbolGeneral/AGEN_H.h"
#include "../../TADS/ArbolGeneral/agen_E-S.h"

using namespace std;

template <typename T>
int desequilibrio(const Agen<T> &agen);
template <typename T>
void desequilibrioRec(const Agen<T> &agen, const typename Agen<T>::nodo nodo, unsigned &ramaMin, unsigned &ramaMax, int &longRama);

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

    cout << "El desequilibrio del arbol es: " << desequilibrio(B);
}

template <typename T>
int desequilibrio(const Agen<T> &agen)
{
    unsigned ramaMin = -1, ramaMax = 0;
    int longRama;
    if(agen.arbolVacio())
        return 0;
    else
    {
        desequilibrioRec(agen, agen.raiz(), ramaMin, ramaMax, longRama = 0);
        return ramaMax - ramaMin;
    }
}

template <typename T>
void desequilibrioRec(const Agen<T> &agen, const typename Agen<T>::nodo nodo, unsigned &ramaMin, unsigned &ramaMax, int &longRama)
{
    typename Agen<T>::nodo hijo = agen.hijoIzqdo(nodo);
    if(hijo == Agen<T>::NODO_NULO)
    {
        if(longRama < ramaMin)
            ramaMin = longRama;
        if(longRama >= ramaMax)
            ramaMax = longRama;
    }

    while(hijo != Agen<T>::NODO_NULO)
    {
        longRama += 1;
        desequilibrioRec(agen, hijo, ramaMin, ramaMax, longRama);
        //cout << "elemento:" << agen.elemento(hijo) << " longrama:" << longRama << endl;
        longRama -= 1;
        hijo = agen.hermDrcho(hijo);
    }
}


