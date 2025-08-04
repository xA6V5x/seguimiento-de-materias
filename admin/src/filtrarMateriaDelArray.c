#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/config.h"
#include "../headers/funciones.h"
#include "../headers/types.h"

void filtrarMateriaDelArray(int materiaBuscadaId, int *materiasLength, materia_archivo_t **materiasArray)
{
    int materiaBuscadaIndex = -1;

    buscarMateriaPorId(&materiaBuscadaIndex, materiaBuscadaId, *materiasLength, *materiasArray);

    if (materiaBuscadaIndex < 0)
    {
        return; // La materia que se busca filtrar no se encuentra en materiasArray
    }

    int materiasFiltradasLength = *materiasLength - 1;

    // Si solo habia una materia, vaciar el array
    if (materiasFiltradasLength == 0)
    {
        *materiasLength = 0;
        return;
    }

    // ----------------------------------------------------------------------

    // Reservar memoria para materiasCursablesArray [sizeof(materia_t)*materiasCursablesLength]
    materia_archivo_t *materiasFiltradasArray = miMalloc("materia filtrada", sizeof(materia_archivo_t) * materiasFiltradasLength);

    // ----------------------------------------------------------------------

    int indexCount = 0; // posicion actual del materiasFiltradasArray

    for (int i = 0; i < *materiasLength; i++)
    {
        materia_archivo_t *materia = &(*materiasArray)[i];

        materia_archivo_t *materiaCpy = &materiasFiltradasArray[indexCount];

        // La materia que buscamos sacar del array no la copiamos
        if (materia->id != materiaBuscadaId)
        {
            copiarMateria(materiaCpy, materia);
            indexCount++;
        }
    }

    // Liberar el puntero anterior de materiasArray
    free(*materiasArray);

    // Reemplazar el antiguo puntero por el nuevo
    *materiasArray = materiasFiltradasArray;
    // Reemplazar el valor de materiasLength por el nuevo valor
    *materiasLength = materiasFiltradasLength;
}
