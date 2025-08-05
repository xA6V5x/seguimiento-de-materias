#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/config.h"
#include "../headers/funciones.h"
#include "../headers/types.h"

void copiarMateria(materia_archivo_t *materiaCpy, materia_archivo_t *materia)
{
    // Copiar materia id
    materiaCpy->id = materia->id;

    // Copiar nombre
    materiaCpy->nombreLength = materia->nombreLength;
    materiaCpy->nombre = miMalloc("el nombre de las materias cursables.", sizeof(char) * (materiaCpy->nombreLength + 1));
    strcpy(materiaCpy->nombre, materia->nombre);

    // Copiar correlativas
    materiaCpy->correlativasLength = materia->correlativasLength;
    if (materiaCpy->correlativasLength > 0)
    {
        materiaCpy->correlativas = miMalloc("las correlativas de las materias cursables.", sizeof(int) * materiaCpy->correlativasLength);
        for (int j = 0; j < materiaCpy->correlativasLength; j++)
        {
            materiaCpy->correlativas[j] = materia->correlativas[j];
        };
    }
    else
    {
        materiaCpy->correlativas = NULL;
    }
};
