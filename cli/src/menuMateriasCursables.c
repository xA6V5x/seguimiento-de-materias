#include <stdio.h>
#include <stdlib.h>
#include "../headers/funciones.h"
#include "../headers/types.h"

void menuMateriasCursables()
{
    materias_t materias = leerBinDeMaterias();

    int materiasLength = materias.length;

    materia_t *materiasArray = materias.array;

    char titulo[19] = "MATERIAS CURSABLES";

    menuSeleccionMateria(titulo, materiasLength, materiasArray);
}
