#include <stdio.h>
#include <stdlib.h>
#include "../headers/config.h"
#include "../headers/funciones.h"
#include "../headers/types.h"

void menuMateriasAprobadas()
{
    materias_t materias = leerBinDeMaterias();

    int estadoId = config_get_aprobada_id();

    int materiasLength = materias.length;

    materia_t *materiasArray = materias.array;

    char titulo[19] = "MATERIAS APROBADAS";

    menuSeleccionMateria(estadoId, titulo, &materiasLength, &materiasArray, filtrarMateriasPorEstado);
}
