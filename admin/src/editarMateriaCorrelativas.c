#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/config.h"
#include "../headers/funciones.h"
#include "../headers/types.h"

void editarMateriaCorrelativas(materia_archivo_t *materia)
{
    int opcion;

    int contadorOpcion = 1;

    materias_t materias = leerBinDeMaterias();

    int estadoId = 0;

    int materiasLength = materias.length;

    materia_archivo_t *materiasArray = materias.array;
    do
    {
        system("cls");

        printf("== SELECCIONAR CORRELATIVAS ==\n");
        printf("0 - Cancelar\n");
        printf("-------------------------------\n");

        if (materia->correlativasLength > 0)
        {
            for (int i = 0; i < materia->correlativasLength; i++)
            {
                printf("%d - %d\n", contadorOpcion, (materiasArray[i].correlativas));
                contadorOpcion++;
            }
            printf("-------------------------------\n");
        }

        // No tener en cuenta las materias que actualmente son correlativas
        if ((materiasLength - materia->correlativasLength) == 0)
        {
            printf("\n**NO SE ENCONTRARON MAS MATERIAS**\n");
        }
        else
        {
            for (int i = 0; i < materiasLength; i++)
            {
                printf("%d - %s\n", contadorOpcion, (materiasArray[i].nombre));
                contadorOpcion++;
            }
        }

        printf("\nSeleccione una opcion: ");
        scanf("%d", &opcion);
        limpiarBuffer();
    } while (opcion != 0);

    return;
}
