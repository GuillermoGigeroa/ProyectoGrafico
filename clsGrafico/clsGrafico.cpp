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
    CompletarMatriz();
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

bool clsGrafico::Arriba()//TODO Hacer que se pueda usar con un while, poniendo un booleano
{
    bool continuar;
    if(GetX()-1 < 0)
    {
        SetX(0);
        continuar = false;
    }
    else
    {
        SetX(GetX()-1);
        continuar = true;
        Esperar(GetVelocidad());
        Dibujar();
    }
    return continuar;
}

void clsGrafico::Arriba(int cant)
{
    for(int x = 0; x < cant; x++)
    {
        Arriba();
    }
}

bool clsGrafico::Abajo()//TODO Hacer que se pueda usar con un while, poniendo un booleano
{
    bool continuar;
    if(GetX()+1 > FILAS - 1)
    {
        SetX(FILAS - 1);
        continuar = false;
    }
    else
    {
        SetX(GetX()+1);
        continuar = true;
        Esperar(GetVelocidad());
        Dibujar();    }
    return continuar;
}

void clsGrafico::Abajo(int cant)
{
    for(int x = 0; x < cant; x++)
    {
        Abajo();
    }
}

bool clsGrafico::Derecha()//TODO Hacer que se pueda usar con un while, poniendo un booleano
{
    bool continuar;
    if(GetY()+1 > COLUMNAS - 2)
    {
        SetY(COLUMNAS - 2);
        continuar = false;
    }
    else
    {
        SetY(GetY()+1);
        continuar = true;
        Esperar(GetVelocidad());
        Dibujar();    }
    return continuar;
}

void clsGrafico::Derecha(int cant)
{
    for(int x = 0; x < cant; x++)
    {
        Derecha();
    }
}

bool clsGrafico::Izquierda()//TODO Hacer que se pueda usar con un while, poniendo un booleano
{
    bool continuar;
    if(GetY()-1 < 0)
    {
        SetY(0);
        continuar = false;
    }
    else
    {
        SetY(GetY()-1);
        continuar = true;
        Esperar(GetVelocidad());
        Dibujar();
    }
    return continuar;
}

void clsGrafico::Izquierda(int cant)
{
    for(int x = 0; x < cant; x++)
    {
        Izquierda();
    }
}

void clsGrafico::CompletarMatriz()
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

void clsGrafico::CompletarMatriz(char a)
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
                    CompletarMatriz();
                    Dibujar();
                }break;
            case 71:///Tecla Home
                {
                    Inicio();
                }break;
            case 79:///Tecla End
                {
                    Fin();
                }break;
            case 120:///Tecla x
            case 88:///Tecla x
                {
                    SetCaracter('X');
                    Dibujar();
                }break;
            case 49:///Tecla numero 1
                {
                    SetColor(1);
                    ColorDeConsola(1);
                    Dibujar();
                }break;
            case 50:///Tecla numero 2
                {
                    SetColor(2);
                    ColorDeConsola(2);
                    Dibujar();
                }break;
            case 51:///Tecla numero 3
                {
                    SetColor(3);
                    ColorDeConsola(3);
                    Dibujar();
                }break;
            case 52:///Tecla numero 4
                {
                    SetColor(4);
                    ColorDeConsola(4);
                    Dibujar();
                }break;
            case 53:///Tecla numero 5
                {
                    SetColor(5);
                    ColorDeConsola(5);
                    Dibujar();
                }break;
            case 54:///Tecla numero 6
                {
                    SetColor(6);
                    ColorDeConsola(6);
                    Dibujar();
                }break;
            case 55:///Tecla numero 7
                {
                    SetColor(7);
                    ColorDeConsola(7);
                    Dibujar();
                }break;
            case 56:///Tecla numero 8
                {
                    SetColor(8);
                    ColorDeConsola(8);
                    Dibujar();
                }break;
            case 57:///Tecla numero 9
                {
                    SetColor(9);
                    ColorDeConsola(9);
                    Dibujar();
                }break;
            case 48:///Tecla numero 0
                {
                    SetColor(0);
                    ColorDeConsola(0);
                    Dibujar();
                }break;
            case 97:///Tecla letra aA
            case 65:
                {
                    AutoIzquierda();
                }break;
            case 115:///Tecla letra sS
            case 83:
                {
                    AutoAbajo();
                }break;
            case 100:///Tecla letra dD
            case 68:
                {
                    AutoDerecha();
                }break;
            case 119:///Tecla letra wW
            case 87:
                {
                    AutoArriba();
                }break;
            default:
                {

                }break;
        }
    }
}

void clsGrafico::ColorDeConsola(int num)
{
    switch (num)
    {
    case 1:
        {
            strcpy(colorConsola,"color 0a");
            system(colorConsola);
        }break;
    case 2:
        {
            strcpy(colorConsola,"color 0b");
            system(colorConsola);
        }break;
    case 3:
        {
            strcpy(colorConsola,"color 0c");
            system(colorConsola);
        }break;
    case 4:
        {
            strcpy(colorConsola,"color 0d");
            system(colorConsola);
        }break;
    case 5:
        {
            strcpy(colorConsola,"color 0e");
            system(colorConsola);
        }break;
    case 6:
        {
            strcpy(colorConsola,"color 0f");
            system(colorConsola);
        }break;
    case 7:
        {
            strcpy(colorConsola,"color f0");
            system(colorConsola);
        }break;
    case 8:
        {
            strcpy(colorConsola,"color f9");
            system(colorConsola);
        }break;
    case 9:
        {
            strcpy(colorConsola,"color fc");
            system(colorConsola);
        }break;
    case 0:
        {
            strcpy(colorConsola,"color e0");
            system(colorConsola);
        }break;
    default:
        {}break;
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

void clsGrafico::Inicio()
{
    SetX(0);
    SetY(0);
    Dibujar();
}

void clsGrafico::Fin()
{
    SetX(FILAS-1);
    SetY(COLUMNAS-2);
    Dibujar();
}

bool clsGrafico::EstaMarcado()
{
    if(cuadrado[GetX()][GetY()] != ' ')
        return true;
    return false;
}

bool clsGrafico::EstaMarcadoArriba()
{
    if(cuadrado[GetX()-1][GetY()] != ' ')
        return true;
    return false;
}

bool clsGrafico::EstaMarcadoAbajo()
{
    if(cuadrado[GetX()+1][GetY()] != ' ')
        return true;
    return false;
}

bool clsGrafico::EstaMarcadoDerecha()
{
    if(cuadrado[GetX()][GetY()+1] != ' ')
        return true;
    return false;
}

bool clsGrafico::EstaMarcadoIzquierda()
{
    if(cuadrado[GetX()][GetY()-1] != ' ')
        return true;
    return false;
}

void clsGrafico::AutoArriba()
{
    while(Arriba() && !EstaMarcadoArriba());
}

void clsGrafico::AutoAbajo()
{
    while(Abajo() && !EstaMarcadoAbajo());
}

void clsGrafico::AutoDerecha()
{
    while(Derecha() && !EstaMarcadoDerecha());
}

void clsGrafico::AutoIzquierda()
{
    while(Izquierda() && !EstaMarcadoIzquierda());
}
