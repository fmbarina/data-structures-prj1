//
// Autores: Rhuan Garcia e Felipe M. Barina
//
#ifndef LISTA_CUIDADOR_H_
#define LISTA_CUIDADOR_H_
#include "cuidador.h"

typedef struct listaCui listaCui;

/**
 * @brief Aloca e inicia uma lista de cuidadores com uma sentinela vazia
 * 
 * @return listaCui* - Lista inicializada
 */
listaCui *IniciaListaCui();

/**
 * @brief Insere o cuidador ao final da lista de cuidadores acessada
 * 
 * @param l - Lista acessada
 * @param cuidador - Cuidador a ser inserido
 */
void InsereListaCui(listaCui *l, Cuidador *cuidador);

/**
 * @brief Retorna o cuidador mais proximo do ponto de referencia entre
 * os presentes na lista
 * 
 * @param l - Lista de cuidadores disponiveis
 * @param referencia - Ponto de referencia
 * @return Cuidador* - Cuidador mais proximo do ponto de referencia
 */
Cuidador *RetornaCuidadorProx(listaCui *l, Geoloc *referencia);

/**
 * @brief Busca na lista o cuidador que possui o nome informado e faz o retorno
 * do mesmo, retornando nulo caso a lista nao possua o mesmo
 * 
 * @param l - Lista acessada
 * @param nome - Nome a ser procurado 
 * @return Cuidador* - Cuidador achado // Null
 */
Cuidador *BuscaListaCui(listaCui *l, char *nome);

/**
 * @brief Retira da lista o cuidador que possui o nome informado, caso nao tenha um 
 * cuidador com mesmo nome, nao sera retirado e retornara nulo
 * 
 * @param l - Lista acessada
 * @param nome - Nome do cuidador a ser retirado
 * @return Cuidador* - Faz o Retorno do cuidador retirado da lista
 */
Cuidador *RetiraListaCui(listaCui *l, char *nome);

/**
 * @brief Faz a iteracao da lista executando a funcao passada como parametro 
 * em cada elemento
 * 
 * @param l - Lista acessada
 * @param funcao - Funcao a ser executada
 */
void IteraListaCui(listaCui *l, void (*funcao)(Cuidador *));

/**
 * @brief Libera a memoria alocada pela lista e suas celulas
 * 
 * @param l - Lista a ser liberada
 */
void LiberaListaCui(listaCui *l);

#endif // LISTA_CUIDADOR_H_
