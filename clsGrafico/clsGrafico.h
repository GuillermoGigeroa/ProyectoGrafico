#ifndef CLSGRAFICO_H
#define CLSGRAFICO_H

const unsigned short int COLUMNAS = 3*25;
const unsigned short int FILAS = 2*10;
const unsigned short int MARGEN_IZQUIERDO = 2;

class clsGrafico
{
    public:
        ///Constructor
        clsGrafico(int x = 0, int y = 0, int vel = 5);

        ///Gets
        int GetX(){return posX;}
        int GetY(){return posY;}
        int GetVelocidad(){return velocidadAnimacion;}

        ///Sets
        void SetX(int x){posX = x;}
        void SetY(int y){posY = y;}
        void SetVelocidad(int v){velocidadAnimacion = v;}

        ///Funciones gráficas
        void Dibujar();
        void LineaInicial();
        void LineaFinal();

        ///Función para detectar teclado
        void DetectarTeclado();

        ///Funciones de control
        void Arriba();
        void Arriba(int cant);
        void Abajo();
        void Abajo(int cant);
        void Izquierda();
        void Izquierda(int cant);
        void Derecha();
        void Derecha(int cant);

        ///Auxiliares
        void CompletarCadena(char cuadrado[FILAS][COLUMNAS]);
        void CompletarCadena(char cuadrado[FILAS][COLUMNAS], char a);
        void Escribir(char cuadrado[FILAS][COLUMNAS]);
        void Esperar(int ms);
    private:
        int posX, posY, velocidadAnimacion;
        char cuadrado[FILAS][COLUMNAS];
};

#endif // CLSGRAFICO_H
