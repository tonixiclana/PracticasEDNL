#include <iostream>
#include "ejercicio3.h"
#include "alg_grafoP_E-S.h"

using namespace std;

int main()
{
	GrafoP<unsigned int> G("ejercicio3.txt");

	if(esAciclico(G))
		cout << "Obtiene subvencion." << endl;
	else
		cout << "No obtiene subvencion." << endl;



}
