#ifndef LISTA_CUIDADOR_H_
#define LISTA_CUIDADOR_H_
#include "cuidador.h"

typedef struct listaCui listaCui;

listaCui *IniciaListaCui();

void InsereListaCui(listaCui *l, Cuidador *cuidador);

Cuidador *RetornaCuidadorProx(listaCui *l, Geoloc *referencia);

Cuidador *BuscaListaCui(listaCui *l, char *nome);

Cuidador *RetiraListaCui(listaCui *l, char *nome);

void LiberaListaCui(listaCui *l);

#endif // LISTA_CUIDADOR_H_
