#include <iostream>
#include "nodosCon4Descendientes.hpp"
using namespace std;

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

    cout << "numero de nodos con 4 descendientes = "<< nodosCon4Descendientes(B);


    return 0;


}
