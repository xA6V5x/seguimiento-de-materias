#include <stdio.h>
#include <stdlib.h>
#include "../headers/funciones.h"
#include "../headers/types.h"

void crearArchivosMock()
{
    // crear archivo materias-length.dat y materias.dat
    FILE *materiasLengthFileW = fopen("../bin/materias-length.dat", "wb");

    if (!materiasLengthFileW)
    {
        printf("Error al crear materias-length.dat\n");
        esperarEnter();
        return;
    }

    int cantidadMateriasW = 3;

    fwrite(&cantidadMateriasW, sizeof(int), 1, materiasLengthFileW);

    fclose(materiasLengthFileW);

    // ------------------------------------------------------------------------------------

    FILE *materiasFileW = fopen("../bin/materias.dat", "wb");
    if (materiasFileW == NULL)
    {
        printf("Error al crear materias.dat\n");
        esperarEnter();
        return;
    }

    materia_archivo_t materias[] = {
        {1, 9, "Algebra-1", 0, (int[]){}},
        {2, 12, "Matematica-1", 0, (int[]){}},
        {3, 8, "Fisica-1", 2, (int[]){1, 2}}};

    for (int i = 0; i < 3; i++)
    {
        fwrite(&materias[i].id, sizeof(int), 1, materiasFileW);
        fwrite(&materias[i].nombreLength, sizeof(int), 1, materiasFileW);
        fwrite(materias[i].nombre, sizeof(char), materias[i].nombreLength, materiasFileW);
        fwrite(&materias[i].correlativasLength, sizeof(int), 1, materiasFileW);
        if (materias[i].correlativas != NULL)
        {
            fwrite(materias[i].correlativas, sizeof(int), materias[i].correlativasLength, materiasFileW);
        }
    }

    fclose(materiasFileW);
}