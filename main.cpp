#include <iostream>
#include "clsGrafico.h"
#include<stdio.h>
#include<conio.h>

using namespace std;

int main()
{
    clsGrafico g1(0,0,20);
    g1.Dibujar();
    int op = 0;
    while (op != 174126541)
    {
        op=getch();
        switch (op)
        {
            case 72:
                {
                    g1.Arriba();
                }break;
            case 75:
                {
                    g1.Izquierda();
                }break;
            case 77:
                {
                    g1.Derecha();
                }break;
            case 80:
                {
                    g1.Abajo();
                }break;
            default:
                {

                }break;
        }
    }
    return 0;
}
