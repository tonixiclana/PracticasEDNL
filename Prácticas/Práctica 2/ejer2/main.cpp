#include <iostream>
#include "reflejado.hpp"        //versi�n especular
//#include "reflejado_por_nodos.hpp"      //versi�n por nodos
using namespace std;

int main()
{

    Abin<char> A{};
    //-----------------Entradas y salidas
    cout << "Rellene arbol A" ;

        cout << "****Lectura del arbol binario A ****\n";
        rellenarAbin<char>(A, '#');

        cout << "\n Introducido correctamente \n";


    imprimirAbin( reflejado(A) );

}
