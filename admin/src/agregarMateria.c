#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/config.h"
#include "../headers/funciones.h"
#include "../headers/types.h"

void agregarMateria(materia_archivo_t materia, int *materiasLength, materia_archivo_t **materiasArray)
{
    // Darle un id disponible a la materia
    int nuevoIdDisponible = leerBinDeContadorId();
    materia.id = nuevoIdDisponible;

    // Actualizar el archivo contador-id.dat
    actualizarBinDeContadorId(nuevoIdDisponible);

    int nuevoMateriasLength = *materiasLength + 1;
    materia_archivo_t *nuevoMateriasArray = miMalloc("materiasArray con nueva materia", sizeof(materia_archivo_t) * nuevoMateriasLength);

    // Copiar todas las materias actuales
    for (int i = 0; i < *materiasLength; i++)
    {
        copiarMateria(&nuevoMateriasArray[i], &(*materiasArray)[i]);
    }

    // Agregar al final del nuevoMateriasArray la nueva materia
    copiarMateria(&nuevoMateriasArray[nuevoMateriasLength - 1], &materia);

    // Liberar el antiguo puntero de materiasArray
    free(*materiasArray);

    // Actualizar el puntero de materiasArray
    *materiasArray = nuevoMateriasArray;
    // Actualizar el largo del materias array
    *materiasLength = nuevoMateriasLength;

    actualizarBinMaterias(*materiasLength, *materiasArray);

    system("cls");
    printf("La materia %s se creo exitosamente.", materia.nombre);
    esperarEnter();
}