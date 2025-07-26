#include <stdio.h>
#include <stdlib.h>
#include "../headers/funciones.h"

void esperarEnter()
{
    // Limpia cualquier resto de caracteres previos
    limpiarBuffer();

    printf("Presione Enter para continuar...");
    // Espera a que el usuario presione Enter
    limpiarBuffer();
}