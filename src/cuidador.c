#include "cuidador.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXT ".txt"

struct cuidador
{
    char *nome;
    char ocupacao;
    Geoloc *local;
    FILE *arquivo;
};

Cuidador *IniciaCuidador(char *nome, char *diretorio)
{
    Cuidador *c = (Cuidador *)malloc(sizeof(Cuidador));
    c->nome = nome;
    c->local = IniciaGeo(0, 0);
    c->ocupacao = 0;

    char dir[strlen(diretorio) + strlen(nome) + strlen(EXT) + 3];

    // Concatenacao com nome do idoso
    strcpy(dir, diretorio);
    strcat(dir, "/");
    strcat(dir, nome);
    strcat(dir, EXT);
    c->arquivo = fopen(dir, "r");

    return c;
}

void AtualizaCuidador(Cuidador *c)
{
    int lon, lati;
    fscanf(c->arquivo, "%i;%i", &lati, &lon);
    SetLocalCuidador(c, lon, lati);
}

char *GetNomeCuidador(Cuidador *c)
{
    return c->nome;
}

int GetOcupacaoCuidador(Cuidador *c)
{
    return (int)c->ocupacao;
}

void SetOcupacaoCuidador(Cuidador *c, int ocupacao)
{
    c->ocupacao = (char)ocupacao;
}

Geoloc *GetLocalCuidador(Cuidador *c)
{
    return c->local;
}

void SetLocalCuidador(Cuidador *c, int longitude, int latitude)
{
    MudaPosGeo(c->local, longitude, latitude);
}

void LiberaCuidador(Cuidador *c)
{
    if (c)
    {
        LiberaGeo(c->local);
        fclose(c->arquivo);
        free(c);
    }
    else
        printf("Cuidador vazio!\n");
}
