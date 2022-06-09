#include "TADidoso.h"
#include <string.h>

#define EXT ".txt"

struct idoso
{
    Geoloc *Local;
    char *nome;
    int idade;
    int condicao;
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
    saida->Local = InicializaGeo(0, 0);

    char *dir;
    // Concatenacao com nome do idoso
    dir = strdup(diretorio);
    strcat(dir, "/");
    strcat(dir, nome);
    strcat(dir, EXT);

    saida->arquivo = fopen(dir, 'r');

    return saida;
}

Geoloc *GetLocal(Idoso *entrada);
void SetLocal(Idoso *entrada);
void AtualizaIdoso(Idoso *entrada);
int GetCondicao(Idoso *entrada);

// Entra aqui lista de amigos e lista de cuidadores, ainda por fazer

void LiberaIdoso(Idoso *entrada);
