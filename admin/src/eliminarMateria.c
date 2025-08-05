#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/config.h"
#include "../headers/funciones.h"
#include "../headers/types.h"

void eliminarMateria(char *t, materia_archivo_t *materia, int *materiasLength, materia_archivo_t **materiasArray)
{
    // Guardar nombre de la materia para luego poder imprimirlo en pantalla ------------------------
    char *materiaNombre = miMalloc("guardar nombre de la materia", sizeof(char) * materia->nombreLength);
    strcpy(materiaNombre, materia->nombre);
    // ---------------------------------------------------------------------------------------------

    // materiaId de la materia a eliminar
    int materiaBuscadaId = materia->id;

    int nuevoMateriasLength = *materiasLength - 1;

    materia_archivo_t *nuevoMateriasArray = NULL;

    if (nuevoMateriasLength > 0)
    {
        nuevoMateriasArray = miMalloc("materiasArray con materia eliminada", sizeof(materia_archivo_t) * nuevoMateriasLength);
    }

    // Copiar todas las materias actuales
    int indexCount = 0; // posicion actual del nuevoMateriasArray
    for (int i = 0; i < *materiasLength; i++)
    {
        materia_archivo_t *materiaSrc = &(*materiasArray)[i];
        int materiaId = materiaSrc->id;

        materia_archivo_t *materiaCpy = &nuevoMateriasArray[indexCount];

        // No copiar la materia que queremos eliminar
        if (materiaId != materiaBuscadaId)
        {
            // Copiar la materiaSrc con todas sus correlativas
            copiarMateria(materiaCpy, materiaSrc);
            // Si tiene de correlativa la materia a eliminar, quitar del array de correlativas
            eliminarCorrelativa(materiaBuscadaId, materiaCpy);

            indexCount++;
        }
    }

    // Liberar el antiguo puntero de materiasArray
    free(*materiasArray);

    // Actualizar el puntero de materiasArray
    *materiasArray = nuevoMateriasArray;
    // Actualizar el largo del materias array
    *materiasLength = nuevoMateriasLength;

    confirmarEliminarMateria(materiaNombre, *materiasLength, *materiasArray);

    return;
}