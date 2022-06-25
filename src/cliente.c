//
// Autores: Rhuan Garcia e Felipe M. Barina
//
#include "idoso.h"
#include "cuidador.h"
#include "listaIdoso.h"
#include "listaCuidador.h"
#include "pathman.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXT ".txt"
#define BUF 30

int main(int argc, char *argv[])
{
    // Organizacao dos parametros recebidos
    char *diretorioGeral = strdup(argv[0]);
    int numLeituras;
    sscanf(argv[1], "%i", &numLeituras);

    // Caminhos utilizados
    diretorioGeral = trpth(diretorioGeral);
    diretorioGeral = adpth(diretorioGeral, "entrada");
    char *pathApoio = expth(adpth(strdup(diretorioGeral), "apoio"), EXT);
    char *pathCuida = expth(adpth(strdup(diretorioGeral), "cuidadores"), EXT);

    // TODO: considerar: Não seria melhor ter operações similares juntas?
    //       -> abertura dos arquivos, declaração de variáveis auxiliares, etc.
    //       Li que deixar coisas perto de onde são usadas é melhor, mas parece
    //       meio bagunçado?

    FILE *fApoio;
    FILE *fCuidadores;
    fApoio = fopen(pathApoio, "r");
    fCuidadores = fopen(pathCuida, "r");

    char nome[BUF];
    char final;

    // Inicializacao e leitura dos idosos
    listaIdo *idosos = IniciaListaIdoso();
    while (fscanf(fApoio, "%[^;\n]", nome))
    {
        // Insere idoso criado com o nome na lista criada acima
        InsereListaIdoso(idosos, IniciaIdoso(nome, diretorioGeral));
        fscanf(fApoio, "%c", &final);

        // Deteccao do inicio das amizades
        if (final == '\n')
            break;
    }

    // Criação das relações de amizade entre idosos
    char amigo[BUF];
    while (fscanf(fApoio, "%[^;];%[^;\n]\n", nome, amigo) == 2)
    {
        InsereAmizade(idosos, nome, amigo);
    }

    // Inicializacao e leitura dos cuidadores
    listaCui *cuidadores = IniciaListaCui();
    while (fscanf(fCuidadores, "%[^;, \n]", nome))
    {
        InsereListaCui(cuidadores, IniciaCuidador(nome, diretorioGeral));

        // Deteccao do inicio das relacoes cuidador
        while (fscanf(fCuidadores, "%*[ ]"));

        fscanf(fCuidadores, "%c", &final);
        if (final == '\n')
            break;
    }

    /* Criação das relações cuidadores-idosos

    Agora, ler o nome do idoso, depois ler os nomes dos cuidadores,
    buscando na lista acima e adicionando na lista dentro de idosos

    Obs: esta sendo feito assim para nao ter que alocar cuidador repetido
    e facilitar a liberacao dos mesmos depois
    */

    while (fscanf(fCuidadores, "%[^;,\n]", nome) == 1)
    {
        Idoso *idosoLido = BuscaListaIdoso(idosos, nome);
        fscanf(fCuidadores, "%*c");

        while (fscanf(fCuidadores, "%[^;,\n]", nome))
        {
            InsereCuidadorIdoso(idosoLido, BuscaListaCui(cuidadores, nome));

            fscanf(fCuidadores, "%c", &final);
            if (final == '\n')
                break;
        }
    }

    fclose(fApoio);
    fclose(fCuidadores);

    // Ciclo de execução
    int i = 0;
    for (i = 0; i < numLeituras; i++)
    {
        // Caminhar pela lista de idosos atualizando idosos
        IteraListaIdoso(idosos, AtualizaIdoso);
        // Caminhas pela lista de cuidadores atualizando cuidadores
        IteraListaCui(cuidadores, AtualizaCuidador);

        // Processamento das informações
        IteraListaIdoso(idosos, ProcessaIdoso);
    }

    // Liberacao de memoria
    IteraListaIdoso(idosos, LiberaIdoso);
    LiberaListaIdoso(idosos);

    IteraListaCui(cuidadores, LiberaCuidador);
    LiberaListaCui(cuidadores);

    free(diretorioGeral);
    free(pathApoio);
    free(pathCuida);

    return 0;
}
