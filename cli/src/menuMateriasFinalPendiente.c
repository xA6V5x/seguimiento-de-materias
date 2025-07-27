#include <stdio.h>
#include <stdlib.h>
#include "../headers/config.h"
#include "../headers/funciones.h"
#include "../headers/types.h"

void menuMateriasFinalPendiente()
{
    materias_t materias = leerBinDeMaterias();

    int estadoId = config_get_final_pendiente_id();

    int materiasLength = materias.length;

    materia_t *materiasArray = materias.array;

    char titulo[29] = "MATERIAS CON FINAL PENDIENTE";

    menuSeleccionMateria(estadoId, titulo, &materiasLength, &materiasArray, filtrarMateriasPorEstado);
}
