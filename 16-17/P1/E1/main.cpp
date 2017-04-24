#include <iostream>
#include <fstream>
#include <string>
#include "../TAD/ABIN_VEC0_H.h"
#include "../TAD/abin_E-S.h"


using namespace std;
typedef char T;

unsigned numNodosAbin(const Abin<T> arbol, Abin<T>::nodo nodo);

int main()
{

    Abin<T> arbol(25);

    ifstream fe("abin.dat"); //abrimos flujo de salida
    rellenarAbin(fe, arbol);
    imprimirAbin(arbol);



    cout << "Hay " << numNodosAbin(arbol, arbol.raizB()) <<
        " nodos en el arbol" << endl;
    return 0;
}

unsigned numNodosAbin(const Abin<T> arbol, Abin<T>::nodo nodo)
{

    if(nodo == Abin<T>::NODO_NULO)
    {
        return 0;
    }else
        return 1 + numNodosAbin(arbol, arbol.hijoIzqdoB(nodo)) +
            numNodosAbin(arbol, arbol.hijoDrchoB(nodo));
}
