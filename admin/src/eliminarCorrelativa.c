#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/config.h"
#include "../headers/funciones.h"
#include "../headers/types.h"

void eliminarCorrelativa(int correlativaId, materia_archivo_t *materia)
{
    // Comprobar que contiene la correlativaId buscada ---------------------------------------------
    int tieneLaCorrelativaBuscada = 0;

    for (int i = 0; i < materia->correlativasLength; i++)
    {
        if (materia->correlativas[i] == correlativaId)
        {
            tieneLaCorrelativaBuscada = 1; // Contiene la correlativa
            break;
        }
    }

    // si no tiene la correlativa no hacer ningun cambio
    if (!tieneLaCorrelativaBuscada)
        return;

    // ---------------------------------------------------------------------------------------------

    // Si contiene la correlativa, generar un nuevo array sin la correlativaId

    int nuevoCorrelativasLength = materia->correlativasLength - 1;

    if (nuevoCorrelativasLength == 0)
    {
        materia->correlativasLength = 0;
        return;
    }

    // Pedir espacio para el nuevo array de correlativas
    int *nuevasCorrelativas = miMalloc("array de correlativas", sizeof(int) * nuevoCorrelativasLength);

    int indexCount = 0; // posicion actual del materiasCursablesArray

    // Copiar las correlativas actuales
    for (int i = 0; i < materia->correlativasLength; i++)
    {
        // No copiar la correlativa que queremos eliminar
        if (materia->correlativas[i] != correlativaId)
        {
            nuevasCorrelativas[indexCount] = materia->correlativas[i];
            indexCount++;
        }
    }

    // Liberar el antiguo puntero a correlativas
    free(materia->correlativas);

    // Actualizar el largo del array de correlativas
    materia->correlativasLength = nuevoCorrelativasLength;
    // Actualizar el puntero al array de correlativas
    materia->correlativas = nuevasCorrelativas;

    return;
}