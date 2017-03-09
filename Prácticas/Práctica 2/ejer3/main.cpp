#include <iostream>
#include "aritmetico.h"

using namespace std;

istream& operator >>(istream &i, nodoArit& n)
{
    cout << "Introducir valores para operador y despues para operando: ";
    i >> n.operador >> n.operando;
    i.ignore();
    return i;
}

ostream& operator <<(ostream &o,const nodoArit& n)
{
    o << n.operador  << n.operando;
    return o;
}

bool operator !=(const nodoArit& izq,const nodoArit& der)
{
    bool ret;
    if(izq.operador == der.operador && izq.operando == der.operando)
        ret = false;
    else
        ret = true;

return ret;
}

int main()
{
    char op;
    Abin<nodoArit> A{}, B{};
    //-----------------Entradas y salidas
    cout << "desea rellenar? S/N" ;
    cin >> op;
    if(op == 'S')
    {
        cout << "****Lectura del arbol binario A ****\n";
        rellenarAbin<nodoArit>(A, nodoArit('#',0));

        ofstream fs("abin.dat");
        imprimirAbin<nodoArit>(fs, A, '#');
        fs.close();
        cout << "\n *****arbol guardado en abin.dat\n";
    }

    cout << "*****Lectura del arbol binario A desde abin.dat****\n";
    ifstream fe("abin.dat");
    rellenarAbin<nodoArit>(fe, B);
    fe.close();
    //---------------- Entradas y salidas

    cout << "\n resultado : "<< aritmetica(B);

    //A.insertarRaizB()

    //rellenarAbin(B, )
}


