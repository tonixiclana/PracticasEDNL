#include <iostream>
#include "ejercicio3.h"


using namespace std;

int main()
{
    size_t N, cantProd;
    double minCosteTotal;
    typename GrafoP<double>::vertice origen;

    N = 8;
    cantProd = 75;
    minCosteTotal = 0;
    origen = 3;

    vector<size_t>  capCiud = {50,50,25,0,50,30,40,30};

    vector<double> subvencion = {0.05,0.5,0.5,0,0.25,0.2,0.2,0.4};

    GrafoP<double> mapaDistribucion("ejercicio3.txt");
    GrafoP<double> mapaDistribucionCop(mapaDistribucion);

    cout <<"matriz de costes directos ciudades: \n"<< mapaDistribucion << endl;

    cout << "cantidades a almacenar en cada ciudad:" << endl;
    cout << distribuirProductos(mapaDistribucion, cantProd, origen, capCiud, subvencion, minCosteTotal) << endl;
    cout << "coste min total de la operacion:" << endl;
    cout << minCosteTotal << endl;

}
