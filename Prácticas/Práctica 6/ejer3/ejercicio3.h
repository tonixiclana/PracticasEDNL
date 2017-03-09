#include "alg_grafoPMC.h"
#include <iostream>


template <typename tCoste> bool esAciclico(const GrafoP<tCoste>& G)
{
	matriz<typename GrafoP<tCoste>::vertice> P;
	matriz<tCoste> M = floydModificado(G,P);
    std::cout << M <<std::endl;
    std::cout << P <<std::endl;
	bool bandera = true;

	for(int i=0; i<M.dimension(); i++){
		if(M[i][i] != GrafoP<tCoste>::INFINITO)
			bandera = false;
	}

	return bandera;
}
