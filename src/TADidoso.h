#ifndef IDOSO_H
#define IDOSO_H
#include "TADgeoloc.h"

typedef struct idoso Idoso;

Idoso *IniciaIdoso(char *nome, char *diretorio);

void AtualizaIdoso(Idoso *ido);

Geoloc *GetLocalIdoso(Idoso *ido);

void SetLocalIdoso(Idoso *ido, int longitude, int latitude);

int GetCondicaoIdoso(Idoso *ido);

void SetCondicaoIdoso(Idoso *ido, int condicao);

// Entra aqui lista de amigos e lista de cuidadores, ainda por fazer
void InsereCuidador(Idoso *ido, int idCuidador);

void LiberaIdoso(Idoso *ido);

#endif // IDOSO_H
