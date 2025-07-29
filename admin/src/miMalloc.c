#include <stdio.h>
#include <stdlib.h>
#include "../headers/funciones.h"

void *miMalloc(char *contexto, size_t size)
{
    if (size == 0)
    {
        printf("Error: se ha intentado asignar memoria de size cero en %s.\n", contexto);
        esperarEnter();
        exit(1);
    }

    void *ptr = malloc(size);
    if (ptr == NULL)
    {
        printf("Error al asignar memoria para %s.\n", contexto);
        esperarEnter();
        exit(1);
    }

    return ptr;
}