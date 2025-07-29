#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/config.h"
#include "../headers/funciones.h"
#include "../headers/types.h"

// Se consideran "cursables" aquellas materias No Cursadas cuyas correlatividades
// ya están finalizadas o aprobadas, es decir, todas sus correlativas tienen estado 4 (Final Pendiente) o 5 (Aprobada).
void menuMateriasCursables()
{
    materias_t materias = leerBinDeMaterias();

    int estadoId = config_get_no_cursada_id();

    int materiasLength = materias.length;

    materia_t *materiasArray = materias.array;

    char titulo[19] = "MATERIAS CURSABLES";

    // Refrescar sus estados
    refrescarEstadosDeMaterias(materiasLength, materiasArray);

    // Inicializar un contador (para saber cuantas materias son cursables)
    int materiasCursablesLength = 0;

    // Iterar en el array de materias para contar cuantas son cursables
    for (int i = 0; i < materiasLength; i++)
    {
        materia_t *materia = &materiasArray[i];

        // En caso de que la materia no tenga correlativas ya es cursable
        if (materia->correlativasLength == 0)
        {
            materiasCursablesLength++;
            continue;
        };

        // Iterar en sus correlativas
        for (int j = 0; j < materia->correlativasLength; j++)
        {
            int materiaIdBuscada = materia->correlativas[j];
            int estadoIdDeLaMateria = 0;

            // Buscar en que estado se encuentra la correlativa
            for (int k = 0; k < materiasLength; k++)
            {
                if (materiaIdBuscada != materiasArray[k].id)
                {
                    continue;
                }
                estadoIdDeLaMateria = materiasArray[k].estado;
                break;
            }

            // Si no es 4 o 5 pasar a la siguiente materia
            // La materia actual no es cursable porque al menos una de sus correlativas no tiene estado 4 o 5
            if (estadoIdDeLaMateria != 4 && estadoIdDeLaMateria != 5)
            {
                break;
            }

            // Sii todas las correlativas estan aprobadas sumar contador++
            if (j == (materia->correlativasLength - 1))
            {
                materiasCursablesLength++;
            }

            // Si el estado es 4 o 5 checkear la siguiente correlativa
            continue;
        }
    }

    // ----------------------------------------------------------------------
    // Cuando se termine de iterar reservar memoria para materiasCursablesArray [sizeof(materia_t)*materiasCursablesLength]
    materia_t *materiasCursablesArray = miMalloc("materias cursables", sizeof(materia_t) * materiasCursablesLength);
    // ----------------------------------------------------------------------

    int indexCount = 0; // posicion actual del materiasCursablesArray

    for (int i = 0; i < materiasLength; i++)
    {
        materia_t *materia = &materiasArray[i];

        materia_t *materiaCpy = &materiasCursablesArray[indexCount];

        // En caso de que la materia no tenga correlativas ya es cursable
        if (materia->correlativasLength == 0)
        {
            materiasCursablesLength++;
            continue;
        };

        // Iterar en sus correlativas
        for (int j = 0; j < materia->correlativasLength; j++)
        {
            int materiaIdBuscada = materia->correlativas[j];
            int estadoIdDeLaMateria = 0;

            // Buscar en que estado se encuentra la correlativa
            for (int k = 0; k < materiasLength; k++)
            {
                if (materiaIdBuscada != materiasArray[k].id)
                {
                    continue;
                }
                estadoIdDeLaMateria = materiasArray[k].estado;
                break;
            }

            // Si no es 4 o 5 pasar a la siguiente materia
            // La materia actual no es cursable porque al menos una de sus correlativas no tiene estado 4 o 5
            if (estadoIdDeLaMateria != 4 && estadoIdDeLaMateria != 5)
            {
                break;
            }

            // Sii todas las correlativas estan aprobadas copiar materia al materiasCursablesArray
            if (j == (materia->correlativasLength - 1))
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

                // Copiar estado
                materiaCpy->estado = materia->estado;
                indexCount++;
            }

            // Si el estado es 4 o 5 checkear la siguiente correlativa
            continue;
        }
    }

    // Filtrar para que solo queden las materias que No hayan sido Cursadas (materia.estado = 1)
    filtrarMateriasPorEstado(estadoId, &materiasCursablesLength, &materiasCursablesArray);

    menuSeleccionMateria(estadoId, titulo, &materiasCursablesLength, &materiasCursablesArray, NULL);
}
