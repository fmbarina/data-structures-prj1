#include "TADListaIdoso.h"
#include "TADidoso.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct celulaIdoso CelulaIdo;

struct celulaIdoso
{
    Idoso *ido;
    CelulaIdo *prox;
};

struct sentinelaIdoso
{
    CelulaIdo *prim;
    CelulaIdo *ult;
};

ListaIdoso *IniciaListaIdoso()
{
    ListaIdoso *li;
    li = (ListaIdoso *)malloc(sizeof(ListaIdoso));
    li->prim = NULL;
    li->ult = NULL;
    return li;
}

void InsereListaIdoso(ListaIdoso *li, Idoso *ido)
{
    if (!li)
        return;

    CelulaIdo *novo = (CelulaIdo *)malloc(sizeof(CelulaIdo));

    novo->ido  = ido;
    novo->prox = NULL;

    if (li->ult == NULL)
	{
		li->prim = novo;
	}
	else
	{
		li->ult->prox = novo;
	}
	li->ult = novo;
}

Idoso *RemoveListaIdoso(ListaIdoso *li, char *nome)
{
    if (!li || li->prim == NULL)
        return NULL;

    CelulaIdo *atual = li->prim;
    CelulaIdo *ant   = NULL;

    while (atual != NULL)
    {
        if (!strcmp(nome, GetNomeIdoso(atual->ido)))
            break;

        ant = atual;
        atual = atual->prox;
    }

    if (atual != NULL)
    {
        // Inicio
        if (ant == NULL)
        {
            li->prim = atual->prox;

            // lista so tem um elemento
            if (li->ult == li->prim)
                li->ult = NULL;
        }
        // Fim
        else if (atual == li->ult)
        {
            li->ult = ant;
            li->ult->prox = NULL;
        }
        // Meio
        else
        {
            ant->prox = atual->prox;
        }
    }

    return atual->ido;
}

Idoso *BuscaListaIdoso(ListaIdoso *li, char *nome)
{
    if (!li)
        return NULL;

    CelulaIdo *atual = li->prim;

    while (atual != NULL)
    {
        if (!strcmp(nome, GetNomeIdoso(atual->ido)))
            break;

        atual = atual->prox;
    }

    if (atual != NULL)
        return atual->ido;

    return NULL;
}

void LiberaListaIdoso(ListaIdoso *li)
{
    if (!li)
        return;

    CelulaIdo *temp = li->prim;
    CelulaIdo *prox = NULL;

    while (temp != NULL)
    {
        prox = temp->prox;
        free(temp);
        temp = prox;
    }

    free(li);
}

void InsereAmizade(ListaIdoso* li, char* amg1, char*amg2)
{
    Idoso* idoso = BuscaListaIdoso(li, amg1);
    Idoso* amigo = BuscaListaIdoso(li, amg2);

    InsereAmigoIdoso(idoso, amigo);
    InsereAmigoIdoso(amigo, idoso);
}

static int validaLI(ListaIdoso *li)
{
    if (!li)
    {
        printf("AVISO: Lista de idosos não alocada.");
        return 0;
    }
    return 1;
}

