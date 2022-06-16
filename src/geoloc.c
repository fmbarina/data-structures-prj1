#include "geoloc.h"
#include <stdlib.h>
#include <math.h>

struct geoloc
{
    float latitude;
    float longitude;
};

Geoloc *IniciaGeo(int longitude, int latitude)
{
    Geoloc *geo = (Geoloc *)malloc(sizeof(Geoloc));
    geo->latitude = latitude;
    geo->longitude = longitude;
    return geo;
}

double CalcDistGeo(Geoloc *g1, Geoloc *g2)
{
    return sqrt(pow(g1->latitude - g2->latitude, 2) +
                pow(g1->longitude - g2->longitude, 2));
}

void MudaPosGeo(Geoloc *geo, int longitude, int latitude)
{
    geo->latitude = latitude;
    geo->longitude = longitude;
}

void LiberaGeo(Geoloc *geo)
{
    free(geo);
}
