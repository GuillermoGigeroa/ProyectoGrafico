#include <iostream>
#include "clsGrafico.h"
#include "clsHelper.h"

using namespace std;

int main()
{
    clsGrafico g1(0,0,5);
    g1.Dibujar();
    g1.Abajo(10);
    g1.Derecha(15);
    g1.Arriba(10);
    g1.Izquierda(15);
    return 0;
}
