#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/funciones.h"

int compararMateriasPorId(const void *a, const void *b)
{
    materia_archivo_t *materiaA = (materia_archivo_t *)a;
    materia_archivo_t *materiaB = (materia_archivo_t *)b;
    return materiaA->id - materiaB->id;
}

// Ordenar las materias por id
void sortMateriasPorId(int materiasLength, materia_archivo_t *materiasArray)
{
    qsort(materiasArray, materiasLength, sizeof(materia_archivo_t), compararMateriasPorId);
}
