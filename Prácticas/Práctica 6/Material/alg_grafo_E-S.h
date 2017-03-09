/*--------------------------------------------------------*/
/* alg_grafo_E-S.h                                        */
/*                                                        */
/* Operadores de inserción en flujos de salida para       */
/* visualizar los resultados de los algoritmos de grafos  */
/* implementados en alg_grafoMA.[h|cpp]                   */
/*                                                        */
/* Estructuras de Datos no Lineales                       */
/* ©2016 José Fidel Argudo                                */
/*--------------------------------------------------------*/
/*
Sobrecarga de operadores:

   ostream& operator <<(ostream& os, const Lista<Grafo::vertice>& L);
      Inserción de una lista de vértices de un grafo en un flujo
      de salida (para probar recorridos).

   template <>
   ostream& operator << <bool>(ostream& os, const matriz<bool>& m);
      Especialización para matriz<bool> del operador << para la
      clase genérica matriz<T> (para probar Warshall).

----------------------------------------------------------*/

#ifndef ALG_GRAFO_E_S_H
#define ALG_GRAFO_E_S_H

class Grafo;                         // grafo no ponderado
template <typename T> class matriz;  // matriz cuadrada
template <typename T> class Lista;

// Inserción de una Lista<Grafo::vertice> en un ostream (para probar recorridos)
std::ostream& operator <<(std::ostream& os, const Lista<Grafo::vertice>& L);

// Inserta una matriz<bool> en un flujo de salida (para probar Warshall)
template <>
std::ostream& operator << <bool>(std::ostream& os, const matriz<bool>& m);

#endif   // ALG_GRAFO_E_S_H
