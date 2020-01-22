#include "clsGrafico.h"
#include "clsHelper.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;
using std::setw;
using std::left;
//10x15
clsGrafico::clsGrafico(int x, int y, int vel)
{
    clsHelper help;
    SetX(x);
    SetY(y);
    SetVelocidad(vel);
    help.CompletarCadena(cuadrado);
}

void clsGrafico::Dibujar()
{
    system("cls");
    cout<<endl<<endl<<endl<<endl;
    for(int x = 0; x < 10; x++)
    {
        cout<<setw(30)<<left<<' ';
        for(int y = 0; y < 15; y++)
        {
            if(x == GetX() && y == GetY())
                cout<<'o';
            else
                cout<<cuadrado[x][y];
        }
        cout<<endl;
    }
}

void clsGrafico::Dibujar(char a)
{
    system("cls");
    cout<<endl<<endl<<endl<<endl;
    for(int x = 0; x < 10; x++)
    {
        cout<<setw(30)<<left<<' ';
        for(int y = 0; y < 15; y++)
        {
            if(x == GetX() && y == GetY())
                cout<<a;
            else
                cout<<cuadrado[x][y];
        }
        cout<<endl;
    }
}

void clsGrafico::Arriba()
{
    clsHelper h;    if(GetX()-1 < 0)
    {
        SetX(0);
        h.Esperar(GetVelocidad());
        Dibujar();
        return;
    }
    SetY(GetY()-1);
    h.Esperar(GetVelocidad());
    Dibujar();
}

void clsGrafico::Abajo()
{
    clsHelper h;
    if(GetX()+1 > 10)
    {
        SetX(9);
        h.Esperar(GetVelocidad());
        Dibujar();
        return;
    }
    SetX(GetX()+1);
    h.Esperar(GetVelocidad());
    Dibujar();
}

void clsGrafico::Derecha()
{
    clsHelper h;
    if(GetY()+1 > 14)
    {
        SetY(14);
        h.Esperar(GetVelocidad());
        Dibujar();
        return;
    }
    SetY(GetY()+1);
    h.Esperar(GetVelocidad());
    Dibujar();
}

void clsGrafico::Izquierda()
{
    clsHelper h;    if(GetY()-1 < 0)
    {
        SetY(0);
        h.Esperar(GetVelocidad());
        Dibujar();
        return;
    }
    SetY(GetY()-1);
    h.Esperar(GetVelocidad());
    Dibujar();
}
