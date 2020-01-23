#include "clsPersistencia.h"
#include <cstdio>

bool clsPersistencia::Cargar(clsGrafico *grafico)
{
    FILE *p;
    p = fopen(ARCHIVO,"rb");
    if(p == NULL) return false;
    fread(&grafico,sizeof(clsGrafico),1,p);
    fclose(p);
    return true;
}

bool clsPersistencia::Guardar(clsGrafico *grafico)
{
    FILE *p;
    p = fopen(ARCHIVO,"wb");
    if(p == NULL) return false;
    fclose(p);
    p = fopen(ARCHIVO,"ab");
    fwrite(&grafico,sizeof(clsGrafico),1,p);
    fclose(p);
    return true;
}
