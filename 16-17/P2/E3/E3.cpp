#include <iostream>
#include <fstream>
#include <string>
#include "../../TADS/ArbolBinario/ABIN_H2.0.h"
#include "../../TADS/ArbolBinario/abin_E-S.h"

using namespace std;

struct nodoArit
{
    char operador;
    double operando;
    nodoArit(char operador = '#', double operando = 0) : operador(operador), operando(operando){}
};

double resultadoAbinAritRec(const Abin<nodoArit> abin, Abin<nodoArit>::nodo nodo);
double resultadoAbinArit(const Abin<nodoArit> abin);

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

    cout << "\n resultado : "<< resultadoAbinArit(B);

}

double resultadoAbinAritRec(const Abin<nodoArit> abin, Abin<nodoArit>::nodo nodo)
{
    if(abin.elemento(nodo).operador != '#')
        switch(abin.elemento(nodo).operador)
        {
            case '*':
                return resultadoAbinAritRec(abin, abin.hijoIzqdoB(nodo))
                    * resultadoAbinAritRec(abin, abin.hijoDrchoB(nodo));
                break;
            case '+':
                return resultadoAbinAritRec(abin, abin.hijoIzqdoB(nodo))
                    + resultadoAbinAritRec(abin, abin.hijoDrchoB(nodo));
                break;
            case '-':
                return resultadoAbinAritRec(abin, abin.hijoIzqdoB(nodo))
                    - resultadoAbinAritRec(abin, abin.hijoDrchoB(nodo));
                break;
            case '/':
                return resultadoAbinAritRec(abin, abin.hijoIzqdoB(nodo))
                    / resultadoAbinAritRec(abin, abin.hijoDrchoB(nodo));
                break;
        }
    else
    {
        cout << abin.elemento(nodo).operando << endl;
        return abin.elemento(nodo).operando;
    }
}

double resultadoAbinArit(const Abin<nodoArit> abin)
{
    if(abin.arbolVacioB())
        return 0;
    else
        return resultadoAbinAritRec(abin, abin.raizB());
}


