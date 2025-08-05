#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/config.h"
#include "../headers/funciones.h"
#include "../headers/types.h"

void menuSeleccionMateriaParaEliminar()
{
    char titulo[20] = "ELIMINAR MATERIAS";

    menuSeleccionMateria(titulo, NULL, eliminarMateria);
}
