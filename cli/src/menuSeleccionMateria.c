#include <stdio.h>
#include <stdlib.h>
#include "../headers/funciones.h"
#include "../headers/types.h"

void menuSeleccionMateria(char *titulo, int materiasLength, materia_t *materiasArray)
{
    int opcion;

    do
    {
        system("cls");
        printf("== %s ==\n", titulo);
        printf("0 - Volver\n");
        printf("-------------------------------\n");
        for (int i = 0; i < materiasLength; i++)
        {
            printf("%d - %s\n", i + 1, materiasArray[i].nombre);
        }
        printf("\nSeleccione una opcion: ");
        scanf("%d", &opcion);
        limpiarBuffer();

        if (opcion == 0)
        {
            break;
        }
        else if (opcion >= 1 && opcion <= materiasLength)
        {
            int indexMateriaSeleccionada = opcion - 1;
            materiaInfo(materiasArray[indexMateriaSeleccionada], materiasLength, materiasArray);
        }
        else
        {
            errorOpcionNoValida();
        }
    } while (opcion != 0);
}
