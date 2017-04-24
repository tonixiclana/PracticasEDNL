#include <iostream>
#include <fstream>
#include <string>
#include "../TAD/ABIN_VEC0_H.h"
#include "../TAD/abin_E-S.h"


using namespace std;
typedef char T;

unsigned alturaAbin(const Abin<T> arbol, Abin<T>::nodo nodo);

int main()
{

    Abin<T> arbol(25);

    ifstream fe("abin.dat"); //abrimos flujo de salida
    rellenarAbin(fe, arbol);
    imprimirAbin(arbol);



    cout << "El arbol tiene altura: " <<
        alturaAbin(arbol, arbol.raizB())<< endl;
    return 0;
}

unsigned alturaAbin(const Abin<T> arbol, Abin<T>::nodo nodo)
{

    if(nodo == Abin<T>::NODO_NULO)
        return 0;
    else
        return 1 + max(alturaAbin(arbol, arbol.hijoIzqdoB(nodo)),
            alturaAbin(arbol, arbol.hijoDrchoB(nodo)));
}
