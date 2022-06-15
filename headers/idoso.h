#ifndef IDOSO_H
#define IDOSO_H
#include "geoloc.h"
#include "cuidador.h"

typedef struct idoso Idoso;

Idoso *IniciaIdoso(char *nome, char *diretorio);

void AtualizaIdoso(Idoso *i);

char* GetNomeIdoso(Idoso *i);

void SetNomeIdoso(Idoso *i, char* nome);

Geoloc *GetLocalIdoso(Idoso *i);

void SetLocalIdoso(Idoso *i, int longitude, int latitude);

int GetCondicaoIdoso(Idoso *i);

void SetCondicaoIdoso(Idoso *i, int condicao);

void InsereCuidadorIdoso(Idoso *i, Cuidador* c);

void InsereAmigoIdoso(Idoso *i, Idoso* amigo);

void LiberaIdoso(Idoso *i);

#endif // IDOSO_H
