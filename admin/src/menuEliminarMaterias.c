#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/config.h"
#include "../headers/funciones.h"
#include "../headers/types.h"

void menuEliminarMaterias()
{
    materias_t materias = leerBinDeMaterias();

    int estadoId = 0;

    char titulo[18] = "ELIMINAR MATERIAS";

    int materiasLength = materias.length;

    materia_archivo_t *materiasArray = materias.array;

    menuSeleccionMateria(estadoId, titulo, &materiasLength, &materiasArray);
}
