#include <stdio.h>
#include <stdlib.h>
#include "../headers/funciones.h"
#include "../headers/types.h"

void menuSeleccionMateriaParaEditar()
{
    char titulo[20] = "EDITAR MATERIAS";

    char tituloFuncion[20] = "EDITAR MATERIA";

    menuSeleccionMateria(titulo, tituloFuncion, menuEditarMateria);
}
