#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/funciones.h"
#include "../headers/types.h"

int comprobarCorrelativasAprobadas(materia_t *materia)
{

    materias_t materias = leerBinDeMaterias();

    int materiasLength = materias.length;

    materia_t *materiasArray = materias.array;

    // Refrescar sus estados
    refrescarEstadosDeMaterias(materiasLength, materiasArray);

    // Iterar en sus correlativas
    for (int j = 0; j < materia->correlativasLength; j++)
    {
        int materiaIdBuscada = materia->correlativas[j];
        char nombreCorrelativa[50];
        int estadoIdDeLaMateria = 0;

        // Buscar en que estado se encuentra la correlativa
        for (int k = 0; k < materiasLength; k++)
        {
            if (materiaIdBuscada != materiasArray[k].id)
            {
                continue;
            }
            estadoIdDeLaMateria = materiasArray[k].estado;
            strcpy(nombreCorrelativa, materiasArray[k].nombre);
            break;
        }

        // Si la correlativa no fue aprobada entonces la materia no puede ser aprobada
        if (estadoIdDeLaMateria != 5)
        {
            system("cls");
            printf("Error: Esta materia requiere que la correlativa %s haya sido aprobada.\n", nombreCorrelativa);
            esperarEnter();

            return 1;
        }
    }

    return 0;
}