#include "idoso.h"
#include "cuidador.h"
#include "listaIdoso.h"
#include "listaCuidador.h"
#include <stdio.h>
#include <string.h>

#define EXT ".txt"
#define BUF 30

int main(int argc, char *argv[])
{
    // Organizacao dos parametros recebidos
    char *diretorioGeral = strdup(argv[0]);
    int numLeituras;
    sscanf(argv[1], "%i", &numLeituras);

    char nome[BUF];
    char dirAtual[strlen(diretorioGeral) + strlen("/cuidadores") + strlen(EXT) + 2];

    // TODO: argv[0] contem o nome do programa, precisamos do diretorio
    strcpy(dirAtual, diretorioGeral);
    strcat(dirAtual, "/apoio");
    strcat(dirAtual, EXT);
    FILE *fApoio;
    fApoio = fopen(dirAtual, "r");

    // Inicializacao dos idosos
    char final;
    listaIdo *idosos = IniciaListaIdoso();

    while (fscanf(fApoio, "%[^;\n]", nome))                          // Leitura de todos idosos
    {                                                                //
        InsereListaIdoso(idosos, IniciaIdoso(nome, diretorioGeral)); // Insere idoso criado com o nome na lista criada acima
        fscanf(fApoio, "%c", &final);                                // Deteccao do inicio das amizades
        if (final == '\n')
            break;
    }

    // Relacoes de amizade
    char amigo[BUF];
    while (fscanf(fApoio, "%[^;];%[^;\n]\n", nome, amigo))
    {
        InsereAmizade(idosos, nome, amigo);
    }

    fclose(fApoio);

    strcpy(dirAtual, diretorioGeral);
    strcat(dirAtual, "/cuidadores");
    strcat(dirAtual, EXT);

    FILE *fCuidadores;
    fCuidadores = fopen(dirAtual, "r");

    // Inicializacao dos cuidadores
    listaCui *geraisCuidadores = IniciaListaCui();

    while (fscanf(fCuidadores, "%[^;,\n]", nome))
    {
        InsereListaCui(geraisCuidadores, IniciaCuidador(nome, diretorioGeral));

        fscanf(fCuidadores, "%c", &final); // Deteccao do inicio das relacoes cuidador
        if (final == '\n')
            break;
    }

    /* Relacoes cuidadores-idosos

    Agora, ler o nome do idoso, depois ler os nomes dos cuidadores,
    buscando na lista acima e adicionando na lista dentro de idosos

    Obs: esta sendo feito assim para nao ter que alocar cuidador repetido
    e facilitar a liberacao dos mesmos depois
    */

    while (fscanf(fCuidadores, "%[^;,\n]", nome))
    {
        Idoso *idosoLido = BuscaListaIdoso(idosos, nome);
        fscanf(fCuidadores, "%*c");

        while (fscanf(fCuidadores, "%[^;,\n]", nome))
        {
            InsereCuidadorIdoso(idosoLido, BuscaListaCui(geraisCuidadores, nome));

            fscanf(fCuidadores, "%c", &final);
            if (final == '\n')
                break;
        }
    }

    fclose(fCuidadores);

    int i = 0;
    for (i = 0; i < numLeituras; i++)
    {
        // Atualizacao dos dados
        // Caminhar pela lista de idosos atualizando idosos
        // Caminhas pela lista de cuidadores atualizando cuidadores

        // Processamento das infos
        /*
        TODO: Funcao de conectar os idosos aos amigos ou cuidadores
        dentro da lista de idosos,
        [a ser descutido abaixo]
        a mesma devera fazer a saida no arquivo saida presente no idoso?
        */
    }

    return 0;
}
