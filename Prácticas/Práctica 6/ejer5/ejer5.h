#include "grafoPLA.h"
// Suma de costes (Dijkstra y Floyd)
template <typename tCoste> tCoste suma(tCoste x, tCoste y)
{
   const tCoste INFINITO = GrafoP<tCoste>::INFINITO;
   if (x == INFINITO || y == INFINITO)
      return INFINITO;
   else
      return x + y;
}


template <typename tCoste>
vector<tCoste> Dijkstra(const GrafoP<tCoste>& G,
                        typename GrafoP<tCoste>::vertice origen,
                        vector<typename GrafoP<tCoste>::vertice>& P)
// Calcula los caminos de coste m�nimo entre origen y todos los
// v�rtices del grafo G. En el vector D de tama�o G.numVert()
// devuelve estos costes m�nimos y P es un vector de tama�o
// G.numVert() tal que P[i] es el �ltimo v�rtice del camino
// de origen a i.
{
   typedef typename GrafoP<tCoste>::vertice vertice;
   vertice v, w;
   const size_t n = G.numVert();
   vector<bool> S(n, false);                  // Conjunto de v�rtices vac�o.
   vector<tCoste> D(n, GrafoP<tCoste>::INFINITO);                          // inicializamos los coste minimos a infinito.

   // Iniciar D y P con caminos directos desde el v�rtice origen.
    typedef typename GrafoP<tCoste>::vertice_coste vC;
    vC vertCost ;
    typename Lista<vC>::posicion p;

   for( p= G.adyacentes(origen).primera(); p != G.adyacentes(origen).fin(); p = G.adyacentes(origen).siguiente(p) )
   {
       D[G.adyacentes(origen).elemento(p).v] = G.adyacentes(origen).elemento(p).c;
   }
    D[origen] = 0;                              // Coste origen-origen es 0.
    P = vector<vertice>(n, origen);

   // Calcular caminos de coste m�nimo hasta cada v�rtice.
   S[origen] = true;                          // Incluir v�rtice origen en S.

   for (size_t i = 1; i <= n-2; i++) {          //Se hacen n-2 iteraciones(noase porque)
      // Seleccionar v�rtice w no incluido en S
      // con menor coste desde origen.
      tCoste costeMin = GrafoP<tCoste>::INFINITO;
      for (v = 0; v < n; v++)
         if (!S[v] && D[v] <= costeMin) {
            costeMin = D[v];
            w = v;
         }
      S[w] = true;                          // Incluir v�rtice w en S.
      // Recalcular coste hasta cada v no incluido en S a trav�s de w.
      for (v = 0; v < n; v++)
         if (!S[v])
        {
            vertCost.v = v;
            p = G.adyacentes(w).buscar(vertCost);

            if(p != G.adyacentes(w).fin())
            {
                tCoste Owv = suma( D[w], G.adyacentes(w).elemento( p ).c );
                if (Owv < D[v]) {
                    D[v] = Owv;
                    P[v] = w;
                }
            }
         }
   }

   return D;
}
