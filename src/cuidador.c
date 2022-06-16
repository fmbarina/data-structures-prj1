#include "cuidador.h"
#include "geoloc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXT ".txt"

struct cuidador
{
    char *nome;
    // char ocupacao; // cuidadores agora sao onipresentes
    Geoloc *local;
    FILE *arquivo;
};

Cuidador *IniciaCuidador(char *nome, char *diretorio)
{
    Cuidador *cui = (Cuidador *)malloc(sizeof(Cuidador));
    cui->nome = nome;
    cui->local = IniciaGeo(0, 0);
    // cui->ocupacao = 0;

    char dir[strlen(diretorio) + strlen(nome) + strlen(EXT) + 3];

    // Concatenacao com nome do idoso
    strcpy(dir, diretorio);
    strcat(dir, "/");
    strcat(dir, nome);
    strcat(dir, EXT);
    cui->arquivo = fopen(dir, "r");

    return cui;
}

char *GetNomeCuidador(Cuidador *cui)
{
    return cui->nome;
}

/*int GetOcupacaoCuidador(Cuidador *cui)
{
    return (int)cui->ocupacao;
}

void SetOcupacaoCuidador(Cuidador *cui, int ocupacao)
{
    cui->ocupacao = (char)ocupacao;
}*/

Geoloc *GetLocalCuidador(Cuidador *cui)
{
    return cui->local;
}

void SetLocalCuidador(Cuidador *cui, int longitude, int latitude)
{
    MudaPosGeo(cui->local, longitude, latitude);
}

void AtualizaCuidador(Cuidador *cui)
{
    int lon, lati; // ...long é uma palavra reservada
    fscanf(cui->arquivo, "%i;%i", &lati, &lon);
    SetLocalCuidador(cui, lon, lati);
}

void LiberaCuidador(Cuidador *cui)
{
    if (cui)
    {
        LiberaGeo(cui->local);
        fclose(cui->arquivo);
        free(cui);
    }
    else
        printf("Cuidador vazio!\n");
}
