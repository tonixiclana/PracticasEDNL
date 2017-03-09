#include <iostream>
#include "ejercicio2.h"


using namespace std;

int main()
{
    size_t N=3*3; // va a ser una laberinto de 3 x 3casillas
    matriz<bool> paredes(N, false);     //matriz bool de paredes
    size_t longitud;                //longitud del camino mas corto

    GrafoP<size_t> laberinto("ejercicio2.txt");
    GrafoP<size_t> laberintoCopia(laberinto);

    //declaramos las paredes
    paredes[0][1] = true;
    paredes[4][5] = true;
    paredes[7][8] = true;
    paredes[3][4] = true;

    //declaramos la casilla de entrada y de salida
    entrada = 0;
    salida = 8;


    matriz<size_t> Mv(laberinto.numVert());
    cout <<"matriz de costes directos tablero original: \n"<< laberinto << endl;

    colocarParedes(laberintoCopia, paredes);
    cout <<"matriz de costes directos tablero con paredes: \n"<< laberintoCopia << endl;
    cout <<"vector de caminos de origen a todos tablero con paredes: \n" << endl;

    cout << "el camino para resolver el laberinto es : " ;
    insCamino<size_t>(cout, caminoCorto(laberintoCopia, longitud) );

    cout << "\n longitud del camino mas corto:"<< longitud <<endl;

    //cout <<"Grafo de costes directos agencia: \n"<< Floyd(tablero, Mv) << endl;






}
