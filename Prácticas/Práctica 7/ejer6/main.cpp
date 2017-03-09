#include <iostream>
#include "ejercicio6.h"


using namespace std;

//Se presupone que el coste a la misma ciudad es 0
int main()
{
    GrafoP<size_t> enBus("ejercicio6_bus.txt");
    GrafoP<size_t> enTren("ejercicio6_tren.txt");

    typename GrafoP<size_t>::vertice ciudadTrans;

    ciudadTrans = 1;

    cout << "costes directos bus: " << endl;
    cout << enBus << endl;

    cout << "costes directos tren: " << endl;
    cout << enTren << endl;

    cout << "matriz de costes minimos: " << endl;

    cout << tarifaMin(enBus, enTren, ciudadTrans) << endl;

}
