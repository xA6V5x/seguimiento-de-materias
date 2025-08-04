#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/config.h"
#include "../headers/funciones.h"
#include "../headers/types.h"

void printSeleccionarCorrelativas(int correlativasLength, int *correlativasArray, int noCorrelativasLength, materia_archivo_t *noCorrelativasArray, int materiasLength, materia_archivo_t *materiasArray)
{
    int contadorOpcion = 1;

    // Printear materias que son actualmente correlativas
    if (correlativasLength > 0)
    {
        for (int i = 0; i < correlativasLength; i++)
        {
            int correlativaId = correlativasArray[i];

            materia_archivo_t *materiaCorrelativa = buscarMateriaPorId(NULL, correlativaId, materiasLength, materiasArray);

            printf("%d - %s [ Quitar ] X\n", contadorOpcion, (materiaCorrelativa->nombre));
            contadorOpcion++;
        }
        printf("-------------------------------\n");
    }

    // No se tiene en cuenta las materias que actualmente son correlativas y la materia principal
    if (noCorrelativasLength == 0)
    {
        printf("\n**NO SE ENCONTRARON MAS MATERIAS PARA AGREGAR**\n");
    }

    // Printear materias que actualmente no son correlativas
    for (int i = 0; i < noCorrelativasLength; i++)
    {
        int materiaPrintId = noCorrelativasArray[i].id;

        printf("%d - %s [ Agregar ]\n", contadorOpcion, noCorrelativasArray[i].nombre);
        contadorOpcion++;
    }
};