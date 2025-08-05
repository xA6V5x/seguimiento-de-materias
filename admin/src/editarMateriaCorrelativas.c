#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/config.h"
#include "../headers/funciones.h"
#include "../headers/types.h"

void editarMateriaCorrelativas(materia_archivo_t *materia)
{
    char buffer[100];
    int opcion;
    int esValido = 0;

    materias_t *materias = leerBinDeMaterias();

    int *materiasLength = &materias->length;
    materia_archivo_t *materiasArray = materias->array;

    // Sacar del materias array la materia principal, siendo que no puede ser correlativa de si misma
    filtrarMateriaDelArray(materia->id, materiasLength, &materiasArray);

    do
    {
        // CORRELATIVAS ----------------------------------------------------------------------------
        int *correlativasLength = &materia->correlativasLength;
        int *correlativasArrayId = materia->correlativas;
        materia_archivo_t *correlativasArray = NULL;

        if (*correlativasLength > 0)
        {
            correlativasArray = miMalloc("array de materias correlativas", sizeof(materia_archivo_t) * (*correlativasLength));
        }

        // Buscar y guardar la informacion de la materia correlativa
        for (int i = 0; i < *correlativasLength; i++)
        {
            correlativasArray = miMalloc("array de materias correlativas", sizeof(materia_archivo_t) * (*correlativasLength));
            materia_archivo_t *materiaBuscada = buscarMateriaPorId(NULL, correlativasArrayId[i], *materiasLength, materiasArray);
            copiarMateria(&correlativasArray[i], materiaBuscada);
        }

        // Ordenas las materias correlativas
        // sortMateriasPorNombre(*correlativasLength, correlativasArray);

        // -----------------------------------------------------------------------------------------

        // NO CORRELATIVAS -------------------------------------------------------------------------
        int noCorrelativasLength = *materiasLength;
        materia_archivo_t *noCorrelativasArray = NULL;
        if (*materiasLength > 0)
        {
            noCorrelativasArray = miMalloc("array de materias no correlativas", sizeof(materia_archivo_t) * (*materiasLength));
        }

        // Copiar todas las materias
        for (int i = 0; i < *materiasLength; i++)
        {
            copiarMateria(&noCorrelativasArray[i], &materiasArray[i]);
        }

        // Sacar del materiasNoCorrelativasArray las materias que son correlativas
        for (int i = 0; i < *correlativasLength; i++)
        {
            filtrarMateriaDelArray(correlativasArray[i].id, &noCorrelativasLength, &noCorrelativasArray);
        }

        // Ordenas las materias no correlativas
        sortMateriasPorNombre(noCorrelativasLength, noCorrelativasArray);

        // -----------------------------------------------------------------------------------------

        system("cls");

        printf("== SELECCIONAR CORRELATIVAS ==\n");
        printf("0 - Cancelar\n");
        printf("-------------------------------\n");

        printSeleccionarCorrelativas(*correlativasLength, correlativasArray, noCorrelativasLength, noCorrelativasArray, *materiasLength, materiasArray);

        printf("\nSeleccione una opcion: ");

        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = 0;
        esValido = esOpcionNumericaValida(buffer, 0, *materiasLength, &opcion);

        if (!esValido)
        {
            errorOpcionNoValida();
        }

        // Debo guardar el length inicial debido a que eliminarCorrelativa y agregarCorrelativa modifican el valor de correlativasLength
        int correlativasLengthInicial = *correlativasLength;

        // Las opciones desde 1 hasta correlativasLength son correlativas que deben ser removidas
        if (opcion > 0 && opcion <= correlativasLengthInicial)
        {
            int index = opcion - 1;
            int correlativaSeleccionadaId = correlativasArray[opcion - 1].id;
            eliminarCorrelativa(correlativaSeleccionadaId, materia);
        }

        // Las opciones desde correlativasLength hasta materiasLength son correlativas que se deben agregar
        if (opcion > correlativasLengthInicial && opcion < (*materiasLength + 1))
        {
            int index = opcion - correlativasLengthInicial - 1;
            int correlativaSeleccionadaId = noCorrelativasArray[index].id;
            agregarCorrelativa(correlativaSeleccionadaId, materia);
        }

    } while (!esValido);

    return;
}
