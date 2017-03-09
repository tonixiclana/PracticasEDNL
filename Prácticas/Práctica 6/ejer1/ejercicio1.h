#include "alg_grafoPMC.h"

using namespace std;

template <typename tCoste>
typename GrafoP<tCoste>::vertice Pseudocentro(const matriz<tCoste> Mc, tCoste &diametro)
{
	tCoste dNodoLeg[2] = {0,0};         //vector con la distancia a los 2 nodos mas lejanos
	tCoste diametroMin = GrafoP<tCoste>::INFINITO ;          //La minima distancia que es suma de las distancias hacia los 2 nodos mas lejanos
	typename GrafoP<tCoste>::vertice pseudoCentro;

	for(size_t i=0; i < Mc.dimension(); i++)        //iteramos todos los nodos
    {
        for(size_t u=0; u < Mc.dimension(); u++)        //iteramos las distancias de un nodo i hasta todos sus indicentes buscando las 2 mas grandes
        {
            if(Mc[i][u] > dNodoLeg[0])
            {
                dNodoLeg[1] = dNodoLeg[0];
                dNodoLeg[0] = Mc[i][u];
            }
            else
                if(Mc[i][u] >= dNodoLeg[1])
                    dNodoLeg[1] = Mc[i][u];
        }

        if(dNodoLeg[0]+dNodoLeg[1] < diametroMin)
        {
            diametroMin = dNodoLeg[0]+dNodoLeg[1];
            pseudoCentro = i;
        }
        dNodoLeg[0] = 0;
        dNodoLeg[1] = 0;

    }

    diametro = diametroMin;
	return pseudoCentro;
}

template <typename tCoste> tCoste diametroGrafoP(const GrafoP<tCoste>& G)
{
	matriz<typename GrafoP<tCoste>::vertice> P;
	matriz<tCoste> McostesMin = Floyd(G,P);
	tCoste diametroGrafoP;
	typename GrafoP<tCoste>::vertice pseudoCentro = Pseudocentro(McostesMin, diametroGrafoP);

	cout << "el nodo pseudocentro es: " << pseudoCentro << endl;

	return diametroGrafoP;
}
