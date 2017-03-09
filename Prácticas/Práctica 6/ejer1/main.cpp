#include <iostream>
#include "ejercicio1.h"
#include "alg_grafoP_E-S.h"

using namespace std;

int main()
{
	string a = "ejercicio1.txt";
	GrafoP<unsigned int> G(a);
	matriz<unsigned int> F(G.numVert());
	matriz<typename GrafoP<unsigned int>::vertice > Fp(G.numVert());

	F = Floyd(G, Fp);               //Hayamos la matriz de costes minimos para poder encontrar el pseudocentro

	cout << "matriz de costes:\n"<< F;

	int diametro = diametroGrafoP(G);
	cout << "El diametro es: " << diametro << endl;
}
