#ifndef LISTA_CUIDADOR_H
#define LISTA_CUIDADOR_H
#include "TADidoso.h"
#include "TADcuidador.h"

typedef struct listacui ListaCui;

ListaCui* IniciaListaCui();

void InsereListaCui(Cuidador* inserido, ListaCui* cs);

Cuidador* RetornaCuidadorProx(ListaCui* cs, Idoso* referencia);

Cuidador* RetornaCuiListaCui(int idCui, ListaCui* cs);

Cuidador* RetiraListaCui(int idRemov, ListaCui* cs);

void LiberaListaCui(ListaCui* cs);

#endif
