#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/config.h"
#include "../headers/funciones.h"
#include "../headers/types.h"

// Se consideran "cursables" aquellas materias No Cursadas cuyas correlatividades
// ya están finalizadas o aprobadas, es decir, todas sus correlativas tienen estado 4 (Final Pendiente) o 5 (Aprobada).
void menuMateriasCursables()
{
    materias_t materias = leerBinDeMaterias();

    int estadoId = config_get_no_cursada_id();

    int materiasLength = materias.length;

    materia_t *materiasArray = materias.array;

    char titulo[19] = "MATERIAS CURSABLES";

    menuSeleccionMateria(estadoId, titulo, &materiasLength, &materiasArray, filtrarMateriasCursables);
}
