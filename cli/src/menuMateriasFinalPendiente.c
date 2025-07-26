#include <stdio.h>
#include <stdlib.h>
#include "../headers/funciones.h"
#include "../headers/types.h"

void menuMateriasFinalPendiente()
{
    materias_t materias = leerBinDeMaterias();

    int materiasLength = materias.length;

    materia_t *materiasArray = materias.array;

    char titulo[29] = "MATERIAS CON FINAL PENDIENTE";

    menuSeleccionMateria(titulo, materiasLength, materiasArray);
}
