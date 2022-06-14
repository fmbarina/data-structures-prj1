#ifndef IDOSO_H
#define IDOSO_H
#include "TADgeoloc.h"

typedef struct idoso Idoso;

Idoso *IniciaIdoso(char *nome, char *diretorio);

void AtualizaIdoso(Idoso *ido);

char* GetNomeIdoso(Idoso *ido);

void SetNomeIdoso(Idoso *ido, char* nome);

Geoloc *GetLocalIdoso(Idoso *ido);

void SetLocalIdoso(Idoso *ido, int longitude, int latitude);

int GetCondicaoIdoso(Idoso *ido);

void SetCondicaoIdoso(Idoso *ido, int condicao);

void InsereCuidadorIdoso(Idoso *ido, Cuidador* cuidador);

void InsereAmigoIdoso(Idoso *ido, Idoso* amigoIdoso);

void LiberaIdoso(Idoso *ido);

#endif // IDOSO_H
