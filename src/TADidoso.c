#include "TADidoso.h"
#include "TADgeoloc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXT ".txt"

struct idoso
{
    char *nome;
    int idade;
    char condicao;
    Geoloc *local;
    FILE *arquivo;
    // Lista de idoso
    // lista de cuidador
};

Idoso *IniciaIdoso(char *nome, int idade, char *diretorio)
{
    Idoso *saida = (Idoso *)malloc(sizeof(Idoso));
    saida->nome = strdup(nome);
    saida->idade = idade;
    saida->condicao = 0;
    saida->local = IniciaGeo(0, 0);

    char *dir;
    // Concatenacao com nome do idoso
    dir = strdup(diretorio);
    strcat(dir, "/");
    strcat(dir, nome);
    strcat(dir, EXT);

    saida->arquivo = fopen(dir, "r");

    return saida;
}

void AtualizaIdoso(Idoso *ido)
{
    // Eh complicado.
}

Geoloc* GetLocal(Idoso *ido)
{
    return ido->local;
}

void SetLocalIdoso(Idoso *ido, int longitude, int latitude)
{
    MudaPosGeo(ido->local, longitude, latitude);
}

int GetCondicaoIdoso(Idoso *ido)
{
    return (int)ido->condicao;
}

void SetCondicaoIdoso(Idoso *ido, int condicao)
{
    ido->condicao = (char)condicao;
}

// Entra aqui lista de amigos e lista de cuidadores, ainda por fazer

void LiberaIdoso(Idoso *ido)
{
    // TODO: verificar se existem antes!
    LiberaGeo(ido->local);
    fclose(ido->arquivo);
    free(ido->nome);
    free(ido);
}
