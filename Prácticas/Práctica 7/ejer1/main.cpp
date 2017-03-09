#include <iostream>
#include "ejercicio1.h"


using namespace std;

int main()
{
    GrafoP<unsigned int> Agencia("ejercicio1.txt");
    cout <<"Grafo de costes directos agencia: \n"<< Agencia << endl;

    typedef typename GrafoP<size_t>::vertice vertice;

    vertice O, D;
    size_t coste;

    viajeMasCaro(Agencia, O, D, coste);

    cout <<"El viaje mas caro es desde la ciudad: "<< O << " Hasta la ciudad "<< D << "Con un coste de: " << coste<< endl;




}
