#include <stdio.h>
#include <stdlib.h>
#include "../headers/funciones.h"
#include "../headers/types.h"

void menuListadoDeMaterias()
{
    materias_t materias = leerBinDeMaterias();

    int estadoId = 0;

    char titulo[20] = "LISTADO DE MATERIAS";

    int materiasLength = materias.length;

    materia_t *materiasArray = materias.array;

    menuSeleccionMateria(estadoId, titulo, &materiasLength, &materiasArray, NULL);
}
