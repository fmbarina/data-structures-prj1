#include <stdio.h>
#include <string.h>
#include "TADidoso.h"
//#include "TADListaIdoso.h"
#include "TADcuidador.h"
#include "TADListaCuidador.h"

#define EXT ".txt"

int main(int argc, char *argv[])
{
    // Organizacao dos parametros recebidos
    char *diretoriogeral;
    diretoriogeral = strdup(argv[0]);
    int numLeituras;
    sscanf(argv[1], "%i", &numLeituras);

    char nome[30];
    char dirAtual[strlen(diretoriogeral) + strlen("/cuidadores") + strlen(EXT) + 2];

    strcpy(dirAtual, diretoriogeral);
    strcat(dirAtual, "/apoio");
    strcat(dirAtual, EXT);
    FILE *fApoio;
    fApoio = fopen(dirAtual, "r");

    // Inicializacao dos idosos
    char aux;

    // TODO:CriaListaIdoso

    while (fscanf(fApoio, "%[^;\n]", nome)) // Leitura de todos idosos
    {
        // TODO:Insere idoso criado com o nome na lista criada acima
        fscanf(fApoio, "%c", aux); // Deteccao do inicio das amizades
        if (aux =='\n')
            break;
    }

    // TODO: Relacoes de amizade

    fclose(fApoio);

    strcpy(dirAtual, diretoriogeral);
    strcat(dirAtual, "/cuidadores");
    strcat(dirAtual, EXT);
    FILE *fCuidadores;
    fCuidadores = fopen(dirAtual, "r");

    // Inicializacao dos cuidadores
    ListaCui *geraisCuidadores;
    geraisCuidadores = IniciaListaCui();

    while (fscanf(fCuidadores, "%[^;,\n]", nome))
    {
        InsereListaCui(IniciaCuidador(nome, diretoriogeral), geraisCuidadores);

        fscanf(fApoio, "%c", aux); // Deteccao do inicio das relacoes cuidador
        if (aux == '\n')
            break;
    }

    // TODO:Relacoes cuidadores-idosos
    /*
    Agr, le o nome do idoso, dps le os nomes dos cuidadores,
    buscando na lista de cima e adicionando na lista dentro de idoso

    Obs: esta sendo feito assim para nao ter que alocar cuidador repetido
    e facilitar a liberacao dos mesmos depois
    */

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
