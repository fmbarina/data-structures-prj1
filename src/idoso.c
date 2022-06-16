#include "idoso.h"
#include "cuidador.h"
#include "listaIdoso.h"
#include "listaCuidador.h"
#include "geoloc.h"
#include "pathman.h"
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

    // Concatenacao com nome do idoso
    char* pathEntrada = expth(adpth(strdup(diretorio), nome), EXT);
    char* pahtSaida   = expth(expth(adpth(strdup(diretorio), nome), "-saida"), EXT);
    
    ido->arqent = fopen(pathEntrada, "r");
    ido->arqsai = fopen(pahtSaida, "W");

    free(pathEntrada);
    free(pahtSaida);
    
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

void ResetFebresIdoso(Idoso *ido)
{
    ido->febreSeguida = (char)0;
}

void IncFebresIdoso(Idoso *ido)
{
    ido->febreSeguida++;
}

void AtualizaIdoso(Idoso *ido)
{
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
        SetCondicaoIdoso(ido, -1);
        return;
    }

    // Casos "Ainda está vivo graças"
    sscanf(entrada, "%f;%i;%i;%i", &temp, &lati, &lon, &queda);

    SetLocalIdoso(ido, lon, lati);

    // Febre Baixa
    if (temp < 38 && temp > 37)
    {
        SetCondicaoIdoso(ido, 1);
        IncFebresIdoso(ido);
    }
    // Febre Alta
    if (temp >= 38)
    {
        SetCondicaoIdoso(ido, 2);
    }
    // Queda
    if (queda)
    {
        SetCondicaoIdoso(ido, 2);
    }
    // Febres Seguidas
    if (ido->febreSeguida >= 4)
    {
        SetCondicaoIdoso(ido, 2);
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
