#include <iostream>
#include "AGEN_H.h"
#include "agen_E-S.h"
#include "poda.hpp"

using namespace std;

int main()
{
   Agen<char> A, B;
   char op;
   //-----------------Entradas y salidas
    cout << "desea rellenar? S/N" ;
    cin >> op;
    if(op == 'S')
    {
        cout << "****Lectura del arbol general A ****\n";
        rellenarAgen<char>(A, '#');

        ofstream fs("abin.dat");
        imprimirAgen<char>(fs, A, '#');
        fs.close();
        cout << "\n *****arbol guardado en abin.dat\n";
    }

    cout << "*****Lectura del arbol binario A desde abin.dat****\n";
    ifstream fe("abin.dat");
    rellenarAgen<char>(fe, B);
    fe.close();
    cout << "el arbol leido de abin.dat es: " << endl;
    imprimirAgen(B);

    podarNodo(B, 'f');

cout << "el resultado de la poda: " << endl;
    imprimirAgen(B);

//cout << "la altura del nodo g en ese arbol es: " << alturaNodo(B, B.raiz()->hizq );
//Lista<int> L;

return 0;
}
