#ifndef CUIDADOR_H
#define CUIDADOR_H
#include "geoloc.h"

typedef struct cuidador Cuidador;

Cuidador *IniciaCuidador(char *nome, char *diretorio);

int GetOcupacaoCuidador(Cuidador *c);

char *GetNomeCuidador(Cuidador *c);

void AtualizaCuidador(Cuidador *c);

void SetOcupacaoCuidador(Cuidador *c, int ocupacao);

Geoloc *GetLocalCuidador(Cuidador *c);

void SetLocalCuidador(Cuidador *c, int longitude, int latitude);

void LiberaCuidador(Cuidador *c);

#endif // CUIDADOR_H
