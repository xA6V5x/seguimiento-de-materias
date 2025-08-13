#include <stdio.h>
#include <stdlib.h>
#include "../headers/funciones.h"
#include "../headers/types.h"

void printMateriasCorrelativas(materia_t materia)
{
    materias_t materias = leerBinDeMaterias();

    int materiasLength = materias.length;

    materia_t *materiasArray = materias.array;

    int correlativasLength = materia.correlativasLength;

    if (correlativasLength > 0)
    {
        // Iterar en las correlativas de la materia
        for (int i = 0; i < correlativasLength; i++)
        {
            int materiaIdBuscada = materia.correlativas[i];
            // Buscar la materia por su ID en el array de materias
            for (int j = 0; j < materiasLength; j++)
            {
                if (materiasArray[j].id == materiaIdBuscada)
                {
                    i != correlativasLength - 1 ? printf("%s; ", materiasArray[j].nombre) : printf("%s", materiasArray[j].nombre); // Evitar el punto y coma al final
                    break;
                }
            }
        }
    }
    else
    {
        printf("--");
    }
    printf("\n");
}