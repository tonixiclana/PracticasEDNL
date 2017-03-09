#include <iostream>
#include "ejercicio2.h"


using namespace std;

int main()
{
    N=3; // va a ser una laberinto de 3 x 3casillas

    Lista<pared> lParedes;     //matriz bool de paredes
    GrafoP<size_t> laberinto(N*N);                  //van a hacer n*n nodos
    GrafoP<size_t> laberintoCopia(laberinto);
    size_t longitud;                //longitud del camino mas corto
    //definimos las casillas de entrada y salida
    casilla entrada(0,0), salida(2,2);

    //definimos las paredes
    pared a(casilla(0,0), casilla(0,1));
    pared b(casilla(1,1), casilla(1,2));
    pared c(casilla(1,1), casilla(2,1));

    //insertamos las paredes en la lista de paredes
    lParedes.insertar( a, lParedes.fin() );
    lParedes.insertar( b, lParedes.fin() );
    lParedes.insertar( c, lParedes.fin() );

    //probamos el programa
    cout << "el camino para resolver el laberinto es : " ;
    insCamino<size_t>(cout, calcularCamino(laberintoCopia, lParedes, entrada, salida, longitud) );

    cout << "\n longitud del camino mas corto:"<< longitud <<endl;


}
