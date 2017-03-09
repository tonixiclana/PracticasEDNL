#include <iostream>
#include <algorithm>
#include "ABIN_H.h"
//#include "ABIN_VEC0_H.h"
#include "abin_E-S.h"
#include "recorridos_ABIN.h"
//#include "Ejer1.h"
//#include "ejer2.h"
//#include "Ejer3.h"
#include "Ejer7.h"

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
        imprimirAbin(fs, A, '#');
        fs.close();
        cout << "\n *****arbol guardado en abin.dat\n";
    }

    cout << "*****Lectura del arbol binario A desde abin.dat****\n";
    ifstream fe("abin.dat");
    rellenarAbin<char>(fe, B);
    fe.close();

    cout << "\n ****Mostrar árbol binario B*****\n";
    imprimirAbin(B);
//-----------------------------------------------------------------
    //Pruebas ejercicios

    //Ejer1
    //cout << "\n" << ejer1(B, B.raizB());

    //Ejer2
    //cout << "\n" << alturaB(B, B.raizB());

    //Ejer 3
    //cout << "\n" << profundidadB(B, B.hijoIzqdoB( B.raizB() ));

    //Ejer 4 y 5
    //cout << "altura de arbol: " << B.alturaB( B.raizB() )<< "profundidad de nodo: " << B.profundidadB( B.hijoIzqdoB(B.raizB() ) ) ;

    //Ejer 6
    //cout << "desequilibrio: " << ejer6(B, B.raizB());

    //Ejer 7
    cout << "pseudocompleto: " << ejer7(B);

    cout << " \n Fin de la transmision" ;
    return 0;
}
