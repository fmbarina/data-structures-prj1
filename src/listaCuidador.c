#include "listaCuidador.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celulaCuidador CelulaCui;

struct celulaCuidador
{
	Cuidador *cuida;
	CelulaCui *prox;
};

struct listaCui
{
	CelulaCui *prim;
	CelulaCui *ult;
};

listaCui *IniciaListaCui()
{
	listaCui *saida = (listaCui *)malloc(sizeof(listaCui));
	saida->prim = NULL;
	saida->ult = NULL;
	return saida;
}

void InsereListaCui(listaCui *l, Cuidador *novo)
{
	// Insere na ultima posicao da lista
	CelulaCui *insertCel = (CelulaCui *)malloc(sizeof(CelulaCui));
	insertCel->cuida = novo;
	insertCel->prox = NULL;
	if (l->ult == NULL)
	{
		l->prim = insertCel;
	}
	else
	{
		l->ult->prox = insertCel;
	}
	l->ult = insertCel;
}

Cuidador *RetornaCuidadorProx(listaCui *l, Geoloc *referencia)
{
	// Esta vazia
	if (l->prim == NULL)
	{
		printf("Lista de cuidadores vazia!!!\n");
		return NULL;
	}

	CelulaCui *aux = l->prim;
	double Menordist = CalcDistGeo(GetLocalCuidador(aux->cuida), referencia);
	Cuidador *CuidadorMenor = l->prim->cuida;

	while (aux != NULL)
	{
		if (CalcDistGeo(GetLocalCuidador(aux->cuida), referencia) < Menordist)
		{
			CuidadorMenor = aux->cuida;
			Menordist = CalcDistGeo(GetLocalCuidador(aux->cuida), referencia);
		}
		aux = aux->prox;
	}

	return CuidadorMenor;
}

Cuidador *BuscaListaCui(listaCui *l, char *nome)
{
	CelulaCui *atual = l->prim;

	// Varre a lista procurando um cuidador com o nome especificado
	while (atual != NULL && strcmp(GetNomeCuidador(atual->cuida), nome) != 0)
	{
		atual = atual->prox;
	}

	return atual->cuida;
}

Cuidador *RetiraListaCui(listaCui *l, char *nome)
{
	CelulaCui *ant = NULL;
	CelulaCui *atual = l->prim;
	Cuidador *saida = NULL;

	// Varre a lista procurando um cuidador com o nome especificado
	while (atual != NULL && strcmp(GetNomeCuidador(atual->cuida), nome) != 0)
	{
		ant = atual;
		atual = atual->prox;
	}

	// Lista vazia
	if (l->prim == NULL)
	{
		return NULL;
	}
	// Lista com unico elemento
	else if (l->ult == l->prim && l->ult == atual)
	{
		l->ult = NULL;
		l->prim = NULL;
		saida = atual->cuida;
		free(atual);
		return saida;
	}
	// Eh o ultimo elemento
	else if (l->ult == atual)
	{
		l->ult = ant;
		ant->prox = NULL;
		saida = atual->cuida;
		free(atual);
		return saida;
	}
	// Eh o primeiro elemento
	else if (l->prim == atual)
	{
		l->prim = atual->prox;
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

void LiberaListaCui(listaCui *l)
{
	CelulaCui *aux = l->prim;
	while (aux != NULL)
	{
		l->prim = aux->prox;
		free(aux);
		aux = l->prim;
	}
	free(l);
}
