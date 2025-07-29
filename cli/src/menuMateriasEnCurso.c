#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/config.h"
#include "../headers/funciones.h"
#include "../headers/types.h"

void menuMateriasEnCurso()
{
    materias_t materias = leerBinDeMaterias();

    int estadoId = config_get_en_curso_id();

    char titulo[18] = "MATERIAS EN CURSO";

    int materiasLength = materias.length;

    materia_t *materiasArray = materias.array;

    menuSeleccionMateria(estadoId, titulo, &materiasLength, &materiasArray, filtrarMateriasPorEstado);
}
