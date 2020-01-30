#include <iostream>
#include "clsGrafico.h"
///#include <stdio.h>
///#include <conio.h>

using namespace std;

int main()
{
    ///int op;do{op=getch();printf("%i\n",op);}while(op != 174126541);return 0;
    clsGrafico g1;

    if(!g1.Cargar())
        g1.InicializarTodo();
    g1.IniciarJuego();
    g1.Guardar();

    return 0;
}
