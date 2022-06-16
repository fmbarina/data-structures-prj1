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
    char febreSeguida;
    char condicao;
    /*Tabela da condicao do idoso
        -2  = Bem morto
        -1  = A informar, morto
        0   = Bem
        1   = Necessita de amigos
        2   = Necessita de cuidador, febre alta
        3   = Necessita de cuidador, febre baixa pela 4a vez
        4   = Necessita de cuidador, queda
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
    SetNomeIdoso(ido, strdup(nome));
    ido->febreSeguida = 0;
    ido->condicao = 0;
    ido->local = IniciaGeo(0, 0);
    ido->amigos = IniciaListaIdoso();
    ido->cuidadores = IniciaListaCui();

    // Concatenacao com nome do idoso
    char *pathEntrada = expth(adpth(strdup(diretorio), nome), EXT);
    char *pahtSaida = expth(expth(adpth(strdup(diretorio), nome), "-saida"), EXT);

    ido->arqent = fopen(pathEntrada, "r");
    ido->arqsai = fopen(pahtSaida, "w");

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
    ido->nome = nome;
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
    ido->febreSeguida++; // Tem que ser reiniciado em algum momento
}

void AtualizaIdoso(Idoso *ido)
{
    // Caso Morto
    if (ido->condicao < 0)
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
    if (temp > 37.0 && temp < 38.0)
    {
        SetCondicaoIdoso(ido, 1);
        IncFebresIdoso(ido);
    }
    // Febre Alta
    if (temp >= 38.0)
    {
        SetCondicaoIdoso(ido, 2);
        ResetFebresIdoso(ido); // Da especificação: sem febre alta “no meio”
    }
    // Febres Seguidas
    if (ido->febreSeguida >= 4)
    {
        SetCondicaoIdoso(ido, 3);
        ResetFebresIdoso(ido); // Da especificação: sem febre alta “no meio”
    }
    // Queda
    if (queda)
    {
        SetCondicaoIdoso(ido, 4);
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

void ProcessaIdoso(Idoso *ido)
{
    // Caso Morto
    if (ido->condicao == -2)
        return;

    char *bufNome;
    Cuidador *auxCui;
    Idoso *auxAmg;

    if (ido->condicao == 1) // Acha amg
    {
        auxAmg = RetornaIdosoProx(ido->amigos, ido->local);
        bufNome = GetNomeIdoso(auxAmg);
    }

    if (ido->condicao >= 2) // Acha cuidador
    {
        auxCui = RetornaCuidadorProx(ido->cuidadores, ido->local);
        bufNome = GetNomeCuidador(auxCui);
    }

    switch (ido->condicao)
    {
    case -1: // Relatando falecimento
        fprintf(ido->arqsai, "falecimento\n");
        SetCondicaoIdoso(ido, -2);
        return;
    case 0: // Bem
        fprintf(ido->arqsai, "tudo ok\n");
        break;
    case 1: // Necessita amg
        fprintf(ido->arqsai, "febre baixa, acionou amigo %s\n", bufNome);
        break;
    case 2: // Necessita cuidador, febre alta
        fprintf(ido->arqsai, "febre alta, acionou %s\n", bufNome);
        break;
    case 3: // Necessita cuidador, febre baixa 4 vez
        fprintf(ido->arqsai, "febre baixa pela quarta vez, acionou %s\n", bufNome);
        break;
    case 4: // Necessita cuidador, queda
        fprintf(ido->arqsai, "queda, acionou %s\n", bufNome);
        break;
    default:
        fprintf(ido->arqsai, "ERRO: Ação de idoso não definida\n");
        break;
    }

    // Resetar condição do idoso
    SetCondicaoIdoso(ido, 0);
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