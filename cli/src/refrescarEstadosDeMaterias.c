#include <stdio.h>
#include <stdlib.h>
#include "../headers/funciones.h"
#include "../headers/types.h"

void refrescarEstadosDeMaterias(int materiasLength, materia_t *materiasArray)
{
    for (int i = 0; i < materiasLength; i++)
    {
        leerBinEstadoDeMateria(&materiasArray[i]);
    }
}