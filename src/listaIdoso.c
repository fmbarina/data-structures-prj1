//
// Autores: Rhuan Garcia e Felipe M. Barina
//
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

    if (l->prim == NULL)
        l->prim = insertCel;
    else
        l->ult->prox = insertCel;

    l->ult = insertCel;
}

Idoso *RetornaIdosoProx(listaIdo *l, Geoloc *referencia)
{
    // Esta vazia
    if (l->prim == NULL)
    {
        printf("Lista de idosos vazia!!!\n");
        return NULL;
    }

    CelulaIdo *aux = l->prim;

    // Exclusão de mortos
    while (aux && GetCondicaoIdoso(aux->idoso) < 0)
        aux = aux->prox;

    // Nao tem idosos, infelizmente todos os amigos morreram! [ou sem amigos]
    if (aux == NULL)
        return NULL;

    double Menordist = CalcDistGeo(GetLocalIdoso(aux->idoso), referencia);
    Idoso *IdosoMenor = aux->idoso;

    while (aux != NULL)
    {

        if (GetCondicaoIdoso(aux->idoso) >= 0 &&
            CalcDistGeo(GetLocalIdoso(aux->idoso), referencia) < Menordist)
        {
            IdosoMenor = aux->idoso;
            Menordist = CalcDistGeo(GetLocalIdoso(aux->idoso), referencia);
        }

        aux = aux->prox;
    }

    return IdosoMenor;
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

    CelulaIdo *aux = l->prim;

    while (aux != NULL)
    {
        l->prim = aux->prox;
        free(aux);
        aux = l->prim;
    }

    free(l);
}