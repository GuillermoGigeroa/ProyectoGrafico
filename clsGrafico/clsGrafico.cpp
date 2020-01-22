#include "clsGrafico.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;
using std::setw;
using std::left;
//10x15
clsGrafico::clsGrafico(int x, int y, int vel)
{
    SetX(x);
    SetY(y);
    SetVelocidad(vel);
    CompletarCadena(cuadrado);
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
    if(GetX()-1 < 0)
    {
        SetX(0);
    }
    else
    {
        SetX(GetX()-1);
    }
    Esperar(GetVelocidad());
    Dibujar();
}

void clsGrafico::Arriba(int cant)
{
    for(int x = 0; x < cant; x++)
    {
        if(GetX()-1 < 0)
        {
            SetX(0);
        }
        else
        {
            SetX(GetX()-1);
        }
        Esperar(GetVelocidad());
        Dibujar();
    }
}

void clsGrafico::Abajo()
{
    if(GetX()+1 > 9)
    {
        SetX(9);
    }
    else
    {
        SetX(GetX()+1);
    }
    Esperar(GetVelocidad());
    Dibujar();
}

void clsGrafico::Abajo(int cant)
{
    for(int x = 0; x < cant; x++)
    {
        if(GetX()+1 > 9)
        {
            SetX(9);
        }
        else
        {
            SetX(GetX()+1);
        }
        Esperar(GetVelocidad());
        Dibujar();
    }
}

void clsGrafico::Derecha()
{
    if(GetY()+1 > 14)
    {
        SetY(14);
    }
    else
    {
        SetY(GetY()+1);
    }
    Esperar(GetVelocidad());
    Dibujar();
}

void clsGrafico::Derecha(int cant)
{
    for(int x = 0; x < cant; x++)
    {
        if(GetY()+1 > 14)
        {
            SetY(14);
        }
        else
        {
            SetY(GetY()+1);
        }
        Esperar(GetVelocidad());
        Dibujar();
    }
}

void clsGrafico::Izquierda()
{
    if(GetY()-1 < 0)
    {
        SetY(0);
    }
    else
    {
        SetY(GetY()-1);
    }
    Esperar(GetVelocidad());
    Dibujar();
}

void clsGrafico::Izquierda(int cant)
{
    for(int x = 0; x < cant; x++)
    {
        if(GetY()-1 < 0)
        {
            SetY(0);
        }
        else
        {
            SetY(GetY()-1);
        }
        Esperar(GetVelocidad());
        Dibujar();
    }
}

void clsGrafico::CompletarCadena(char cuadrado[10][15])
{
    for(int x = 0; x < 10; x++)
    {
        for(int y = 0; y < 15; y++)
        {
            cuadrado[x][y] = ' ';
        }
        cuadrado[x][14] = '\0';
    }
}

void clsGrafico::CompletarCadena(char cuadrado[10][15], char a)
{
    for(int x = 0; x < 10; x++)
    {
        for(int y = 0; y < 15; y++)
        {
            cuadrado[x][y] = a;
        }
        cuadrado[x][14] = '\0';
    }
}

void clsGrafico::Escribir(char cuadrado[10][15])
{
    cout<<endl<<endl<<endl<<endl;
    for(int x = 0; x < 10; x++)
    {
        cout<<setw(30)<<left<<' ';
        for(int y = 0; y < 15; y++)
        {
            cout<<cuadrado[x][y];
        }
        cout<<endl;
    }
}

void clsGrafico::Esperar(int ms)
{
    Sleep(ms);
}
