#ifndef LISTA_IDOSO_H_
#define LISTA_IDOSO_H_
#include "idoso.h"

typedef struct listaIdoso listaIdo;

listaIdo *IniciaListaIdoso();

void InsereListaIdoso(listaIdo *l, Idoso *idoso);

Idoso *RetornaIdosoProx(listaIdo *l, Geoloc *referencia);

Idoso *BuscaListaIdoso(listaIdo *l, char *nome);

Idoso *RetiraListaIdoso(listaIdo *l, char *nome);

void InsereAmizade(listaIdo *l, char *amg1, char *amg2);

void IteraListaIdoso(listaIdo *l, void (*funcao)(Idoso *));

void LiberaListaIdoso(listaIdo *l);

#endif // LISTA_IDOSO_H_
