#ifndef CLSPERSISTENCIA_H
#define CLSPERSISTENCIA_H
#include "clsGrafico.h"
const char ARCHIVO[] = "ArchivoDeGuardado.gigeroa";

class clsPersistencia
{
    public:
        bool Cargar(clsGrafico *);
        bool Guardar(clsGrafico *);
};

#endif // CLSPERSISTENCIA_H
