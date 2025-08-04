#include <stdio.h>
#include <stdlib.h>
#include "../headers/funciones.h"
#include "../headers/types.h"

int actualizarBinDeContadorId(int contadorId)
{
    // Sumarle 1 al archivo de contador id
    int nuevoContadorId = contadorId + 1;

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