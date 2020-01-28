#include "clsPersistencia.h"
#include <cstdio>

bool clsPersistencia::Cargar(clsGrafico *grafico)
{
    FILE *p;
    p = fopen("ArchivoDeGuardado.gigeroa","rb");
    if(p == NULL) return false;
    fread(&grafico,sizeof(clsGrafico),1,p);
    if(grafico->GetColor() < 0 && grafico->GetColor() > 9)
        grafico->ColorDeConsola(0);
    else
        grafico->ColorDeConsola(grafico->GetColor());
    fclose(p);
    return true;
}

bool clsPersistencia::Guardar(clsGrafico *grafico)
{
    FILE *p;
    p = fopen("ArchivoDeGuardado.gigeroa","wb");
    if(p == NULL) return false;
    fclose(p);
    p = fopen("ArchivoDeGuardado.gigeroa","ab");
    fwrite(&grafico,sizeof(clsGrafico),1,p);
    fclose(p);
    return true;
}
