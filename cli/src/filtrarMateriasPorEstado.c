#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/funciones.h"
#include "../headers/types.h"

void filtrarMateriasPorEstado(int estadoId, int *materiasLength, materia_t **materiasArray)
{
    int estadoBuscado = estadoId;
    int nuevoMateriasLength = 0;

    // Contar cuantas materias coinciden con el estado buscado
    for (int i = 0; i < *materiasLength; i++)
    {
        materia_t *materia = &(*materiasArray)[i];
        if (materia->estado == estadoBuscado)
        {
            nuevoMateriasLength++;
        }
    };

    // Al filtrar no se encontro ninguna materia con el estado buscado
    if (nuevoMateriasLength == 0)
    {
        *materiasLength = nuevoMateriasLength;
        return;
    }

    // Si el valor contado es igual al materiasLength terminar la funcion
    if (nuevoMateriasLength == *materiasLength)
        return; // Al filtrar quedaron las mismas materias que ya estaban

    // Reservar memoria para esa cantidad de materias
    materia_t *nuevoMateriasArray = miMalloc("las materias filtradas.", sizeof(materia_t) * nuevoMateriasLength);

    // Iterar sobre materiasArray e ir guardando las materias coincidentes en mi nuevo puntero
    int indexCount = 0; // posicion actual del nuevo array
    for (int i = 0; i < *materiasLength; i++)
    {
        materia_t *materia = &(*materiasArray)[i];

        materia_t *materiaCpy = &nuevoMateriasArray[indexCount];

        // Si no tiene el estado buscado pasar a la siguiente materia
        if (materia->estado != estadoBuscado)
        {
            continue;
        }

        // Copiar materia id
        materiaCpy->id = materia->id;

        // Copiar nombre
        materiaCpy->nombreLength = materia->nombreLength;
        materiaCpy->nombre = miMalloc("el nombre de las materias filtradas.", sizeof(char) * (materiaCpy->nombreLength + 1));
        strcpy(materiaCpy->nombre, materia->nombre);

        // Copiar correlativas
        materiaCpy->correlativasLength = materia->correlativasLength;
        if (materiaCpy->correlativasLength > 0)
        {
            materiaCpy->correlativas = miMalloc("las correlativas de las materias filtradas.", sizeof(int) * materiaCpy->correlativasLength);
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
        indexCount++; // Moverse de posicion solo si se guardo infomacion en la posicion actual
    };

    materia_t *ptrAntiguo = *materiasArray;
    // Reemplazar el antiguo puntero por el nuevo
    *materiasArray = nuevoMateriasArray;
    // Reemplazar el valor de materiasLength por el nuevo valor
    *materiasLength = nuevoMateriasLength;
    // Liberar el puntero anterior de materiasArray
    free(ptrAntiguo);
}