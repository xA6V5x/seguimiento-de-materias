#include <stdio.h>
#include <stdlib.h>
#include "../headers/funciones.h"
#include "../headers/types.h"

void menuEditarMaterias()
{
    materias_t materias = leerBinDeMaterias();

    int estadoId = 0;

    char titulo[20] = "EDITAR MATERIAS";

    int materiasLength = materias.length;

    materia_archivo_t *materiasArray = materias.array;

    menuSeleccionMateria(estadoId, titulo, &materiasLength, &materiasArray);
}
