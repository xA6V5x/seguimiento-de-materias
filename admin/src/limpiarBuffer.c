#include <stdio.h>
#include <stdlib.h>
#include "../headers/funciones.h"

void limpiarBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}