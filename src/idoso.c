#include "idoso.h"
#include "cuidador.h"
#include "listaIdoso.h"
#include "listaCuidador.h"
#include "geoloc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXT ".txt"

struct idoso
{
    char *nome;
    char condicao;
    char febreSeguida;
    /*Tabela da condicao do idoso
        -1  = Bem morto
        0   = Bem
        1   = Necessita de amigos
        2   = Necessita de cuidador
    */
    Geoloc *local;
    // Arquivos de entrada e saída
    FILE *arqent;
    FILE *arqsai;
    // Listas
    listaIdo *amigos;
    listaCui *cuidadores;
};

Idoso *IniciaIdoso(char *nome, char *diretorio)
{
    Idoso *ido = (Idoso *)malloc(sizeof(Idoso));
    SetNomeIdoso(ido, nome);
    ido->febreSeguida = 0;
    ido->condicao = 0;
    ido->local = IniciaGeo(0, 0);
    ido->amigos = IniciaListaIdoso();
    ido->cuidadores = IniciaListaCui();

    char dir[strlen(diretorio) + strlen(nome) + strlen(EXT) + strlen("-saida") + 3];

    // Concatenacao com nome do idoso
    strcpy(dir, diretorio);
    strcat(dir, "/");
    strcat(dir, nome);
    strcat(dir, EXT);

    ido->arqent = fopen(dir, "r");

    strcpy(dir, diretorio);
    strcat(dir, "/");
    strcat(dir, nome);
    strcat(dir, "-saida");
    strcat(dir, EXT);

    ido->arqsai = fopen(dir, "W");
    return ido;
}

char *GetNomeIdoso(Idoso *ido)
{
    return ido->nome;
}

void SetNomeIdoso(Idoso *ido, char *nome)
{
    if (ido->nome)
        free(ido->nome);

    ido->nome = strdup(nome);
}

Geoloc *GetLocalIdoso(Idoso *ido)
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

int GetFebresIdoso(Idoso *ido)
{
    return (int)ido->febreSeguida;
}

void IncFebresIdoso(Idoso *ido)
{
    ido->febreSeguida++;
}

void AtualizaIdoso(Idoso *ido)
{
    // TODO:Fazer a leitura de cada linha de nome.txt
    // Considerando que o arquivo ja esta aberto na prop. arqent

    // Caso Morto
    if (ido->condicao == -1)
        return;

    int queda;
    float temp;
    int lon, lati;
    char entrada[30];

    fscanf(ido->arqent, "%s", entrada);

    // Caso Falecimento
    if (!strcmp(entrada, "falecimento"))
    {
        ido->condicao = -1;
    }

    // Vivo
    if (ido->condicao != -1)
    {
        sscanf(entrada, "%f;%i;%i;%i", &temp, &lati, &lon, &queda);

        SetLocalIdoso(ido, lon, lati);

        // Febre Baixa
        if (temp < 38 && temp > 37)
        {
            ido->condicao = 1;
            ido->febreSeguida++;
        }
        // Febre Alta
        if (temp >= 38)
        {
            ido->condicao = 2;
        }
        // Queda
        if (queda)
        {
            ido->condicao = 2;
        }
        // Febres Seguidas
        if (ido->febreSeguida >= 4)
        {
            ido->condicao = 2;
        }
    }
}

void InsereCuidadorIdoso(Idoso *ido, Cuidador *cui)
{
    InsereListaCui(ido->cuidadores, cui);
}

void InsereAmigoIdoso(Idoso *ido, Idoso *amigo)
{
    InsereListaIdoso(ido->amigos, amigo);
}

void LiberaIdoso(Idoso *ido)
{
    if (!ido)
        return;

    LiberaListaIdoso(ido->amigos);
    LiberaListaCui(ido->cuidadores);
    LiberaGeo(ido->local);
    fclose(ido->arqent);
    fclose(ido->arqsai);
    free(ido->nome);
    free(ido);
}
