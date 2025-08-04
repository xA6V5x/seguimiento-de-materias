#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/config.h"
#include "../headers/funciones.h"
#include "../headers/types.h"

void menuEditarMateria(char *title, materia_archivo_t *materia, int materiasLength, materia_archivo_t *materiasArray)
{
    int opcion;

    do
    {
        system("cls");
        printf("== %s ==\n", title);
        materia->id != -1 && printf("id: %d\n", materia->id);
        printf("1 - nombre: %s\n", materia->nombre);
        printf("2 - correlativas: ");
        printMateriasCorrelativas((*materia), materiasLength, materiasArray);
        printf("-------------------------------\n");
        printf("3 - Confirmar\n");
        printf("0 - Volver\n");
        printf("\nSeleccione una opcion: ");

        scanf("%d", &opcion);
        limpiarBuffer();

        switch (opcion)
        {
        case 1:
            editarMateriaNombre(materia);
            break;
        case 2:
            editarMateriaCorrelativas(materia);
            break;
        case 3:
            actualizarBinMaterias(materiasLength, materiasArray);
            system("cls");
            printf("La materia %s se actualzo exitosamente.", materia->nombre);
            esperarEnter();
            break;
        case 0:
            break;
        default:
            errorOpcionNoValida();
            break;
        }
    } while (opcion != 0 && opcion != 3);
}
