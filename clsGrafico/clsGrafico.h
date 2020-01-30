#ifndef CLSGRAFICO_H
#define CLSGRAFICO_H

const unsigned short int COLUMNAS = 75;
const unsigned short int FILAS = 20;
const unsigned short int MARGEN_IZQUIERDO = 2;

class clsGrafico
{
    public:
        ///Constructor
        clsGrafico(int x = 0, int y = 0);
        void InicializarTodo(int x = 0, int y = 0);

        ///Gets
        int GetX(){return posX;}
        int GetY(){return posY;}
        bool GetModoLinea(){return modoLinea;}
        char GetCaracter(){return caracterParaEscribir;}
        bool GetEstadoGuardado(){return seGuardo;}
        int GetColor(){return colorElegido;}

        ///Sets
        void SetX(int x){posX = x;}
        void SetY(int y){posY = y;}
        void SetModoLinea(bool asi){modoLinea = asi;}
        void SetCaracter(char a){caracterParaEscribir = a;}
        void SetGuardado(bool a){seGuardo = a;}
        void SetColor(int num){colorElegido = num;}

        ///Funciones gráficas
        void Dibujar();
        void LineaInicial();
        void LineaFinal();
        void Marcar();
        void ColorDeConsola(int);

        ///Persistencia
        bool Cargar();
        bool Limpiar();
        bool Guardar();

        ///Función principal para iniciar
        void IniciarJuego();

        ///Funciones de control
        bool Arriba();
        void Arriba(int);
        bool Abajo();
        void Abajo(int);
        bool Izquierda();
        void Izquierda(int);
        bool Derecha();
        void Derecha(int);
        void Inicio();
        void Fin();

        ///Funciones de detección
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
        void CompletarMatriz(char);

    private:
        int posX, posY, colorElegido;
        char cuadrado[FILAS][COLUMNAS], caracterParaEscribir, colorConsola[9];
        bool modoLinea, seGuardo;
};

#endif // CLSGRAFICO_H
