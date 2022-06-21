#ifndef LISTA_IDOSO_H_
#define LISTA_IDOSO_H_
#include "idoso.h"

typedef struct listaIdoso listaIdo;

/**
 * @brief Aloca e inicia uma lista de Idosos com uma sentinela vazia
 *
 * @return listaIdo* - Lista inicializada
 */
listaIdo *IniciaListaIdoso();

/**
 * @brief Insere o Idoso ao final da lista de idosos acessada
 *
 * @param l - Lista acessada
 * @param idoso - Idoso a ser inserido
 */
void InsereListaIdoso(listaIdo *l, Idoso *idoso);

/**
 * @brief Retorna o Idoso mais proximo do ponto de referencia entre
 * os presentes na lista
 *
 * @param l - Lista de Idosos disponiveis
 * @param referencia - Ponto de referencia
 * @return Idoso* - Idoso mais proximo do ponto de referencia
 */
Idoso *RetornaIdosoProx(listaIdo *l, Geoloc *referencia);

/**
 * @brief Busca na lista o Idoso que possui o nome informado e faz o retorno
 * do mesmo, retornando nulo caso a lista nao possua o mesmo
 *
 * @param l - Lista acessada
 * @param nome - Nome a ser procurado
 * @return Idoso* - Idoso achado // Null
 */
Idoso *BuscaListaIdoso(listaIdo *l, char *nome);

/**
 * @brief Retira da lista o Idoso que possui o nome informado, caso nao tenha um
 * cuidador com mesmo nome, nao sera retirado e retornara nulo
 *
 * @param l - Lista acessada
 * @param nome - Nome a ser procurado
 * @return Idoso* - Idoso retirado da lista
 */
Idoso *RetiraListaIdoso(listaIdo *l, char *nome);

/**
 * @brief Cria o um laco de amizade, inserindo o amigo na lista de amigos um do outro
 * Como amizades sao reciprocas, amg1 eh inserido na lista de amigos de amg2 e amg2 inserido
 * na lista de amigos de amg1
 *
 * @param l - Lista de Idosos em que estao inseridos
 * @param amg1 - Idoso a fazer amizade
 * @param amg2 - Idoso a fazer amizade
 */
void InsereAmizade(listaIdo *l, char *amg1, char *amg2);

/**
 * @brief Faz a iteracao da lista executando a funcao passada como parametro
 * em cada elemento
 *
 * @param l - Lista acessada
 * @param funcao - Funcao a ser executada
 */
void IteraListaIdoso(listaIdo *l, void (*funcao)(Idoso *));

/**
 * @brief Libera a memoria alocada pela lista e suas celulas
 *
 * @param l - Lista a ser liberada
 */
void LiberaListaIdoso(listaIdo *l);

#endif // LISTA_IDOSO_H_
