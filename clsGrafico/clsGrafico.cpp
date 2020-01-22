#include "clsGrafico.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
using namespace std;
using std::setw;
using std::left;

clsGrafico::clsGrafico(int x, int y, int vel)
{
    SetX(x);
    SetY(y);
    SetVelocidad(vel);
    CompletarCadena(cuadrado);
    Dibujar();
}

void clsGrafico::Dibujar()
{
    char a = '0';
    system("cls || clear");
    cout<<setw(30)<<left<<' '<<" GigeroaBlack"<<endl;
    LineaInicial();
    for(int x = 0; x < FILAS; x++)
    {
        cout<<setw(MARGEN_IZQUIERDO)<<left<<'|';///FILA DE RAYAS AL PRINCIPIO
        for(int y = 0; y < COLUMNAS; y++)
        {
            if(x == GetX() && y == GetY())
                cout<<a;
            else
                cout<<cuadrado[x][y];
        }
        cout<<'|'<<endl;
    }
    LineaFinal();
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
    if(GetX()+1 > FILAS - 1)
    {
        SetX(FILAS - 1);
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
        if(GetX()+1 > FILAS - 1)
        {
            SetX(FILAS);
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
    if(GetY()+1 > COLUMNAS - 2)
    {
        SetY(COLUMNAS - 2);
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
        if(GetY()+1 > COLUMNAS - 2)
        {
            SetY(COLUMNAS - 2);
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

void clsGrafico::CompletarCadena(char cuadrado[FILAS][COLUMNAS])
{
    for(int x = 0; x < FILAS; x++)
    {
        for(int y = 0; y < COLUMNAS; y++)
        {
            cuadrado[x][y] = ' ';
        }
        cuadrado[x][COLUMNAS - 1] = '\0';
    }
}

void clsGrafico::CompletarCadena(char cuadrado[FILAS][COLUMNAS], char a)
{
    for(int x = 0; x < FILAS; x++)
    {
        for(int y = 0; y < COLUMNAS; y++)
        {
            cuadrado[x][y] = a;
        }
        cuadrado[x][COLUMNAS - 1] = '\0';
    }
}

void clsGrafico::Escribir(char cuadrado[FILAS][COLUMNAS])
{
    cout<<endl<<endl;
    for(int x = 0; x < FILAS; x++)
    {
        cout<<setw(30)<<left<<' ';
        for(int y = 0; y < COLUMNAS; y++)
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

void clsGrafico::DetectarTeclado()
{
    /*
    op=getch();
    printf("%i\n",op);
    return 0;
    */
    int op = 0;
    while (op != 174126541)
    {
        op=getch();
        switch (op)
        {
            case 72:///Flecha arriba
                {
                    Arriba();
                }break;
            case 75:///Flecha izquierda
                {
                    Izquierda();
                }break;
            case 77:///Flecha derecha
                {
                    Derecha();
                }break;
            case 80:///Flecha abajo
                {
                    Abajo();
                }break;
            case 27:///Tecla Escape
                {
                    return;
                }break;
            case 13:///Tecla Enter
                {
                    return;
                }break;
            default:
                {

                }break;
        }
    }
}

void clsGrafico::LineaInicial()
{
    cout<<' ';
    for(int i = 0; i < COLUMNAS + 1; i++)
    {
        cout<<'_';
    }
    cout<<endl<<'|';
    int i;
    for(i = 0; i < COLUMNAS + 1; i++)
    {
        cout<<' ';
    }
    cout<<'|'<<endl;
}

void clsGrafico::LineaFinal()
{
    cout<<'|';
    for(int i = 0; i < COLUMNAS + 1; i++)
    {
        cout<<'_';
    }
    cout<<'|'<<endl;
}
