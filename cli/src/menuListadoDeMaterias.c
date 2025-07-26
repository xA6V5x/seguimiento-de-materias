#include <stdio.h>
#include <stdlib.h>
#include "../headers/funciones.h"
#include "../headers/types.h"

void menuListadoDeMaterias()
{
    materias_t materias = leerBinDeMaterias();

    int materiasLength = materias.length;

    materia_t *materiasArray = materias.array;

    char titulo[20] = "LISTADO DE MATERIAS";

    menuSeleccionMateria(titulo, materiasLength, materiasArray);
}
