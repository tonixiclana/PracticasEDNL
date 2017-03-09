#include <iostream>
#include "ejer5.h"
#include "alg_grafoP_E-S.h"

using namespace std;

int main()
{
    vector<typename GrafoP<size_t>::vertice> P;
    GrafoP<size_t> G("ejercicio5.txt");
    vector<size_t> D;

    D = Dijkstra(G, 0, P);
    cout << G <<endl;
    cout << D << endl;

    cout << "Hello world!" << endl;
    return 0;
}


