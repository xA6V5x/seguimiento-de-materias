#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/config.h"
#include "../headers/funciones.h"
#include "../headers/types.h"

// Se consideran "cursables" aquellas materias No Cursadas cuyas correlatividades
// ya están finalizadas o aprobadas, es decir, todas sus correlativas tienen estado 4 (Final Pendiente) o 5 (Aprobada).
void agregarMateria()
{
    materias_t materias = leerBinDeMaterias();

    int estadoId = 0;

    int materiasLength = materias.length;

    materia_archivo_t *materiasArray = materias.array;

    materia_archivo_t materiaNueva = {.id = -1, .nombreLength = 2, .nombre = "--", .correlativasLength = 0, .correlativas = NULL};

    char titulo[19] = "AGREGAR MATERIAS";

    menuMateriaInfo(materiaNueva, materiasLength, materiasArray);
}
