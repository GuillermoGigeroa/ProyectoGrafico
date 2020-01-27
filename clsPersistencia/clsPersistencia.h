#ifndef CLSPERSISTENCIA_H
#define CLSPERSISTENCIA_H
#include "clsGrafico.h"

class clsPersistencia
{
    public:
        bool Cargar(clsGrafico *);
        bool Guardar(clsGrafico *);
};

#endif // CLSPERSISTENCIA_H
