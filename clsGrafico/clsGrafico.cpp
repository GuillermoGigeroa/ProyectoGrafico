#include "clsGrafico.h"
#include "clsPersistencia.h"
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
    SetCaracter('X');
    if(vel != 0)
        SetVelocidad(vel);
    else
        SetModoAnimado(false);
    CompletarMatriz(cuadrado);
    SetModoLinea(false);
    Dibujar();
}

void clsGrafico::Dibujar()
{
    system("cls || clear");
    if(GetModoLinea())
    {
        cout<<"   Modo linea activado    -    GigeroaBlack    -    Caracter a escribir: \'"<<GetCaracter()<<"\'"<<endl;
    }
    else
    {
        cout<<"                          -    GigeroaBlack    -    Caracter a escribir: \'"<<GetCaracter()<<"\'"<<endl;
    }
    LineaInicial();
    for(int x = 0; x < FILAS; x++)
    {
        cout<<setw(MARGEN_IZQUIERDO)<<left<<'|';///FILA DE RAYAS AL PRINCIPIO
        for(int y = 0; y < COLUMNAS; y++)
        {
            if(x == GetX() && y == GetY())
                cout<<GetCaracter();
            else
                cout<<cuadrado[x][y];
        }
        cout<<'|'<<endl;
    }
    LineaFinal();
    if(GetModoLinea())
        Marcar();
}

void clsGrafico::Arriba()
{
    if(GetX()-1 < 0)
        SetX(0);
    else
        SetX(GetX()-1);
    Esperar(GetVelocidad());
    Dibujar();
}

void clsGrafico::Arriba(int cant)
{
    for(int x = 0; x < cant; x++)
    {
        if(GetX()-1 < 0)
            SetX(0);
        else
            SetX(GetX()-1);
        Esperar(GetVelocidad());
        Dibujar();
    }
}

void clsGrafico::Abajo()
{
    if(GetX()+1 > FILAS - 1)
        SetX(FILAS - 1);
    else
        SetX(GetX()+1);
    Esperar(GetVelocidad());
    Dibujar();
}

void clsGrafico::Abajo(int cant)
{
    for(int x = 0; x < cant; x++)
    {
        if(GetX()+1 > FILAS - 1)
            SetX(FILAS);
        else
            SetX(GetX()+1);
        Esperar(GetVelocidad());
        Dibujar();
    }
}

void clsGrafico::Derecha()
{
    if(GetY()+1 > COLUMNAS - 2)
        SetY(COLUMNAS - 2);
    else
        SetY(GetY()+1);
    Esperar(GetVelocidad());
    Dibujar();
}

void clsGrafico::Derecha(int cant)
{
    for(int x = 0; x < cant; x++)
    {
        if(GetY()+1 > COLUMNAS - 2)
            SetY(COLUMNAS - 2);
        else
            SetY(GetY()+1);
        Esperar(GetVelocidad());
        Dibujar();
    }
}

void clsGrafico::Izquierda()
{
    if(GetY()-1 < 0)
        SetY(0);
    else
        SetY(GetY()-1);
    Esperar(GetVelocidad());
    Dibujar();
}

void clsGrafico::Izquierda(int cant)
{
    for(int x = 0; x < cant; x++)
    {
        if(GetY()-1 < 0)
            SetY(0);
        else
            SetY(GetY()-1);
        Esperar(GetVelocidad());
        Dibujar();
    }
}

void clsGrafico::CompletarMatriz(char cuadrado[FILAS][COLUMNAS])
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

void clsGrafico::CompletarMatriz(char cuadrado[FILAS][COLUMNAS], char a)
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
    if(GetModoAnimado())
        Sleep(ms);
}

void clsGrafico::DetectarTeclado()
{
    ///int op;do{op=getch();printf("%i\n",op);}while(op != 174126541);return 0;
    clsPersistencia save;
    Dibujar();
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
            case 32:///Tecla Espacio
                {
                    Marcar();
                }break;
            case 9:///Tecla Tab
                {
                    if(GetModoLinea())
                        SetModoLinea(false);
                    else
                        SetModoLinea(true);
                    Dibujar();
                }break;
            case 13:///Tecla Enter
                {
                    save.Guardar(this);
                }break;
            case 8:///Tecla Backspace
                {
                    CompletarMatriz(cuadrado);
                    Dibujar();
                }break;
            case 71:///Tecla Home
                {
                    SetX(0);
                    SetY(0);
                    Dibujar();
                }break;
            case 79:///Tecla End
                {
                    SetX(FILAS-1);
                    SetY(COLUMNAS-2);
                    Dibujar();
                }break;
            case 120:///Tecla x
                {
                    SetCaracter('X');
                    Dibujar();
                }break;
            case 49:///Tecla numero 1
                {
                    SetCaracter('1');
                    Dibujar();
                }break;
            case 50:///Tecla numero 2
                {
                    SetCaracter('2');
                    Dibujar();
                }break;
            case 51:///Tecla numero 3
                {
                    SetCaracter('3');
                    Dibujar();
                }break;
            case 52:///Tecla numero 4
                {
                    SetCaracter('4');
                    Dibujar();
                }break;
            case 53:///Tecla numero 5
                {
                    SetCaracter('5');
                    Dibujar();
                }break;
            case 54:///Tecla numero 6
                {
                    SetCaracter('6');
                    Dibujar();
                }break;
            case 55:///Tecla numero 7
                {
                    SetCaracter('7');
                    Dibujar();
                }break;
            case 56:///Tecla numero 8
                {
                    SetCaracter('8');
                    Dibujar();
                }break;
            case 48:///Tecla numero 0
                {
                    SetCaracter('0');
                    Dibujar();
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

void clsGrafico::Marcar()
{
    if(cuadrado[GetX()][GetY()] == GetCaracter())
        cuadrado[GetX()][GetY()] = ' ';
    else
        cuadrado[GetX()][GetY()] = GetCaracter();
}
