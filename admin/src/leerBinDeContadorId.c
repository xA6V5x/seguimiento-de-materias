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
        fclose(fr);

        materias_t materias = leerBinDeMaterias();

        int maxIdActual = 0;

        if (materias.length > 0)
        {
            // Ordenar por id para poder obtener el id mas alto como referencia
            sortMateriasPorId(materias.length, materias.array);
            maxIdActual = materias.array[materias.length - 1].id;
        }

        // Le envio el id mas alto actual, le suma 1 y lo guarda en contador-id.dat
        int nuevoContadorId = actualizarBinDeContadorId(maxIdActual);

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