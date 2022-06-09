#include "TADcuidador.h"
#include <stdio.h>
#include <stdlib.h>
struct cuidador
{
    Geoloc *Local;
    int ocupancia;
    int id;
};

Cuidador *InicializaCuidador(int longitude, int latitude, int id)
{
    Cuidador *saida = (Cuidador *)malloc(sizeof(Cuidador));
    saida->Local = InicializaGeo(longitude, latitude);
    saida->ocupancia = 0;
    saida->id = id;
    return saida;
}
int GetOcupancia(Cuidador *entrada)
{
    return entrada->ocupancia;
}
Geoloc *GetLocal(Cuidador *entrada)
{
    return entrada->Local;
}
void SetLocal(Cuidador *entrada, int longitude, int latitude)
{
    MudaPos(entrada->Local, longitude, latitude);
}

void SetOcupacao(Cuidador *entrada, int ocupancia)
{
    entrada->ocupancia = ocupancia;
}
void LiberaCuidador(Cuidador *entrada)
{
    LiberaGeo(entrada->Local);
    free(entrada);
}