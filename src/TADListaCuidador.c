#include "TADListaCuidador.h"

typedef struct celulaCui CelulaCui;

struct celulaCui{
	Cuidador* cuida;
	CelulaCui* prox;
};

struct listacui{
	CelulaCui* prim;
	CelulaCui* ult;
}

typedef struct listacui ListaCui;

ListaCui* IniciaListaCui(){
	ListaCui* saida = (ListaCui*) malloc(sizeof(ListaCui));
	saida->prim = NULL;
	saida->ult = NULL;
	return saida;
}

void InsereListaCui(Cuidador* inserido, ListaCui* cs){
	CelulaCui* insertCel = (CelulaCui*) malloc(sizeof(CelulaCui));
	insertCel->cuida = inserido;
	insertCel->prox = NULL;
	if(cs->ult == NULL){
		cs->prim = insertCel;
	}
	else
	{
		cs->ult->prox = insertCel;
	}
	cs->ult = insertCel;
}

Cuidador* RetornaCuidadorProx(ListaCui* cs, Idoso* referencia){
	//Esta vazia
	if (listona->prim == NULL){
		printf("Lista de cuidadores vazia!!!\n");
		return NULL;
	}
	
	CelulaCui* aux = cs->prim;
	double Menordist=CalcDistGeo(GetLocalCuidador(aux->cuida),GetLocalIdoso(referencia));
	Cuidador* CuidadorMenor = cs->prim;
	
	while(aux!=NULL)
	{
		if(CalcDistGeo(GetLocalCuidador(aux->cuida),GetLocalIdoso(referencia))<Menordist)
		{
			CuidadorMenor = aux->cuida;
			Menordist = CalcDistGeo(GetLocalCuidador(aux->cuida),GetLocalIdoso(referencia));
		}
		aux = aux->prox;
	}
	
	return CuidadorMenor;
}

Cuidador* RetornaCuiListaCui(int idCui, ListaCui* cs){
	CelulaCui *ant = NULL; *atual = cs->prim;
	
	while(atual!=NULL&&GetIdCuidador(atual)!=idCui)
	{
		ant = atual;
		atual = atual->prox;
	}
	
	return atual;
}

Cuidador* RetiraListaCui(int idRemov, ListaCui* cs){
	CelulaCui *ant = NULL; *atual = cs->prim;
	Cuidador* saida=NULL;
	while(atual!=NULL&&GetIdCuidador(atual)!=idRemov)
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
	else if (cs->ult == cs->prim && cs->final == atual)
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
	else {
		ant->prox = atual->prox;
		saida = atual->cuida;
		free(atual);
		return saida;
	}
}

void LiberaListaCui(ListaCui* cs){
	CelulaCui* aux = cs->prim;
	while(aux!=NULL){
		cs->inic = aux->prox;
		free(aux);
		aux = cs->inic;
	}
	free(cs);
}

