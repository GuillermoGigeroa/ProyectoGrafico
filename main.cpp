#include <iostream>
#include "clsGrafico.h"
#include "clsPersistencia.h"
#include <stdio.h>
#include <conio.h>

using namespace std;

int main()
{
    //int op;do{op=getch();printf("%i\n",op);}while(op != 174126541);return 0;
    clsPersistencia s;
    clsGrafico g1(0,0,5);
    s.Cargar(&g1);

    ///MOVIMIENTO DE PRUEBA
    g1.Inicio();
    g1.Marcar();
    g1.SetModoLinea(true);
    g1.Abajo(19);
    g1.Derecha(74);
    g1.Arriba(19);
    g1.Izquierda(73);
    ///MOVIMIENTO DE PRUEBA

    g1.DetectarTeclado();
    s.Guardar(&g1);
    return 0;
}
