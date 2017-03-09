#include <iostream>
#include "nodosCon3Nietos.hpp"
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

    cout << "numero de nodos con 3 nietos = "<< nodosCon3Nietos(B);


    return 0;


}
