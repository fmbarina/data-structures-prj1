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
    // TODO: restaurar. Como passar o dir do programa? Devia ter perguntado
    //char *diretorioGeral = strdup(argv[0]); 
    char *diretorioGeral = strdup(argv[2]);  // modo alternativo, pra testes.
    int numLeituras;
    sscanf(argv[1], "%i", &numLeituras);

    // Caminhos utilizados
    // diretorioGeral  = trpth(diretorioGeral); TODO: restaurar
    char* pathApoio = expth(adpth(strdup(diretorioGeral), "apoio"), EXT);
    char* pathCuida = expth(adpth(strdup(diretorioGeral), "cuidadores"), EXT);

    // TODO: considerar: Não seria melhor ter operações similares juntas?
    //       -> abertura dos arquivos, declaração de variáveis auxiliares, etc.
    //       Li que deixar coisas perto de onde são usadas é melhor, mas parece
    //       meio bagunçado?

    FILE *fApoio;
    fApoio = fopen(pathApoio, "r");

    // Inicializacao dos idosos
    char final;
    listaIdo *idosos = IniciaListaIdoso();

    char nome[BUF];
    // Leitura de todos idosos
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
    while (fscanf(fApoio, "%[^;];%[^;\n]\n", nome, amigo))
    {
        InsereAmizade(idosos, nome, amigo);
    }

    fclose(fApoio);;

    FILE *fCuidadores;
    fCuidadores = fopen(pathCuida, "r");

    // Inicializacao dos cuidadores
    listaCui *cuidadores = IniciaListaCui();

    while (fscanf(fCuidadores, "%[^;,\n]", nome))
    {
        InsereListaCui(cuidadores, IniciaCuidador(nome, diretorioGeral));

        fscanf(fCuidadores, "%c", &final); // Deteccao do inicio das relacoes cuidador
        if (final == '\n')
            break;
    }

    /* Criação das relações cuidadores-idosos

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
            InsereCuidadorIdoso(idosoLido, BuscaListaCui(cuidadores, nome));

            fscanf(fCuidadores, "%c", &final);
            if (final == '\n')
                break;
        }
    }

    fclose(fCuidadores);

    // Ciclo de execução
    int i = 0;
    for (i = 0; i < numLeituras; i++)
    {
        // Atualizacao dos dados
        
        // Caminhar pela lista de idosos atualizando idosos
        IteraListaIdoso(idosos, AtualizaIdoso);
        // Caminhas pela lista de cuidadores atualizando cuidadores
        IteraListaCui(cuidadores, AtualizaCuidador);

        // Processamento das informações
        
        /*
        TODO: Funcao de conectar os idosos aos amigos ou cuidadores (chamar)
        dentro da lista de idosos,
        [a ser descutido abaixo]
        a mesma devera fazer a saida no arquivo saida presente no idoso?
        se entendi direito, acho que seria melhor uma funcao que so faz saida
        */
    }
    
    free(diretorioGeral);
    free(pathApoio);
    free(pathCuida);

    return 0;
}
