#include "idoso.h"
#include "geoloc.h"
#include "listaIdoso.h" // TODO: Dependecia circular?!
#include "listaCuidador.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXT ".txt"

struct idoso
{
    char *nome;
    int febreSeguida;
    char condicao;
    /*Tabela da condicao do idoso
        -1  = Bem morto
        0   = Bem
        1   = Necessita de amigos
        2   = Necessita de cuidador
    */
    Geoloc *local;
    FILE *arquivo;
    lIdosos *ListaAmigos;
    lCuidadores *ListaCuidadores;
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

void AtualizaIdoso(Idoso *i)
{
    // TODO:Fazer a leitura de cada linha de nome.txt
    // Considerando que o arquivo ja esta aberto na prop. arquivo

    // Caso Morto
    if (i->condicao == -1)
        return;

    int queda;
    float temp;
    int lon, lati;
    char entrada[30];

    fscanf(i->arquivo, "%s", entrada);

    // Caso Falecimento
    if (!strcmp(entrada, "falecimento"))
    {
        i->condicao = -1;
    }

    // Vivo
    if (i->condicao != -1)
    {
        sscanf(entrada, "%f;%i;%i;%i", &temp, &lati, &lon, &queda);

        SetLocalIdoso(i, lon, lati);

        // Febre Baixa
        if (temp < 38 && temp > 37)
        {
            i->condicao = 1;
            i->febreSeguida++;
        }
        // Febre Alta
        if (temp >= 38)
        {
            i->condicao = 2;
        }
        // Queda
        if (queda)
        {
            i->condicao = 2;
        }
        // Febres Seguidas
        if (i->febreSeguida >= 4)
        {
            i->condicao = 2;
        }
    }
}

char* GetNomeIdoso(Idoso *i)
{
    return i->nome;
}

void SetNomeIdoso(Idoso *i, char* nome)
{
    if(i->nome)
        free(i->nome);

    i->nome = strdup(nome);

}

Geoloc *GetLocalIdoso(Idoso *i)
{
    return i->local;
}

void SetLocalIdoso(Idoso *i, int longitude, int latitude)
{
    MudaPosGeo(i->local, longitude, latitude);
}

int GetCondicaoIdoso(Idoso *i)
{
    return (int)i->condicao;
}

void SetCondicaoIdoso(Idoso *i, int condicao)
{
    i->condicao = (char)condicao;
}

void InsereCuidadorIdoso(Idoso *i, Cuidador* c)
{
    InsereListaCui(i->ListaCuidadores, c);
}

void InsereAmigoIdoso(Idoso *i, Idoso* amigo)
{
    InsereListaIdoso(i->ListaAmigos, amigo);
}

void LiberaIdoso(Idoso *i)
{
    if (i)
    {
        LiberaGeo(i->local);
        fclose(i->arquivo);
        fclose(i->saida);
        free(i->nome);
        LiberaListaIdoso(i->ListaAmigos);
        LiberaListaCui(i->ListaCuidadores);
        free(i);
    }
    else
        printf("Idoso Vazio!\n");
}
