#ifndef LISTA_CUIDADOR_H
#define LISTA_CUIDADOR_H
#include "TADidoso.h"
#include "TADcuidador.h"

typedef struct listacui ListaCui;

ListaCui *IniciaListaCui();

void InsereListaCui(Cuidador *inserido, ListaCui *cs);

Cuidador *RetornaCuidadorProx(ListaCui *cs, Idoso *referencia);

Cuidador *RetornaCuiListaCui(char *nomeCui, ListaCui *cs);

Cuidador *RetiraListaCui(char *nomeCui, ListaCui *cs);

void LiberaListaCui(ListaCui *cs);

#endif
