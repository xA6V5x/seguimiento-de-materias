#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/config.h"
#include "../headers/funciones.h"
#include "../headers/types.h"

void editarMateriaNombre(materia_archivo_t *materia)
{
    system("cls");

    char *viejoNombre = materia->nombre;

    char buffer[100];
    printf("Introduce el Nombre de la Materia:\n");
    fgets(buffer, sizeof(buffer), stdin);

    // Eliminar el salto de línea final si esta presente
    buffer[strcspn(buffer, "\n")] = 0;

    // Obtener longitud de la string
    int strLength = strlen(buffer);

    // Si el nombre nuevo esta vacio seguir usando el anterior
    if (strLength == 0)
    {
        return;
    }

    materia->nombreLength = strLength;

    materia->nombre = miMalloc("nombre de la materia", sizeof(char) * (strLength + 1));

    strcpy(materia->nombre, buffer);

    free(viejoNombre);

    return;
}
