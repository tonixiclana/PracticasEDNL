#include <iostream>
#include <string>
#include <fstream>
#include "../TAD/ABIN_H.h"
#include "../TAD/abin_E-S.h"

using namespace std;
typedef string tElto;

unsigned profundidadNodo(const Abin<tElto> &arbol, const Abin<tElto>::nodo &nodo);

int main()
{
    Abin<tElto> abin;
    ifstream fe("abin.dat");

    rellenarAbin(fe, abin);

    imprimirAbin(abin);

    cout << "El nodo: " << abin.elemento(abin.raizB())
        << " tiene profundidad: " << profundidadNodo(abin, abin.raizB());

    cout << "El nodo: " << abin.elemento(abin.hijoDrchoB(abin.raizB()))
        << " tiene profundidad: " << profundidadNodo(abin, abin.hijoDrchoB(abin.raizB()));


}

unsigned profundidadNodo(const Abin<tElto> &abin, const Abin<tElto>::nodo &nodo)
{
    if(nodo == abin.raizB())
        return 0;
    else
        return 1 + profundidadNodo(abin, abin.padreB(nodo));

}
