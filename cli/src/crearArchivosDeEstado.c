#include <stdio.h>
#include <stdlib.h>
#include "../headers/funciones.h"
#include "../headers/types.h"

// Checkear que todas las materias de materias.dat tenga un archivo de estado en cli/bin/${materiaId}.dat,
// sino lo crea con el estado inicial 1 (No cursada)
void crearArchivosDeEstado()
{
    materias_t materias = leerBinDeMaterias();

    int materiasLength = materias.length;

    materia_t *materiasArray = materias.array;

    for (int i = 0; i < materiasLength; i++)
    {
        char filename[50];

        // Construir el path para cada archivo binario individual de materia
        sprintf(filename, "./bin/%d.dat", materiasArray[i].id);

        // Intentar abrir el archivo en modo lectura binaria
        FILE *fr = fopen(filename, "rb");

        // El archivo no existe entonces se crea con valor 1
        if (fr == NULL)
        {
            FILE *fw = fopen(filename, "wb");
            if (fw == NULL)
            {
                fclose(fw);
                perror("Error al crear el archivo");
                esperarEnter();
                exit(1);
            }

            int valorDefault = 1; // No cursada

            fwrite(&valorDefault, sizeof(int), 1, fw);
            fclose(fw);
        }
        else
        {
            // Si el archivo ya existe no hacer nada
            fclose(fr);
        }
    }
}