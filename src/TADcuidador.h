#ifndef CUIDADOR_H
#define CUIDADOR_H
#include "TADgeoloc.h"

typedef struct cuidador Cuidador;

Cuidador *IniciaCuidador(int id, int longitude, int latitude);

int GetOcupacaoCuidador(Cuidador *c);

int GetIdCuidador(Cuidador *c); //A ser implementado

void SetOcupacaoCuidador(Cuidador *c, int ocupacao);

Geoloc *GetLocalCuidador(Cuidador *c);

void SetLocalCuidador(Cuidador *c, int longitude, int latitude);

void LiberaCuidador(Cuidador *c);

void ImprimeCuidador(Cuidador *c); //A ser implementado

#endif  // CUIDADOR_H
