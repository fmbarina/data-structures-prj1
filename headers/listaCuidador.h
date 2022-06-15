#ifndef LISTA_CUIDADOR_H
#define LISTA_CUIDADOR_H
#include "cuidador.h"

typedef struct listaCuidadores lCuidadores;

lCuidadores *IniciaListaCui();

void InsereListaCui(lCuidadores *l, Cuidador *cuidador);

Cuidador *RetornaCuidadorProx(lCuidadores *l, Geoloc *referencia);

Cuidador *BuscaListaCui(lCuidadores *l, char *nome);

Cuidador *RetiraListaCui(lCuidadores *l, char *nome);

void LiberaListaCui(lCuidadores *l);

#endif // LISTA_CUIDADOR_H
