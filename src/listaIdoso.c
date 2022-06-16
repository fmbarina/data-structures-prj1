#include "listaIdoso.h"
#include "idoso.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celulaIdoso CelulaIdo;

struct celulaIdoso
{
    Idoso *idoso;
    CelulaIdo *prox;
};

struct listaIdoso
{
    CelulaIdo *prim;
    CelulaIdo *ult;
};

listaIdo *IniciaListaIdoso()
{
    listaIdo *l;
    l = (listaIdo *)malloc(sizeof(listaIdo));
    l->prim = NULL;
    l->ult = NULL;
    return l;
}

void InsereListaIdoso(listaIdo *l, Idoso *idoso)
{
    CelulaIdo *insertCel = (CelulaIdo *)malloc(sizeof(CelulaIdo));

    insertCel->idoso = idoso;
    insertCel->prox = NULL;

    if (l->ult == NULL)
        l->prim = insertCel;
    else
        l->ult->prox = insertCel;

    l->ult = insertCel;
}

Idoso *BuscaListaIdoso(listaIdo *l, char *nome)
{
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

Idoso *RetiraListaIdoso(listaIdo *l, char *nome)
{
    CelulaIdo *atual = l->prim;
    CelulaIdo *ant = NULL;

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

void InsereAmizade(listaIdo *l, char *amg1, char *amg2)
{
    Idoso *idoso = BuscaListaIdoso(l, amg1);
    Idoso *amigo = BuscaListaIdoso(l, amg2);

    InsereAmigoIdoso(idoso, amigo);
    InsereAmigoIdoso(amigo, idoso);
}

void IteraListaIdoso(listaIdo *l, void (*funcao)(Idoso *))
{
    CelulaIdo *atual = l->prim;

    // Varre a lista chamando a funcao passada
    while (atual != NULL)
    {
        funcao(atual->idoso);
        atual = atual->prox;
    }
}

void LiberaListaIdoso(listaIdo *l)
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