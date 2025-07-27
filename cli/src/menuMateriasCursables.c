#include <stdio.h>
#include <stdlib.h>
#include "../headers/config.h"
#include "../headers/funciones.h"
#include "../headers/types.h"

void menuMateriasCursables()
{
    materias_t materias = leerBinDeMaterias();

    int estadoId = config_get_no_cursada_id();

    int materiasLength = materias.length;

    materia_t *materiasArray = materias.array;

    char titulo[19] = "MATERIAS CURSABLES";

    menuSeleccionMateria(estadoId, titulo, &materiasLength, &materiasArray, filtrarMateriasPorEstado);
}
