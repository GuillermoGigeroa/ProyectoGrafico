#ifndef CLSGRAFICO_H
#define CLSGRAFICO_H


class clsGrafico
{
    public:
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
        void Dibujar(char a);

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
        void CompletarCadena(char cuadrado[10][15]);
        void CompletarCadena(char cuadrado[10][15], char a);
        void Escribir(char cuadrado[10][15]);
        void Esperar(int ms);
    private:
        int posX, posY, velocidadAnimacion;
        char cuadrado[10][15];
};

#endif // CLSGRAFICO_H
