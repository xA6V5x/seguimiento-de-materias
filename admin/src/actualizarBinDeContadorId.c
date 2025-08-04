#include <stdio.h>
#include <stdlib.h>
#include "../headers/funciones.h"
#include "../headers/types.h"

int actualizarBinDeContadorId(int *materiasLength, materia_archivo_t *materiasArray)
{
    int nuevoContadorId = 0;

    // Se agrego una nueva materia y hay que actualizar contador-id.dat
    if (materiasLength != NULL && materiasArray != NULL)
    {
        sortMateriasPorId(*materiasLength, materiasArray);
        // Sumarle 1 al id mas alto actual
        nuevoContadorId = materiasArray[*materiasLength - 1].id + 1;
    }

    FILE *fw = fopen("./bin/contador-id.dat", "wb");

    if (!fw)
    {
        printf("Error al crear contador-id.dat\n");
        esperarEnter();
        exit(1);
    }

    fwrite(&nuevoContadorId, sizeof(int), 1, fw);

    fclose(fw);

    return nuevoContadorId;
};