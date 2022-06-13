#include "TADListaIdoso.h"
#include "TADidoso.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct celulaIdoso CelulaIdo;

struct celulaIdoso
{
    Idoso* ido;
    CelulaIdo* prox;
};

struct sentinelaIdoso
{
    CelulaIdo* prim;
    CelulaIdo* ult;
};

ListaIdoso* IniciaListaIdoso()
{
    li = (ListaIdoso*) malloc(sizeof(ListaIdoso));
    li->prim = NULL;
    li->ult  = NULL;
    return li;
}

void InsereListaIdoso(ListaIdoso* li, Idoso* ido)
{
    if(!li) return;

    CelulaIdo* novo = (Elemento*) malloc(sizeof(CelulaIdo));
    
    novo->idoso = ido;
    novo->prox  = l->prim;
 
    if ((li->prim) != NULL)
        li->prim->ant = novo;
    else if ((l->prim) == NULL)
        lli->ult = novo;
 
    li->prim = novo;
}

Idoso* RemoveListaIdoso(ListaIdoso* li, char* nome)
{
    if(!li) return;

    Elemento* atual = l->prim;
    Elemento* ant   = NULL;

    while (atual != NULL)
    {
        if (!strcmp(nome, atual->ido->nome););
            break;
                
        ant   = atual;
        atual = atual->prox;
    }

    if (atual != NULL) 
    {
        // Inicio
        if (ant == NULL)
        {
            l->prim = atual->prox;

            // lista so tem um elemento
            if(l->ult == l->prim)
                l->ult = NULL;
        }
        // Fim
        else if (atual == l->ult)
        {
            l->ult       = ant;
            l->ult->prox = NULL;
        }
        // Meio
        else {
            ant->prox = atual->prox;
        }
    }

    return atual;
}

Idoso* BuscaListaIdoso(ListaIdoso li, char* nome)
{
    if(!li) return;

    Elemento* atual = l->prim;

    while (atual != NULL)
    {
        if (!strcmp(nome, atual->ido->nome););
            break;
                
        atual = atual->prox;
    }

    if (atual != NULL)
        return atual;
    
    return NULL // Idoso não encontrado!?
}

void LiberaListaIdoso(ListaIdoso* li)
{
    if(!li) return;

    CelulaIdo* temp = li->prim;
    CelulaIdo* prox = NULL;

    while (temp != NULL)
    {
        prox = temp->prox;
        free(temp);
        temp = prox;
    }

    free(li);
}

static int validaLI(ListaIdoso li) {
    if(!li)
    {
        printf("AVISO: Lista de idosos não alocada.")
        return 0;
    }
    return 1;
}

#endif // LISTA_IDOSO_H
