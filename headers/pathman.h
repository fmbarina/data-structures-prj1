//
// Autores: Rhuan Garcia e Felipe M. Barina
//
#ifndef PATHMAN_H_
#define PATHMAN_H_

/*
 * Funções simples para facilitar uso e manipulação de strings de caminhos.
 * Feita para o trabalho I de Estrutura de Dados I. Se fosse um projeto sério,
 * seria melhor usar algo como cwalk.
 *
 * A alocação e liberação de memória deve ocorrer externamente.
 * Todas as funções assumem uma string "path" válida, pré-alocada.
 */

/**
 * @brief Extend path: adiciona uma string no final do caminho
 *
 * @param path - string de caminho
 * @param add - string a ser adicionada no fim
 * @return char* - nova string do caminho extendido
 */
char *expth(char *path, char *add);

/**
 * @brief Trim path: remove caracteres do fim até o primeiro divisor (incluso),
 * se o path terminar com o divisor, ignora e procura o anterior.
 *
 * @param path - string de caminho
 * @return char* - nova string do caminho reduzido
 */
char *trpth(char *path);

/**
 * @brief adiciona uma string no final do caminho, com um divisor no meio
 * se o path terminar com um divisor, não o adiciona novamente.
 *
 * @param path - string de caminho
 * @param add - string a ser adicionada no fim
 * @return char* - nova string do caminho extendido com um divisor
 */
char *adpth(char *path, char *add);

#endif // PATHMAN_H_
