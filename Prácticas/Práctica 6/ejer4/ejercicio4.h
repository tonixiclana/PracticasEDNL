#include "alg_grafoPMC.h"
#include "alg_grafoP_E-S.h"

//configuracion de zuelandia
size_t nCiudades = 6;
vector<bool> cTomadas(nCiudades, false);

matriz<bool> carrCort(nCiudades, false);

GrafoP<size_t>::vertice capital;
//-------------------------------


template <typename tCoste>
void cortarCarreteras( GrafoP<tCoste> &zuelan)
{
    for(typename GrafoP<tCoste>::vertice i=0; i< zuelan.numVert(); i++)
        for(typename GrafoP<tCoste>::vertice u=0; u< zuelan.numVert(); u++)
            if(carrCort[i][u])
                zuelan[i][u] = GrafoP<tCoste>::INFINITO;
}

template <typename tCoste>
void tomarCiudades(GrafoP<tCoste> &zuelan)
{
    for(typename GrafoP<tCoste>::vertice i=0; i< zuelan.numVert(); i++)
            if(cTomadas[i])
            {
                for(typename GrafoP<tCoste>::vertice u=0; u< zuelan.numVert(); u++)
                {
                    zuelan[u][i] = GrafoP<tCoste>::INFINITO;    //cortamos los caminos de llegada
                    zuelan[i][u] = GrafoP<tCoste>::INFINITO;    //cortamos los caminos de salida
                }
            }
}

template <typename tCoste>
matriz<tCoste> activarControlSeguridad(GrafoP<tCoste> &zuelan)
{
    //matriz de coste minimo de ciudades y matriz de vertices intermedios
    matriz<tCoste> Mc(zuelan.numVert());
    matriz<tCoste> Pf(zuelan.numVert());

    //vectores de coste minimo para dijkstra
    vector<tCoste> Vc;
    vector<tCoste> Vc2;
    vector<typename GrafoP<tCoste>::vertice> Pd;

    std::cout <<"Matriz de costes en guerra antes de la aplicar controles de seguridad: \n"<< Floyd(zuelan, Pf) <<std::endl;

    Vc = Dijkstra(zuelan, capital, Pd);     //hacemos dijkstra para calcular las distancias minimas desde la capi a todo lao
    Vc2 = DijkstraInv(zuelan, capital, Pd); //hacemos dijkstra inv para calcula el otro tramo, de cualquier origen a la capi
    for(typename GrafoP<tCoste>::vertice i=0; i< zuelan.numVert(); i++)
    {
        for(typename GrafoP<tCoste>::vertice u=0; u< zuelan.numVert(); u++)
        {
                   if(i==u)
                        Mc[i][u] = 0;
                    else
                        Mc[i][u] = suma(Vc[u], Vc2[i]);
        }
    }

return Mc;

}




