#include "TADListaCuidador.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct celulaCui CelulaCui;

struct celulaCui
{
	Cuidador *cuida;
	CelulaCui *prox;
};

struct listacui
{
	CelulaCui *prim;
	CelulaCui *ult;
};

ListaCui *IniciaListaCui()
{
	ListaCui *saida = (ListaCui *)malloc(sizeof(ListaCui));
	saida->prim = NULL;
	saida->ult = NULL;
	return saida;
}

void InsereListaCui(Cuidador *inserido, ListaCui *cs)
{
	// Insere na ultima posicao da lista
	CelulaCui *insertCel = (CelulaCui *)malloc(sizeof(CelulaCui));
	insertCel->cuida = inserido;
	insertCel->prox = NULL;
	if (cs->ult == NULL)
	{
		cs->prim = insertCel;
	}
	else
	{
		cs->ult->prox = insertCel;
	}
	cs->ult = insertCel;
}

Cuidador *RetornaCuidadorProx(ListaCui *cs, Idoso *referencia)
{
	// Esta vazia
	if (cs->prim == NULL)
	{
		printf("Lista de cuidadores vazia!!!\n");
		return NULL;
	}

	CelulaCui *aux = cs->prim;
	double Menordist = CalcDistGeo(GetLocalCuidador(aux->cuida), GetLocalIdoso(referencia));
	Cuidador *CuidadorMenor = cs->prim->cuida;

	while (aux != NULL)
	{
		if (CalcDistGeo(GetLocalCuidador(aux->cuida), GetLocalIdoso(referencia)) < Menordist)
		{
			CuidadorMenor = aux->cuida;
			Menordist = CalcDistGeo(GetLocalCuidador(aux->cuida), GetLocalIdoso(referencia));
		}
		aux = aux->prox;
	}

	return CuidadorMenor;
}

Cuidador *RetornaCuiListaCui(char *nomeCui, ListaCui *cs)
{
	CelulaCui  *atual = cs->prim;

	// Varre a lista procurando um cuidador com o nome especificado
	while (atual != NULL && strcmp(GetNomeCuidador(atual->cuida), nomeCui) != 0)
	{
		atual = atual->prox;
	}

	return atual->cuida;
}

Cuidador *RetiraListaCui(char *nomeCui, ListaCui *cs)
{
	CelulaCui *ant = NULL;
	CelulaCui *atual = cs->prim;
	Cuidador *saida = NULL;

	// Varre a lista procurando um cuidador com o nome especificado
	while (atual != NULL && strcmp(GetNomeCuidador(atual->cuida), nomeCui) != 0)
	{
		ant = atual;
		atual = atual->prox;
	}

	// Lista vazia
	if (cs->prim == NULL)
	{
		return NULL;
	}
	// Lista com unico elemento
	else if (cs->ult == cs->prim && cs->ult == atual)
	{
		cs->ult = NULL;
		cs->prim = NULL;
		saida = atual->cuida;
		free(atual);
		return saida;
	}
	// Eh o ultimo elemento
	else if (cs->ult == atual)
	{
		cs->ult = ant;
		ant->prox = NULL;
		saida = atual->cuida;
		free(atual);
		return saida;
	}
	// Eh o primeiro elemento
	else if (cs->prim == atual)
	{
		cs->prim = atual->prox;
		saida = atual->cuida;
		free(atual);
		return saida;
	}
	// Caso geral
	else
	{
		ant->prox = atual->prox;
		saida = atual->cuida;
		free(atual);
		return saida;
	}
}

void LiberaListaCui(ListaCui *cs)
{
	CelulaCui *aux = cs->prim;
	while (aux != NULL)
	{
		cs->prim = aux->prox;
		free(aux);
		aux = cs->prim;
	}
	free(cs);
}
