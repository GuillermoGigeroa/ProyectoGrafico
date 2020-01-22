#include "clsHelper.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;
using std::setw;
using std::left;

void clsHelper::CompletarCadena(char cuadrado[10][15])
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

void clsHelper::CompletarCadena(char cuadrado[10][15], char a)
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

void clsHelper::Escribir(char cuadrado[10][15])
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

void clsHelper::Esperar(int ms)
{
    Sleep(ms);
}

