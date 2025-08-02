#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/config.h"
#include "../headers/funciones.h"
#include "../headers/types.h"

void agregarMateria()
{
    materias_t materias = leerBinDeMaterias();

    int estadoId = 0;

    int materiasLength = materias.length;

    materia_archivo_t *materiasArray = materias.array;

    materia_archivo_t materia = {.id = -1, .nombreLength = 2, .correlativasLength = 0, .correlativas = NULL};

    materia.nombre = miMalloc("inicializar nombre de la materia", sizeof(char) * 3);

    strcpy(materia.nombre, "--");

    char titulo[19] = "CREAR MATERIA";

    // menuMateriaInfo(materiaNueva, materiasLength, materiasArray);

    int opcion;

    do
    {
        // leerBinEstadoDeMateria(&materia); // Lee el estado y lo guarda en materia.estado
        system("cls");
        printf("== AGREGAR MATERIA ==\n");
        printf("1 - nombre: %s\n", materia.nombre);
        printf("2 - correlativas: ");
        printMateriasCorrelativas(materia, materiasLength, materiasArray);
        printf("-------------------------------\n");
        printf("3 - Confirmar\n");
        printf("0 - Volver\n");
        printf("\nSeleccione una opcion: ");

        scanf("%d", &opcion);
        limpiarBuffer();

        switch (opcion)
        {
        case 1:
            editarMateriaNombre(&materia);
            break;
        case 2:
            editarMateriaCorrelativas(&materia);
            break;
        case 3:
            actualizarBinMaterias(&materia);
            break;
        case 0:
            break;
        default:
            errorOpcionNoValida();
            break;
        }
    } while (opcion != 0);
}
