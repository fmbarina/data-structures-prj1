//
// Autores: Rhuan Garcia e Felipe M. Barina
//
#ifndef GEOLOC_H_
#define GEOLOC_H_

typedef struct geoloc Geoloc;

/**
 * @brief Faz a alocacao de memoria e inicializacao
 * de uma variavel do tipo Geoloc, responsavel por
 * armazenas e gerir a localizacao
 * 
 * @param longitude - Coordenada inicial
 * @param latitude  - Coordenada inicial
 * @return Geoloc* - Geolocalizacao iniciada
 */
Geoloc *IniciaGeo(int longitude, int latitude);

/**
 * @brief Calcula a distancia entre duas localizacoes
 * Retornando um double resultante do calculo
 * 
 * @param g1 - Ponto 1
 * @param g2 - Ponto 2
 * @return double - Distancia entre eles
 */
double CalcDistGeo(Geoloc *g1, Geoloc *g2);

/**
 * @brief Define a geolocalizacao dada para os valores de
 * latitude e longitude passados
 * 
 * @param geo - Geoloc a ser atualizado
 * @param longitude - Nova coordenada
 * @param latitude - Nova coordenada
 */
void MudaPosGeo(Geoloc *geo, int longitude, int latitude);


/**
 * @brief Libera a memoria alocada para a variavel de tipo
 * Geoloc
 * 
 * @param geo - Geoloc a ser liberado
 */
void LiberaGeo(Geoloc *geo);

#endif // GEOLOC_H_
