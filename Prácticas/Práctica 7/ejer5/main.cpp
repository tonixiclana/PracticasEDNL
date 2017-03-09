#include <iostream>
#include "ejercicio5.h"


using namespace std;

//Se presupone que el coste a la misma ciudad es 0
int main()
{
    GrafoP<size_t> enCarretera("ejercicio5_carretera.txt");
    GrafoP<size_t> enTren("ejercicio5_tren.txt");
    GrafoP<size_t> enAvion("ejercicio5_avion.txt");

    size_t presupuesto;

    typename GrafoP<size_t>::vertice origen;

    presupuesto = 16;
    tipoAlergia alergia = TREN;
    origen = 2;

    cout << "costes directos carretera: " << endl;
    cout << enCarretera << endl;

    cout << "costes directos tren: " << endl;
    cout << enTren << endl;

    cout << "costes directos avion: " << endl;
    cout << enAvion << endl;

    cout << "posibles ciudades destino: " << endl;
    cout << posiblesCiudadesDestino(enCarretera, enTren, enAvion, presupuesto, alergia, origen) << endl;

}
