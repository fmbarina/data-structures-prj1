#ifndef IDOSO_H_
#define IDOSO_H_
#include "geoloc.h"
#include "cuidador.h"

typedef struct idoso Idoso;

Idoso *IniciaIdoso(char *nome, char *diretorio);

char *GetNomeIdoso(Idoso *ido);

void SetNomeIdoso(Idoso *ido, char *nome);

Geoloc *GetLocalIdoso(Idoso *ido);

void SetLocalIdoso(Idoso *ido, int longitude, int latitude);

int GetCondicaoIdoso(Idoso *ido);

void SetCondicaoIdoso(Idoso *ido, int condicao);

int GetFebresIdoso(Idoso *ido);

void IncFebresIdoso(Idoso *ido);

void ResetFebresIdoso(Idoso *ido);

void AtualizaIdoso(Idoso *ido);

void InsereCuidadorIdoso(Idoso *ido, Cuidador *cui);

void InsereAmigoIdoso(Idoso *ido, Idoso *amigo);

void ProcessaIdoso(Idoso *ido);

void LiberaIdoso(Idoso *ido);

#endif // IDOSO_H_
