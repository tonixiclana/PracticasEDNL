#include "ArBinBus.h"
#include "E_S_BUS_.h"
#include "operabus.hpp"
#include <iostream>
#include <stdlib.h>
#include <cassert>

using namespace std;

int main(){
int operacion;
do {
cout << "Introduzca que desea hacer " << endl;
cout << " 1. Union conjuntos " << endl;
cout << " 2. Interseccion conjuntos " << endl;
cout << " 3. Poda de un arbol " << endl;
cin >> operacion;
switch(operacion) {
    case 1: {
     int fin;
     cout << "Introduzca el elemento que se usara como bandera para rellenar el arbol A" << endl;
     cin >> fin;
     Abb<int> A;
     leerAbb(A,fin);
     cout << "Introduzca el elemento que se usara como bandera para rellenar el arbol B" << endl;
     cin >> fin;
     Abb<int> B;
     leerAbb(A,fin);
     Abb<int> C ;
     //C = unionconjuntos(A,B);
     cout << " la union de esos 2 conjuntos es " << endl;
     imprimirAbb(C);
  }break;
  case 2: {
    int fin;
     cout << "Introduzca el elemento que se usara como bandera para rellenar el arbol A" << endl;
     cin >> fin;
     Abb<int> A;
     leerAbb(A,fin);
     cout << "Introduzca el elemento que se usara como bandera para rellenar el arbol B" << endl;
     cin >> fin;
     Abb<int> B;
     leerAbb(B,fin);
     Abb<int> C ;
     //C = interseccionconjuntos(A,B);
     cout << " la interseccion de esos 2 conjuntos es " << endl;
     imprimirAbb(C);
  }break;
   case 3: {
    int fin;
     cout << "Introduzca el elemento que se usara como bandera para rellenar el arbol A" << endl;
     cin >> fin;
     Abb<int> A;
     leerAbb(A,fin);
     cout << "introduzca el elemento a podar " << endl;
     int elto;
     cin >> elto;
     //poda(A,elto) ;
     cout << " El arbol con la poda es " << endl;
     imprimirAbb(A);
  }break;
   }//switch
cout << "Pulse 1 si desea realizar otra operacion " << endl;
cin >> operacion;
 }while(operacion==1);
return 0;
}
