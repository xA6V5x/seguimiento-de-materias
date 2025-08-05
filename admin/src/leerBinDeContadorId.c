#include <stdio.h>
#include <stdlib.h>
#include "../headers/funciones.h"
#include "../headers/types.h"

int leerBinDeContadorId()
{
    int contadorId;

    // Consumir materias-length.dat y materias.dat
    FILE *fr = fopen("./bin/contador-id.dat", "rb");
    if (fr == NULL)
    {
        // Si no existe contador-id.dat crearlo
        int nuevoContadorId = actualizarBinDeContadorId(NULL, NULL);

        return nuevoContadorId;
    }

    size_t materiasLengthLeidos = fread(&contadorId, sizeof(int), 1, fr);

    if (materiasLengthLeidos != 1)
    {
        printf("Error al leer el contador id.\n");
        fclose(fr);
        esperarEnter();
        exit(1);
    }

    fclose(fr);

    return contadorId;
}