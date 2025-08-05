#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/config.h"
#include "../headers/funciones.h"
#include "../headers/types.h"

void eliminarMateriaDelArray(char *title, materia_archivo_t *materia, int *materiasLength, materia_archivo_t **materiasArray)
{
    int materiaBuscadaId = materia->id;

    int nuevoMateriasLength = *materiasLength - 1;
    materia_archivo_t *nuevoMateriasArray = miMalloc("materiasArray con nueva materia", sizeof(materia_archivo_t) * nuevoMateriasLength);

    // Copiar todas las materias actuales
    for (int i = 0; i < *materiasLength; i++)
    {
        materia_archivo_t *materia = &(*materiasArray)[i];
        int materiaId = materia->id;

        // No copiar la materia que queremos eliminar
        if (materiaId != materiaBuscadaId)
        {
            copiarMateria(&nuevoMateriasArray[i], &(*materiasArray)[i]);
            // Sacar de todas las correlativas la materia eliminada
            eliminarCorrelativa(materiaBuscadaId, materia);
        }
    }

    // Liberar el antiguo puntero de materiasArray
    free(*materiasArray);

    // Actualizar el puntero de materiasArray
    *materiasArray = nuevoMateriasArray;
    // Actualizar el largo del materias array
    *materiasLength = nuevoMateriasLength;

    materia_archivo_t *ptrMateriaEnElArray = &(*materiasArray)[*materiasLength - 1];

    confirmarEliminarMateria(materia, *materiasLength, *materiasArray);

    return;
}