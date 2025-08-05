#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/config.h"
#include "../headers/funciones.h"
#include "../headers/types.h"

void menuAgregarMateria()
{
    char titulo[14] = "CREAR MATERIA";

    materias_t *materias = leerBinDeMaterias();

    int *materiasLength = &materias->length;

    materia_archivo_t *materiasArray = materias->array;

    materia_archivo_t materia = {.id = -1, .nombreLength = 2, .correlativasLength = 0, .correlativas = NULL};

    materia.nombre = miMalloc("inicializar nombre de la materia", sizeof(char) * 3);

    strcpy(materia.nombre, "--");

    materia_archivo_t *ptrMateriaEnElArray = agregarMateriaAlArray(materia, materiasLength, &materiasArray);

    menuEditarMateria(titulo, ptrMateriaEnElArray, materiasLength, &materiasArray);
}
