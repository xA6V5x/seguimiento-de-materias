#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/config.h"
#include "../headers/funciones.h"
#include "../headers/types.h"

void agregarCorrelativa(int correlativaId, materia_archivo_t *materia)
{
    int nuevoCorrelativasLength = materia->correlativasLength + 1;

    // Pedir espacio para el nuevo array de correlativas
    int *nuevasCorrelativas = miMalloc("array de correlativas", sizeof(int) * nuevoCorrelativasLength);

    // Copiar las correlativas actuales
    for (int i = 0; i < materia->correlativasLength; i++)
    {
        nuevasCorrelativas[i] = materia->correlativas[i];
    }

    // Agregar al final la nueva correlativa
    nuevasCorrelativas[nuevoCorrelativasLength - 1] = correlativaId;

    // Liberar el antiguo puntero a correlativas
    free(materia->correlativas);

    // Actualizar el largo del array de correlativas
    materia->correlativasLength = nuevoCorrelativasLength;
    // Actualizar el puntero al array de correlativas
    materia->correlativas = nuevasCorrelativas;
}