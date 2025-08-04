#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/config.h"
#include "../headers/funciones.h"
#include "../headers/types.h"

materia_archivo_t *buscarMateriaPorId(int *materiaBuscadaIndex, int materiaId, int materiasLength, materia_archivo_t *materiasArray)
{
    materia_archivo_t *materia;

    if (materiasLength <= 0)
    {
        printf("La materia buscada con id: %d no existe", materiaId);
        esperarEnter();
        exit(1);
    }

    for (int i = 0; i < materiasLength; i++)
    {
        if (materiasArray[i].id == materiaId)
        {
            materia = &materiasArray[i];
            if (materiaBuscadaIndex != NULL)
            {
                *materiaBuscadaIndex = i;
            }
            break;
        }
    }

    return materia;
};