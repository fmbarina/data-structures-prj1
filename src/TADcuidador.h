#ifndef CUID_H
#define CUID_H
#include "TADgeoloc.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct cuidador Cuidador;

Cuidador *InicializaCuidador(int longitude, int latitude, int id);
int GetOcupancia(Cuidador *entrada);
Geoloc *GetLocal(Cuidador *entrada);
void SetLocal(Cuidador *entrada,int longitude, int latitude);
void SetOcupacao(Cuidador *entrada, int ocupancia);
void LiberaCuidador(Cuidador *entrada);

#endif