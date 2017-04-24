#include <iostream>
#include <fstream>

#include "../../../TADS/ArbolBinario/ABIN_H2.0.h"
#include "../../../TADS/ArbolBinario/abin_E-S.h"
using namespace std;

template <typename T>
bool pseudocompletoAbin(const Abin<T> &arbol);

template <typename T>
bool pseudocompletoAbinRec(const Abin<T> &arbol, const typename Abin<T>::nodo nodo);


int main()
{
    Abin<string> abin, abin2;
    ifstream fe("abin.dat");
    ifstream fe2("abin2.dat");

    rellenarAbin(fe, abin);
    rellenarAbin(fe2, abin2);

    imprimirAbin(abin);
    imprimirAbin(abin2);


    cout << "Es abin pseudocompleto?" << pseudocompletoAbin(abin) << endl;
    cout << "Es abin2 pseudocompleto?" << pseudocompletoAbin(abin2) << endl;
    return 0;
}

template <typename T>
bool pseudocompletoAbin(const Abin<T> &arbol)
{
    if(arbol.arbolVacioB())
        return true;                            //suponemos que si un arbol está vacio es pseudocompleto
    else
        if(arbol.alturaB(arbol.raizB()) < 2)    //si el nodo raiz no tiene hijostamb suponemos que es pseudocompleto
            return false;
        else
            return pseudocompletoAbinRec(arbol, arbol.raizB());
}

template <typename T>
bool pseudocompletoAbinRec(const Abin<T> &arbol, const typename Abin<T>::nodo nodo)
{
    if(arbol.profundidadB(nodo) == arbol.alturaB(arbol.raizB()) - 1)        //si estoy en el penultimo nivel
        if((arbol.hijoIzqdoB(nodo) == Abin<T>::NODO_NULO && arbol.hijoDrchoB(nodo) == Abin<T>::NODO_NULO) ||
            (arbol.hijoIzqdoB(nodo) != Abin<T>::NODO_NULO && arbol.hijoDrchoB(nodo) != Abin<T>::NODO_NULO) ) //si el nodo tiene 2 hijo o ninguno
            return true;
        else
            return false;
    else
        if(arbol.alturaB(arbol.hijoIzqdoB(nodo)) > arbol.alturaB(arbol.hijoDrchoB(nodo)))
            return pseudocompletoAbinRec(arbol, arbol.hijoIzqdoB(nodo));
        else
            if(arbol.alturaB(arbol.hijoIzqdoB(nodo)) < arbol.alturaB(arbol.hijoDrchoB(nodo)))
                return pseudocompletoAbinRec(arbol, arbol.hijoDrchoB(nodo));
            else
                return pseudocompletoAbinRec(arbol, arbol.hijoIzqdoB(nodo)) && pseudocompletoAbinRec(arbol, arbol.hijoDrchoB(nodo));

}
