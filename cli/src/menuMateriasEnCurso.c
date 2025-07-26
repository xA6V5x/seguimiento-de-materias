#include <stdio.h>
#include <stdlib.h>
#include "../headers/funciones.h"
#include "../headers/types.h"

void menuMateriasEnCurso()
{
    materias_t materias = leerBinDeMaterias();

    int materiasLength = materias.length;

    materia_t *materiasArray = materias.array;

    char titulo[18] = "MATERIAS EN CURSO";

    menuSeleccionMateria(titulo, materiasLength, materiasArray);
}
