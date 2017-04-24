#include <iostream>
#include <fstream>
#include <string>
#include "../TAD/ABIN_H2.0.h"
#include "../TAD/abin_E-S.h"

using namespace std;

template <typename T>
int desequilibrioAbin(const Abin<T> &abin);

template <typename T>
int desequilibrioAbinRec(const Abin<T> &abin, const typename Abin<T>::nodo &nodo);


int main()
{
    Abin<string> abin;

    ifstream fe("abin.dat");
    rellenarAbin(fe, abin);

    imprimirAbin(abin);
    cout << "El desequilibrio del arbol es: " << desequilibrioAbin(abin) << endl;
    return 0;
}

template <typename T>
int desequilibrioAbin(const Abin<T> &abin)
{
    if(abin.arbolVacioB())
        return 0;
    else
        return desequilibrioAbinRec(abin, abin.raizB());
}

template <typename T>
int desequilibrioAbinRec(const Abin<T> &abin, const typename Abin<T>::nodo &nodo)
{
    if(nodo == Abin<T>::NODO_NULO)
        return 0;
    else
        return max(max(abs(abin.alturaB(abin.hijoIzqdoB(nodo)) - abin.alturaB(abin.hijoDrchoB(nodo))),
            desequilibrioAbinRec(abin, abin.hijoIzqdoB(nodo))), desequilibrioAbinRec(abin, abin.hijoDrchoB(nodo)));
}
