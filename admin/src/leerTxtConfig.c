#include <stdio.h>
#include <stdlib.h>
#include "../headers/funciones.h"
#include "../headers/types.h"

opciones_acciones_t leerTxtConfig(const ptr_funcion_void_t *funcionesArray)
{
    int opcionesLength;

    opcion_accion_t *opcionesArray;

    FILE *fp = fopen("./config/menu-principal.txt", "r");

    if (!fp)
    {
        printf("Error al abrir el archivo de configuracion.");
        esperarEnter();
        exit(1);
    };

    if (fscanf(fp, "%d,\n", &opcionesLength) != 1)
    {
        printf("Error al leer la cantidad de opciones.");
        esperarEnter();
        exit(1);
    };

    opcionesArray = miMalloc("opciones del menu principal", sizeof(opcion_accion_t) * opcionesLength);

    for (int i = 0; i < opcionesLength; i++)
    {
        int funcionIndex;

        int textLength;

        if (fscanf(fp, "%d, %d, ", &funcionIndex, &textLength) != 2)
        {
            printf("Error al leer funcionId y textLength.");
            esperarEnter();
            exit(1);
        };

        if (funcionesArray[funcionIndex] == NULL)
        {
            printf("Error en el archivo config, la funcionId %d no existe.", funcionIndex);
            esperarEnter();
            exit(1);
        }

        opcionesArray[i].text = miMalloc("opciones del menu principal", sizeof(char) * textLength + 1);

        // Uso de fgets debido a que fscanf deja de leer la string al recibir un espacio
        fgets(opcionesArray[i].text, textLength + 1, fp);

        opcionesArray[i].funcion = funcionesArray[funcionIndex];

        printf("%s\n", opcionesArray[i].text);
    }

    fclose(fp);

    const opciones_acciones_t opcionesAccionesObject = {
        .length = opcionesLength,
        .array = opcionesArray,
    };

    return opcionesAccionesObject;
}