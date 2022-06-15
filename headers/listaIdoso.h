#ifndef LISTA_IDOSO_H
#define LISTA_IDOSO_H
#include "idoso.h"

typedef struct listaIdosos lIdosos;

lIdosos* IniciaListaIdoso();

void InsereListaIdoso(lIdosos* l, Idoso* idoso);

Idoso* BuscaListaIdoso(lIdosos* l, char* nome);

Idoso* RetiraListaIdoso(lIdosos* l, char* nome);

void LiberaListaIdoso(lIdosos* l);

void InsereAmizade(lIdosos* l, char* amg1, char* amg2);

#endif // LISTA_IDOSO_H
