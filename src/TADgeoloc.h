#ifndef GEOLOC_H
#define GEOLOC_H
typedef struct geoloc Geoloc;

//Inicializacao
Geoloc *InicializaGeo(int longitude, int latitude);
//Calcula distancia
double CalcDist(Geoloc *idoso, Geoloc *cuidador);
//Liberacao da memoria alocada
void LiberaGeo(Geoloc *entrada);

void MudaPos(Geoloc* saida,int longitude, int latitude);

void AtualizaIdoso(Idoso *entrada);


#endif