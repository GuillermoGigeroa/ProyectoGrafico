#include <iostream>
#include "clsGrafico.h"
#include <stdio.h>
#include <conio.h>

using namespace std;

int main()
{
    clsGrafico g1(0,0,30);
    g1.Dibujar();
    g1.DetectarTeclado();
    return 0;
}
