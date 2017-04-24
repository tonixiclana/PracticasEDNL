#include <iostream>
#include <fstream>
#include <string>
#include "../../TADS/ArbolBinario/ABIN_H2.0.h"
#include "../../TADS/ArbolBinario/abin_E-S.h"
/*
    * Consiste en buscar y contar los nodos que tienen 3 nietos ni 1+ ni 1-
*/
using namespace std;

template <typename T>
bool comprobarSucesoresRec(const Abin<T> &abin, const typename Abin<T>::nodo nodo0, const typename Abin<T>::nodo nodo1)
{
    if(nodo1 == Abin<T>::NODO_NULO)
        return true;
    else
        if(abin.hijoIzqdoB(nodo1) != Abin<T>::NODO_NULO && abin.hijoDrchoB(nodo1) != Abin<T>::NODO_NULO)
            if(abin.elemento(nodo0) < abin.elemento(nodo1) && abin.elemento(nodo0) < abin.elemento(nodo1))
                return comprobarSucesoresRec(abin, nodo0, abin.hijoIzqdoB(nodo1)) && comprobarSucesoresRec(abin, nodo0, abin.hijoDrchoB(nodo1));
            else
                return false;
        else
        if(abin.hijoIzqdoB(nodo1) == Abin<T>::NODO_NULO)
            if(abin.elemento(nodo0) < abin.elemento(nodo1))
                return comprobarSucesoresRec(abin, nodo0, abin.hijoDrchoB(nodo1));
            else
                return false;
        else
        if(abin.hijoDrchoB(nodo1) == Abin<T>::NODO_NULO)
            if(abin.elemento(nodo0) < abin.elemento(nodo1))
                return comprobarSucesoresRec(abin, nodo0, abin.hijoIzqdoB(nodo1));
            else
                return false;
}

template <typename T>
bool comprobarAntecesoresRec(const Abin<T> &abin, const typename Abin<T>::nodo nodo0, const typename Abin<T>::nodo nodo1)
{
    if(nodo1 == Abin<T>::NODO_NULO)
        return true;
    else
        if(abin.elemento(nodo0) > abin.elemento(nodo1))
            return (comprobarAntecesoresRec(abin, nodo0, abin.padreB(nodo1)));
        else
            return false;
}


template <typename T>
bool esProspero(const Abin<T> &abin, const typename Abin<T>::nodo nodo)
{
    if(abin.padreB(nodo) == Abin<T>::NODO_NULO)
        return false;
    else
    if(abin.hijoIzqdoB(nodo) == Abin<T>::NODO_NULO && abin.hijoDrchoB(nodo) == Abin<T>::NODO_NULO)
        return false;
    else
        return comprobarAntecesoresRec(abin, nodo, abin.padreB(nodo)) && comprobarSucesoresRec(abin, nodo, abin.hijoIzqdoB(nodo))
            && comprobarSucesoresRec(abin, nodo, abin.hijoDrchoB(nodo));

}


template <typename T>
unsigned contarProsperosRec(const Abin<T> &abin, const typename Abin<T>::nodo nodo)
{
    if(nodo == Abin<T>::NODO_NULO)
        return 0;
    else
        if(esProspero(abin, nodo))
            return 1 + contarProsperosRec(abin, abin.hijoIzqdoB(nodo)) + contarProsperosRec(abin, abin.hijoDrchoB(nodo));
        else
            return contarProsperosRec(abin, abin.hijoIzqdoB(nodo)) + contarProsperosRec(abin, abin.hijoDrchoB(nodo));
}

template <typename T>
unsigned contarProsperos(const Abin<T> &abin)
{
    if(abin.arbolVacioB())
        return 0;
    else
        return contarProsperosRec(abin, abin.raizB());
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

    //cout << contarDescendencia(B, B.raizB(), 1) << endl;
    cout << "numero de nodos prosperos = "<< contarProsperos(B);


}
