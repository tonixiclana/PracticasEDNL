#include <iostream>
#include "ejercicio4.h"


using namespace std;

int main()
{
    //grafos de Zuelandia en situacion normal
	GrafoP<unsigned int> Zuelan("ejercicio4.txt");
	GrafoP<unsigned int> ZuelanGuerra(Zuelan);

	//carreteras cortadas
    carrCort[0][5] = true;     //de 0 a 5
    carrCort[3][1] = true;     //de 3 a 1
    //ciudades tomadas
    cTomadas[2] = true;        //ciudad 2 tomada
    cTomadas[4] = true;        //ciudad 4 tomada
    //capital
    capital = 3;

    cout <<"Zuelandia en situacion normal: \n"<< Zuelan << endl;

    cortarCarreteras(ZuelanGuerra);
    tomarCiudades(ZuelanGuerra);
    cout <<"Zuelandia en situacion belica sin controles en capital: \n"<< ZuelanGuerra << endl;

    cout <<"Matriz de costes minimos para viajar de una ciudad a otra en situacion belica con controles: \n"<< activarControlSeguridad(ZuelanGuerra) << endl;


}
