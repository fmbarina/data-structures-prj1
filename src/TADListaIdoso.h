#ifndef LISTA_IDOSO_H
#define LISTA_IDOSO_H
#include "TADidoso.h"

typedef struct sentinelaIdoso ListaIdoso;

ListaIdoso* IniciaListaIdoso();

void InsereListaIdoso(ListaIdoso* li, Idoso* ido);

Idoso* RemoveListaIdoso(ListaIdoso* li, char* nome);

Idoso* BuscaListaIdoso(ListaIdoso li, char* nome);

void LiberaListaIdoso(ListaIdoso* li);

#endif // LISTA_IDOSO_H
