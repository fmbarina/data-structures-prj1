#include "pathman.h"
#include <stdlib.h>
#include <string.h>

#define DIVISOR "/\0" // String do divisor de diretorios

char *expth(char *path, char *add)
{
    char *new_path = malloc(strlen(path) + strlen(add) + 1);

    strcpy(new_path, path);
    strcat(new_path, add);
    free(path);

    return new_path;
}

static char *shorten_path(char *path, int characters)
{
    char *new_path = malloc(strlen(path) - characters + 1);

    strncpy(new_path, path, strlen(path) - characters);
    new_path[strlen(path) - characters] = '\0';
    free(path);

    return new_path;
}

char *trpth(char *path)
{
    if (strlen(path) <= 2)
        return path;

    int i = strlen(path) - 1;

    if (path[strlen(path) - 1] == DIVISOR[0])
        i--;

    while (path[i] != DIVISOR[0])
        i--;

    return shorten_path(path, strlen(path) - i);
}

char *adpth(char *path, char *add)
{
    if (path[strlen(path) - 1] != DIVISOR[0])
        path = expth(path, DIVISOR);

    return expth(path, add);
}