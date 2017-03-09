#include "similares.hpp"
#include <iostream>


using namespace std;

int main()
{
    char op;
    Abin<char> A{}, B{};
    //-----------------Entradas y salidas
    cout << "Rellene arbol A" ;

        cout << "****Lectura del arbol binario A ****\n";
        rellenarAbin<char>(A, '#');

        cout << "\n Introducido correctamente \n";


    cout << "Rellene arbol B" ;

        cout << "****Lectura del arbol binario B ****\n";
        rellenarAbin<char>(B, '#');

        cout << "\n Introducido correctamente \n";

    cout << similares(A, B);

}
