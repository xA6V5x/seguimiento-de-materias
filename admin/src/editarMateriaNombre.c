#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../headers/config.h"
#include "../headers/funciones.h"
#include "../headers/types.h"

void stringToLower(char *dest, const char *src)
{
    int i = 0;
    while (src[i])
    {
        dest[i] = tolower((unsigned char)src[i]);
        i++;
    }
    dest[i] = '\0';
}

void editarMateriaNombre(materia_archivo_t *materia, int materiasLength, materia_archivo_t *materiasArray)
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

    char bufferLower[strLength];

    // normailizar el nombre de la materia para que este en minusculas
    stringToLower(bufferLower, buffer);

    // Comprobar que no se repita un nombre de materia ---------------------------------------------
    int elNombreYaExiste = 0;

    for (int i = 0; i < materiasLength; i++)
    {
        if (strcmp(bufferLower, materiasArray[i].nombre) == 0)
        {
            elNombreYaExiste = 1;
            break;
        }
    }

    if (elNombreYaExiste)
    {
        system("cls");
        printf("Error: El nombre de la materia ingresado ya existe, por favor elige otro.");
        esperarEnter();
        return;
    }
    // ---------------------------------------------------------------------------------------------

    materia->nombreLength = strLength;

    materia->nombre = miMalloc("nombre de la materia", sizeof(char) * (strLength + 1));

    strcpy(materia->nombre, bufferLower);

    free(viejoNombre);

    return;
}
