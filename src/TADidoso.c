#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TADidoso.h"
#include "TADgeoloc.h"
#include "TADListaIdoso.h"
#include "TADListaCuidador.h"

#define EXT ".txt"

struct idoso
{
    char *nome;
    int febreSeguida;
    char condicao;
    /*Tabela da condicao do idoso
        -1  = Morto
        0   = Bem
        1   = Necessita de amigos
        2   = Necessita de cuidador
    */
    Geoloc *local;
    FILE *arquivo;
    ListaIdoso *ListaAmigos;
    ListaCui *ListaCuidadores;
    // Arquivo de saida do idoso
    FILE *saida;
};

Idoso *IniciaIdoso(char *nome, char *diretorio)
{
    Idoso *saida = (Idoso *)malloc(sizeof(Idoso));
    SetNomeIdoso(saida, nome);
    saida->febreSeguida = 0;
    saida->condicao = 0;
    saida->local = IniciaGeo(0, 0);
    saida->ListaAmigos = IniciaListaIdoso();
    saida->ListaCuidadores = IniciaListaCui();

    char dir[strlen(diretorio) + strlen(nome) + strlen(EXT) + strlen("-saida") + 3];
    // Concatenacao com nome do idoso
    strcpy(dir, diretorio);
    strcat(dir, "/");
    strcat(dir, nome);
    strcat(dir, EXT);

    saida->arquivo = fopen(dir, "r");

    strcpy(dir, diretorio);
    strcat(dir, "/");
    strcat(dir, nome);
    strcat(dir, "-saida");
    strcat(dir, EXT);

    saida->saida = fopen(dir, "W");
    return saida;
}

void AtualizaIdoso(Idoso *ido)
{
    // TODO:Fazer a leitura de cada linha de joao.txt
    // Considerando que o arquivo ja esta aberto em arquivo

    // Caso Morto
    if (ido->condicao == -1)
        return;

    int queda;
    float temp;
    int lon, lati;
    char entrada[30];

    fscanf(ido->arquivo, "%s", entrada);

    // Caso Falecimento
    if (entrada == "falecimento")
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

char* GetNomeIdoso(Idoso *ido)
{
    return ido->nome;
}

void SetNomeIdoso(Idoso *ido, char* nome)
{
    if(ido->nome)
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

void InsereCuidadorIdoso(Idoso *ido, Cuidador* cuidador)
{
    InsereListaCui(ido->ListaCuidadores, cuidador);
}

void InsereAmigoIdoso(Idoso *ido, Idoso* amigoIdoso)
{
    InsereListaIdoso(ido->ListaAmigos, amigoIdoso);
}

void LiberaIdoso(Idoso *ido)
{
    if (ido)
    {
        LiberaGeo(ido->local);
        fclose(ido->arquivo);
        fclose(ido->saida);
        free(ido->nome);
        LiberaListaIdoso(ido->ListaAmigos);
        LiberaListaCui(ido->ListaCuidadores);
        free(ido);
    }
    else
        printf("Idoso Vazio!\n");
}
