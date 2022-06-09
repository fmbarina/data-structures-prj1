

#include "TADgeoloc.h"
#include <math.h>
struct geoloc
{
    float latitude;
    float longitude;
};

Geoloc *InicializaGeo(int longitude, int latitude)
{
    Geoloc *saida = (Geoloc *)malloc(sizeof(Geoloc));
    saida->latitude = latitude;
    saida->longitude = longitude;
    return saida;
}
double CalcDist(Geoloc *idoso, Geoloc *cuidador)
{
    double dist;
    dist = sqrt(pow(idoso->latitude - cuidador->latitude, 2) +
                pow(idoso->longitude - cuidador->longitude, 2));
    return dist;
}
void LiberaGeo(Geoloc *entrada)
{
    free(entrada);
}
void MudaPos(Geoloc *saida, int longitude, int latitude)
{
    saida->latitude = latitude;
    saida->longitude = longitude;
}