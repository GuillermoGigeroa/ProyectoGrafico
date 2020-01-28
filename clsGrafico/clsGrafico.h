#ifndef CLSGRAFICO_H
#define CLSGRAFICO_H

const unsigned short int COLUMNAS = 75;
const unsigned short int FILAS = 20;
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
        bool GetModoLinea(){return modoLinea;}
        bool GetModoAnimado(){return modoAnimado;}
        char GetCaracter(){return caracterParaEscribir;}
        bool GetEstadoGuardado(){return seGuardo;}
        int GetColor(){return colorElegido;}

        ///Sets
        void SetX(int x){posX = x;}
        void SetY(int y){posY = y;}
        void SetVelocidad(int v){velocidadAnimacion = v;}
        void SetModoLinea(bool asi){modoLinea = asi;}
        void SetModoAnimado(bool asi){modoAnimado = asi;}
        void SetCaracter(char a){caracterParaEscribir = a;}
        void SetGuardado(bool a){seGuardo = a;}
        void SetColor(int num){colorElegido = num;}

        ///Funciones gráficas
        void Dibujar();
        void LineaInicial();
        void LineaFinal();
        void Marcar();
        void ColorDeConsola(int num);

        ///Función para detectar teclado
        void DetectarTeclado();

        ///Funciones de control
        bool Arriba();
        void Arriba(int cant);
        bool Abajo();
        void Abajo(int cant);
        bool Izquierda();
        void Izquierda(int cant);
        bool Derecha();
        void Derecha(int cant);
        void Inicio();
        void Fin();
        bool EstaMarcado();
        bool EstaMarcadoArriba();
        bool EstaMarcadoAbajo();
        bool EstaMarcadoDerecha();
        bool EstaMarcadoIzquierda();

        ///Funciones de control automático
        void AutoArriba();
        void AutoAbajo();
        void AutoDerecha();
        void AutoIzquierda();

        ///Auxiliares
        void CompletarMatriz();
        void CompletarMatriz(char a);
        void Escribir(char cuadrado[FILAS][COLUMNAS]);
        void Esperar(int ms);
    private:
        int posX, posY, velocidadAnimacion, colorElegido;
        char cuadrado[FILAS][COLUMNAS], caracterParaEscribir, colorConsola[9];
        bool modoLinea, modoAnimado, seGuardo;
};

#endif // CLSGRAFICO_H
