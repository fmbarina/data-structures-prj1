//
// Autores: Rhuan Garcia e Felipe M. Barina
//
#ifndef IDOSO_H_
#define IDOSO_H_
#include "geoloc.h"
#include "cuidador.h"

typedef struct idoso Idoso;

/**
 * @brief Faz a alocacao de memoria e inicializacao
 * de uma variavel do tipo Idoso
 * 
 * @param nome - Nome do Idoso a ser inicializado
 * @param diretorio - Diretorio onde estarao os arquivos de entrada
 * @return Idoso* - Idoso inicializado
 */
Idoso *IniciaIdoso(char *nome, char *diretorio);

/**
 * @brief Retorna o Nome do objeto Idoso
 * 
 * @param ido - Idoso acessado
 * @return char* - Atual nome do Idoso
 */
char *GetNomeIdoso(Idoso *ido);

/**
 * @brief Define o Nome do objeto Idoso
 * 
 * @param ido - Idoso acessado
 * @param nome - Novo nome que devera ser atribuido
 */
void SetNomeIdoso(Idoso *ido, char *nome);

/**
 * @brief Retorna o Local do Idoso (Como Geoloc)
 * 
 * @param ido - Idoso acessado
 * @return Geoloc* - Local do Idoso
 */
Geoloc *GetLocalIdoso(Idoso *ido);

/**
 * @brief Define o Local do Idoso para as novas coordenadas
 * 
 * @param ido - Idoso acessado
 * @param longitude - Novas coordenadas
 * @param latitude - Novas coordenadas
 */
void SetLocalIdoso(Idoso *ido, int longitude, int latitude);

/**
 * @brief Retorna a condicao atual do idoso, respeitando a seguinte tabela
 *      -2  = Bem morto
 *      -1  = A informar, morto
 *      0   = Bem
 *      1   = Necessita de amigos
 *      2   = Necessita de cuidador, febre alta
 *      3   = Necessita de cuidador, febre baixa pela 4a vez
 *      4   = Necessita de cuidador, queda
 * 
 * @param ido - Idoso acessado
 * @return int - Condicao atual do Idoso
 */
int GetCondicaoIdoso(Idoso *ido);

/**
 * @brief Define uma nova Condicao ao Idoso
 * 
 * @param ido - Idoso acessado
 * @param condicao - Nova condicao de idoso
 */
void SetCondicaoIdoso(Idoso *ido, int condicao);

/**
 * @brief Retorna quantas Febres baixas seguidas o Idoso em questao teve
 * 
 * @param ido - Idoso acessado
 * @return int - Febres seguidas
 */
int GetFebresIdoso(Idoso *ido);

/**
 * @brief Incrementa o contador de febres baixas seguidas do Idoso
 * 
 * @param ido - Idoso acessado
 */
void IncFebresIdoso(Idoso *ido);

/**
 * @brief Zera o contador de febres baixas do Idoso
 * 
 * @param ido - Idoso acessado
 */
void ResetFebresIdoso(Idoso *ido);

/**
 * @brief Faz a leitura de uma nova linha do arquivo referente
 * ao Idoso, atualizando seus dados no dado tempo
 * 
 * @param ido - Idoso a ser atualizado
 */
void AtualizaIdoso(Idoso *ido);

/**
 * @brief Insere um novo cuidador a lista de cuidadores que o Idoso acessado
 * pode requisitar.
 * 
 * @param ido - Idoso acessado
 * @param cui - Cuidador a ser inserido
 */
void InsereCuidadorIdoso(Idoso *ido, Cuidador *cui);

/**
 * @brief Insere um novo idoso a lista de amizades do Idoso acessado
 * 
 * @param ido - Idoso acessado
 * @param amigo - Amigo a ser inserido
 */
void InsereAmigoIdoso(Idoso *ido, Idoso *amigo);

/**
 * @brief Dadas as informacoes atualizadas do idoso, essa funcao eh responsavel
 * por processar as informacoes obtidas e atualizar a condicao do idoso em 
 * questao
 * 
 * @param ido - Idoso a ser processado 
 */
void ProcessaIdoso(Idoso *ido);

/**
 * @brief Libera a memoria alocada para a variavel de tipo Idoso
 * 
 * @param ido - Idoso a ser liberado
 */
void LiberaIdoso(Idoso *ido);

#endif // IDOSO_H_
