#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/config.h"
#include "../headers/funciones.h"
#include "../headers/types.h"

void actualizarBinMaterias(int materiasLength, materia_archivo_t *materiasArray)
{
    // Actualizar el contador-id.dat con el id mas alto disponible
    actualizarBinDeContadorId(&materiasLength, materiasArray);

    // crear archivo materias-length.dat
    FILE *materiasLengthFile = fopen("../bin/materias-length.dat", "wb");

    if (!materiasLengthFile)
    {
        printf("Error al crear materias-length.dat\n");
        esperarEnter();
        return;
    }

    fwrite(&materiasLength, sizeof(int), 1, materiasLengthFile);

    fclose(materiasLengthFile);

    // ------------------------------------------------------------------------------------

    // crear archivo materias.dat
    FILE *materiasFile = fopen("../bin/materias.dat", "wb");
    if (materiasFile == NULL)
    {
        printf("Error al crear materias.dat\n");
        esperarEnter();
        return;
    }

    if (materiasArray == NULL)
    {
        fwrite(NULL, sizeof(NULL), 1, materiasFile);
        return;
    }

    for (int i = 0; i < materiasLength; i++)
    {
        fwrite(&materiasArray[i].id, sizeof(int), 1, materiasFile);
        fwrite(&materiasArray[i].nombreLength, sizeof(int), 1, materiasFile);
        fwrite(materiasArray[i].nombre, sizeof(char), materiasArray[i].nombreLength, materiasFile);
        fwrite(&materiasArray[i].correlativasLength, sizeof(int), 1, materiasFile);
        if (materiasArray[i].correlativas != NULL)
        {
            fwrite(materiasArray[i].correlativas, sizeof(int), materiasArray[i].correlativasLength, materiasFile);
        }
    }

    fclose(materiasFile);

    return;
}
