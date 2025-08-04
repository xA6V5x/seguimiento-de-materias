#include <stdio.h>
#include <stdlib.h>
#include "../headers/funciones.h"

void printMenuPrincipal(const int opcionesArrayLength, const opcion_accion_t *opcionesArray)
{
    system("cls");
    printf("== ADMINISTRAR MATERIAS ==\n");
    for (int i = 0; i < opcionesArrayLength; i++)
    {
        printf("%d - %s\n", i + 1, opcionesArray[i].text);
    };
    printf("-------------------------------\n");
    printf("0 - Salir\n");
    printf("\nSeleccione una opcion: ");
}
