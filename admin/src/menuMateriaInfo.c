#include <stdio.h>
#include <stdlib.h>
#include "../headers/funciones.h"
#include "../headers/types.h"

void menuMateriaInfo(materia_archivo_t materia, int materiasLength, materia_archivo_t *materiasArray)
{
    int opcion;

    do
    {
        // leerBinEstadoDeMateria(&materia); // Lee el estado y lo guarda en materia.estado
        system("cls");
        printf("== MATERIA %s ==\n", materia.nombre);
        (materia.id != -1) && ("id: %d\n", materia.id);
        printf("nombre: %s\n", materia.nombre);
        printf("correlativas: ");
        printMateriasCorrelativas(materia, materiasLength, materiasArray);
        printf("-------------------------------\n");
        // printf("1 - Editar estado\n");
        printf("0 - Volver\n");
        printf("\nSeleccione una opcion: ");

        scanf("%d", &opcion);
        limpiarBuffer();

        switch (opcion)
        {
        // case 1:
        //     menuEditarEstadoDeMateria(&materia);
        //     break;
        case 0:
            break;
        default:
            errorOpcionNoValida();
            break;
        }
    } while (opcion != 0);
}