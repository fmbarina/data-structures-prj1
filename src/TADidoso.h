#include <stdio.h>
#include <stdlib.h>
#include "TADgeoloc.h"

#ifndef IDOSO_H
#define IDOSO_H

typedef struct idoso Idoso;

Idoso *IniciaIdoso(char *nome, int idade, char *diretorio);

Geoloc *GetLocal(Idoso *entrada);
void SetLocal(Idoso *entrada);
void AtualizaIdoso(Idoso *entrada);
int GetCondicao(Idoso *entrada);

// Entra aqui lista de amigos e lista de cuidadores, ainda por fazer

void LiberaIdoso(Idoso *entrada);

#endif
