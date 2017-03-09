#include "alg_grafoPMC.h"
#include "alg_grafoP_E-S.h"


typedef typename GrafoP<size_t>::vertice casilla;
casilla entrada, salida;

template <typename tCoste>
void colocarParedes(GrafoP<tCoste> &G, matriz<bool> paredes)
{
    for(casilla i=0; i<G.numVert(); i++)
        for(casilla j=0; j<G.numVert(); j++)

            if(paredes[i][j] == true)
                G[i][j] = GrafoP<tCoste>::INFINITO;
}

template <typename tCoste>
typename GrafoP<tCoste>::tCamino caminoCorto(GrafoP<tCoste> &G, tCoste &len )
{
    vector<tCoste> vCosteMin(G.numVert());
    vector<casilla> vCaminMin(G.numVert());
    typename GrafoP<tCoste>::tCamino camin;

    vCosteMin = Dijkstra(G, entrada, vCaminMin);

    camin = camino<tCoste>(entrada, salida, vCaminMin);

    len = vCosteMin[salida];
    return camin;
/*
    for(casilla i=0; i<G.numVert(); i++)
        for(casilla j=0; j<G.numVert(); j++)*/

}


/*template <typename tCoste>
void viajeMasCaro(const GrafoP<tCoste> &G, typename GrafoP<tCoste>::vertice & origen, typename GrafoP<tCoste>::vertice & dest, tCoste &coste )
{
    typedef typename GrafoP<tCoste>::vertice vertice;
    coste = 0;
    matriz<unsigned int> McF(G.numVert());
	matriz<unsigned int> McamF(G.numVert());

	McF = Floyd(G, McamF );
    std::cout <<"Grafo de costes minimos agencia: \n"<< McF << std::endl;

    for(vertice i = 0; i<G.numVert(); i++)
        for(vertice j = 0; j<G.numVert(); j++)
        {
            if(McF[i][j] > coste)
            {
                coste = McF[i][j];
                origen = i;
                dest = j;
            }

        }
}*/





