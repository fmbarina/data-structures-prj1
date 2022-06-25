//
// Autores: Rhuan Garcia e Felipe M. Barina
//
#ifndef CUIDADOR_H_
#define CUIDADOR_H_
#include "geoloc.h"

typedef struct cuidador Cuidador;
/**
 * @brief Faz a alocacao de memoria e inicializacao
 * de uma variavel do tipo cuidador
 * 
 * @param nome - Nome do cuidador a ser inicializado
 * @param diretorio - Diretorio onde estarao os arquivos de entrada
 * @return Cuidador* - Cuidador inicializado
 */
Cuidador *IniciaCuidador(char *nome, char *diretorio);

// /**
//  * @brief Retorna a Ocupacao do objeto Cuidador
//  * 
//  * @param cui 
//  * @return int 
//  */
// int GetOcupacaoCuidador(Cuidador *cui);

/**
 * @brief Retorna o Nome do objeto Cuidador
 * 
 * @param cui 
 * @return char* 
 */
char *GetNomeCuidador(Cuidador *cui);

// /**
//  * @brief Define o Ocupacao do objeto Cuidador
//  * 
//  * @param cui 
//  * @param ocupacao 
//  */
// void SetOcupacaoCuidador(Cuidador *cui, int ocupacao);

/**
 * @brief Retorna o Local (de tipo Geoloc) do objeto Cuidador
 * 
 * @param cui 
 * @return Geoloc* 
 */
Geoloc *GetLocalCuidador(Cuidador *cui);

/**
 * @brief Define o Local (de tipo Geoloc) do objeto Cuidador
 * 
 * @param cui 
 * @param longitude 
 * @param latitude 
 */
void SetLocalCuidador(Cuidador *cui, int longitude, int latitude);

/**
 * @brief Faz a leitura de uma nova linha do arquivo referente
 * ao cuidador, atualizando seu local no dado tempo
 * 
 * @param cui 
 */
void AtualizaCuidador(Cuidador *cui);


/**
 * @brief Libera a memoria alocada para tal cuidador
 * 
 * @param cui 
 */
void LiberaCuidador(Cuidador *cui);

#endif // CUIDADOR_H_
