#include "TADcuidador.h"
#include <stdio.h>
#include <stdlib.h>

struct cuidador
{
    int id;
    char ocupacao;
    Geoloc *local;
};

Cuidador *IniciaCuidador(int id, int longitude, int latitude)
{
    Cuidador *c = (Cuidador *)malloc(sizeof(Cuidador));
    c->id       = id;
    c->local    = IniciaGeo(longitude, latitude);
    c->ocupacao = 0; 
    return c;
}

int GetOcupacaoCuidador(Cuidador *c)
{
    return (int)c->ocupacao;
}

void SetOcupacaoCuidador(Cuidador *c, int ocupacao)
{
    c->ocupacao = (char)ocupacao;
}

Geoloc *GetLocalCuidador(Cuidador *c)
{
    return c->local;
}

void SetLocalCuidador(Cuidador *c, int longitude, int latitude)
{
    MudaPosGeo(c->local, longitude, latitude);
}

void LiberaCuidador(Cuidador *c)
{
    LiberaGeo(c->local);
    free(c);
}
