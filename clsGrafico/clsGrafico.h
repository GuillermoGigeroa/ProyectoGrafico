#ifndef CLSGRAFICO_H
#define CLSGRAFICO_H


class clsGrafico
{
    public:
        clsGrafico(int x = 0, int y = 0, int vel = 5);
        int GetX(){return posX;}
        int GetY(){return posY;}
        int GetVelocidad(){return velocidadAnimacion;}
        void SetX(int x){posX = x;}
        void SetY(int y){posY = y;}
        void SetVelocidad(int v){velocidadAnimacion = v;}

        void Dibujar();
        void Dibujar(char a);
        void Arriba();
        void Arriba(int cant);
        void Abajo();
        void Abajo(int cant);
        void Izquierda();
        void Izquierda(int cant);
        void Derecha();
        void Derecha(int cant);
    private:
        int posX, posY, velocidadAnimacion;
        char cuadrado[10][15];
};

#endif // CLSGRAFICO_H
