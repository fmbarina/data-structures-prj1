#ifndef CUIDADOR_H_
#define CUIDADOR_H_
#include "geoloc.h"

typedef struct cuidador Cuidador;

Cuidador *IniciaCuidador(char *nome, char *diretorio);

int GetOcupacaoCuidador(Cuidador *cui);

char *GetNomeCuidador(Cuidador *cui);

void SetOcupacaoCuidador(Cuidador *cui, int ocupacao);

Geoloc *GetLocalCuidador(Cuidador *cui);

void SetLocalCuidador(Cuidador *cui, int longitude, int latitude);

void AtualizaCuidador(Cuidador *cui);

void LiberaCuidador(Cuidador *cui);

#endif // CUIDADOR_H_
