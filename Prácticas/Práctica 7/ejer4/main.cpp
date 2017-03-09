#include <iostream>
#include "ejercicio4.h"


using namespace std;

//Se presupone que el coste a la misma ciudad es 0
int main()
{
    numCamiones = 5;
    typename GrafoP<size_t>::vertice capital;

    GrafoP<size_t> Zuelan("ejercicio4.txt");
    matriz<parteTrabajo<size_t>> vPT(numCamiones);  //matriz de partes por cada camion, un camion puede tener 2  o mas partes en un mismo dia porque tenga clientes diferentes

    parteTrabajo<size_t> P1(0, 3);
    parteTrabajo<size_t> P2(1, 5);
    parteTrabajo<size_t> P3(2, 1);
    parteTrabajo<size_t> P4(4, 6);
    parteTrabajo<size_t> P5(5, 4);

    vPT[0][0] = P1;
    vPT[0][1] = P5;
    vPT[1][0] = P2;
    vPT[2][0] = P3;
    vPT[3][0] = P4;

    capital = 3;

    cout << "La matriz de costes directos de zuelandia es:" <<endl;
    cout << Zuelan <<endl;

    cout << "el numero de camiones disp es :" << endl;
    cout <<numCamiones<<endl;

    cout << "la capital y centro de distribucion es: " << endl;
    cout << capital << endl;

    cout << "las distancias recorridas por los camiones en el dia de hoy es: " << endl;
    cout << calcularDistCamiones(Zuelan, vPT, capital) <<endl;


}
