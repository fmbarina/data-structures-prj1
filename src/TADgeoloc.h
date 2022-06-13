#ifndef GEOLOC_H
#define GEOLOC_H

typedef struct geoloc Geoloc;

Geoloc *IniciaGeo(int longitude, int latitude);

double CalcDistGeo(Geoloc *g1, Geoloc *g2);

void MudaPosGeo(Geoloc* geo,int longitude, int latitude);

void LiberaGeo(Geoloc *geo);

#endif // GEOLOC_H
