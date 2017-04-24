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
int contarDescendenciaRec(const Abin<T> &abin, const typename Abin<T>::nodo nodo, size_t grado);
template <typename T>
int contarDescendencia(const Abin<T> &abin, const typename Abin<T>::nodo nodo, size_t grado);
template <typename T>
int numeroNodosTriNietosRec(const Abin<T> &abin, const typename Abin<T>::nodo nodo);
template <typename T>
int numeroNodosTriNietos(const Abin<T> &abin);


int main()
{
    char op;
    Abin<char> A{}, B{};
    //-----------------Entradas y salidas
    cout << "desea rellenar? S/N" ;
    cin >> op;
    if(op == 'S')
    {
        cout << "****Lectura del arbol binario A ****\n";
        rellenarAbin<char>(A, '#');

        ofstream fs("abin.dat");
        imprimirAbin<char>(fs, A, '#');
        fs.close();
        cout << "\n *****arbol guardado en abin.dat\n";
    }

    cout << "*****Lectura del arbol binario A desde abin.dat****\n";
    ifstream fe("abin.dat");
    rellenarAbin<char>(fe, B);
    fe.close();
    imprimirAbin(B);

    //cout << contarDescendencia(B, B.raizB(), 1) << endl;
    cout << "numero de nodos con 3 nietos = "<< numeroNodosTriNietos(B);


}

template <typename T>
int contarDescendenciaRec(const Abin<T> &abin, const typename Abin<T>::nodo nodo, size_t grado)
{
    if(nodo == Abin<T>::NODO_NULO)
        return 0;
    else
    if(grado == 0)  //si grado = 0 desde el principio, se genera pregunta ¿descendecia de grado 0?, seria el propio nodo que cuenta 1
        return 1;
    else
        return contarDescendenciaRec(abin, abin.hijoIzqdoB(nodo), grado - 1)
            + contarDescendenciaRec(abin, abin.hijoDrchoB(nodo), grado - 1);
}

template <typename T>
int contarDescendencia(const Abin<T> &abin, const typename Abin<T>::nodo nodo, size_t grado)
{
    if(abin.arbolVacioB())
        return 0;
    else
    if(grado == 0)
        return 0;
    else
        return contarDescendenciaRec(abin, nodo, grado);
}

template <typename T>
int numeroNodosTriNietosRec(const Abin<T> &abin, const typename Abin<T>::nodo nodo)
{
    if(nodo == Abin<T>::NODO_NULO)
        return 0;
    else
    if(contarDescendencia(abin, nodo, 2) == 3)
        return 1 + numeroNodosTriNietosRec(abin, abin.hijoIzqdoB(nodo)) +
            numeroNodosTriNietosRec(abin, abin.hijoDrchoB(nodo));
    else
        return numeroNodosTriNietosRec(abin, abin.hijoIzqdoB(nodo)) +
            numeroNodosTriNietosRec(abin, abin.hijoDrchoB(nodo));
}

template <typename T>
int numeroNodosTriNietos(const Abin<T> &abin)
{
    if(abin.arbolVacioB())
        return 0;
    else
        return numeroNodosTriNietosRec(abin, abin.raizB());
}
