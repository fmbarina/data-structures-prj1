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

/* Extend path: adiciona uma string no final do caminho
 * @input: path - string de caminho
 * @input: add - string a ser adicionada no fim
 * @output: path - nova string do caminho extendido
 */
char *expth(char *path, char *add);

/* Trim path: remove caracteres do fim até o primeiro divisor (incluso),
 * se o path terminar com o divisor, ignora e procura o anterior.
 * @input: path - string de caminho
 * @output: path - nova string do caminho reduzido
 */
char *trpth(char *path);

/* Add path: adiciona uma string no final do caminho, com um divisor no meio
 * se o path terminar com um divisor, não o adiciona novamente.
 * @input: path - string de caminho
 * @input: add - string a ser adicionada no fim
 * @output: path - nova string do caminho extendido com um divisor
 */
char *adpth(char *path, char *add);

#endif // PATHMAN_H_
