#include <stdio.h>
#include <stdlib.h>
#include "../headers/funciones.h"
#include "../headers/types.h"

// Leer ${materia.id}.dat (int)
void leerBinEstadoDeMateria(materia_t *materia)
{
    char filename[50];

    // Construir el path
    sprintf(filename, "./bin/%d.dat", materia->id);

    FILE *fr = fopen(filename, "rb");
    if (fr == NULL)
    {
        fclose(fr);
        printf("Error al abrir el estado de la materia %d.dat\n", materia->id);
        esperarEnter();
        exit(1);
    }

    size_t estadoDeLaMateriaLeidos = fread(&materia->estado, sizeof(int), 1, fr);

    if (estadoDeLaMateriaLeidos != 1)
    {
        printf("Error al leer el estado de la materia %d.dat.\n", materia->id);
        fclose(fr);
        esperarEnter();
        exit(1);
    }

    fclose(fr);
}