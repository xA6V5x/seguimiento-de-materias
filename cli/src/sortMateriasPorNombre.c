#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/funciones.h"

int compareMateriasPorNombre(const void *a, const void *b)
{
    const materia_t *materiaA = (const materia_t *)a;
    const materia_t *materiaB = (const materia_t *)b;
    return strcmp(materiaA->nombre, materiaB->nombre);
}

// Ordenar las materias por nombre
void sortMateriasPorNombre(materia_t *materiasArray, int materiasLength)
{
    qsort(materiasArray, materiasLength, sizeof(materia_t), compareMateriasPorNombre);
}
