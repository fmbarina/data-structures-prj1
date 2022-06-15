#include "listaIdoso.h"
#include "idoso.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct celulaIdoso CelulaIdo;

struct celulaIdoso
{
    Idoso *idoso;
    CelulaIdo *prox;
};

struct listaIdosos
{
    CelulaIdo *prim;
    CelulaIdo *ult;
};

lIdosos *IniciaListaIdoso()
{
    lIdosos *l;
    l = (lIdosos *)malloc(sizeof(lIdosos));
    l->prim = NULL;
    l->ult = NULL;
    return l;
}

void InsereListaIdoso(lIdosos* l, Idoso* idoso)
{
    if (!l)
        return;

    CelulaIdo *insertCel = (CelulaIdo *)malloc(sizeof(CelulaIdo));

    insertCel->idoso = idoso;
    insertCel->prox  = NULL;

    if (l->ult == NULL)
		l->prim = insertCel;
	else
		l->ult->prox = insertCel;

	l->ult = insertCel;
}

Idoso* BuscaListaIdoso(lIdosos* l, char* nome)
{
    if (!l)
        return NULL;

    CelulaIdo *atual = l->prim;

    while (atual != NULL)
    {
        if (!strcmp(nome, GetNomeIdoso(atual->idoso)))
            break;

        atual = atual->prox;
    }

    if (atual != NULL)
        return atual->idoso;

    return NULL;
}

Idoso* RetiraListaIdoso(lIdosos* l, char* nome)
{
    if (!l || l->prim == NULL)
        return NULL;

    CelulaIdo *atual = l->prim;
    CelulaIdo *ant   = NULL;

    while (atual != NULL)
    {
        if (!strcmp(nome, GetNomeIdoso(atual->idoso)))
            break;

        ant = atual;
        atual = atual->prox;
    }

    if (atual != NULL)
    {
        // Inicio
        if (ant == NULL)
        {
            l->prim = atual->prox;

            // lista so tem um elemento
            if (l->ult == l->prim)
                l->ult = NULL;
        }
        // Fim
        else if (atual == l->ult)
        {
            l->ult = ant;
            l->ult->prox = NULL;
        }
        // Meio
        else
        {
            ant->prox = atual->prox;
        }
    }

    return atual->idoso;
}

void LiberaListaIdoso(lIdosos* l)
{
    if (!l)
        return;

    CelulaIdo *temp = l->prim;
    CelulaIdo *prox = NULL;

    while (temp != NULL)
    {
        prox = temp->prox;
        free(temp);
        temp = prox;
    }

    free(l);
}

void InsereAmizade(lIdosos* l, char* amg1, char* amg2)
{
    Idoso* idoso = BuscaListaIdoso(l, amg1);
    Idoso* amigo = BuscaListaIdoso(l, amg2);

    InsereAmigoIdoso(idoso, amigo);
    InsereAmigoIdoso(amigo, idoso);
}
