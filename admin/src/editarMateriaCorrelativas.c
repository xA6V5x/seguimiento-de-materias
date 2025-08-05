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

    int *correlativasLength = &materia->correlativasLength;
    int *correlativasArray = materia->correlativas;

    do
    {
        int noCorrelativasLength = *materiasLength;
        materia_archivo_t *noCorrelativasArray = NULL;
        if (materiasLength > 0)
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
            filtrarMateriaDelArray(correlativasArray[i], &noCorrelativasLength, &noCorrelativasArray);
        }

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
            int correlativaSeleccionadaId = correlativasArray[opcion - 1];
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
