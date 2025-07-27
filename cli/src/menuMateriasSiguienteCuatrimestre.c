#include <stdio.h>
#include <stdlib.h>
#include "../headers/config.h"
#include "../headers/funciones.h"
#include "../headers/types.h"

void menuMateriasSiguienteCuatrimestre()
{
    materias_t materias = leerBinDeMaterias();

    int estadoId = config_get_siguiente_cuatrimestre_id();

    int materiasLength = materias.length;

    materia_t *materiasArray = materias.array;

    char titulo[32] = "MATERIAS SIGUIENTE CUATRIMESTRE";

    menuSeleccionMateria(estadoId, titulo, &materiasLength, &materiasArray, filtrarMateriasPorEstado);
}
