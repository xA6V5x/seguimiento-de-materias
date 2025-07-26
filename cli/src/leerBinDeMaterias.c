#include <stdio.h>
#include <stdlib.h>
#include "../headers/funciones.h"
#include "../headers/types.h"

materias_t leerBinDeMaterias() {
    materias_t materias;

    // Consumir materias-length.dat y materias.dat
    FILE *materiasLengthFile = fopen("../bin/materias-length.dat", "rb");
    if (materiasLengthFile == NULL) {
        fclose(materiasLengthFile);
        printf("Error al abrir materias-length.dat\n");
        esperarEnter();
        exit(1);
    }   
    
    size_t materiasLengthLeidos = fread(&materias.length, sizeof(int), 1, materiasLengthFile);
    
    if (materiasLengthLeidos != 1) {
        printf("Error al leer la cantidad de materias.\n");
        fclose(materiasLengthFile);
        esperarEnter();
        exit(1);
    }

    fclose(materiasLengthFile);

    // ---------------------------------------------------

    materias.array = malloc(materias.length * sizeof(materia_t));
    if (materias.array == NULL) {
        printf("Error al asignar memoria para las materias.\n");
        esperarEnter();
        exit(1);
    }

    FILE *materiasFile = fopen("../bin/materias.dat", "rb");
    if (materiasFile == NULL) {
        fclose(materiasFile);
        printf("Error al abrir materias.dat\n");
        esperarEnter();
        exit(1);
    }

    for(int i = 0; i < materias.length; i++) {
        // Extraer ID de la materia
        fread(&materias.array[i].id, sizeof(int), 1, materiasFile);
        
        // Extraer el nombre de la materia
        fread(&materias.array[i].nombreLength, sizeof(int), 1, materiasFile); // Largo del nombre
        materias.array[i].nombre = malloc((materias.array[i].nombreLength + 1) * sizeof(char));
        fread(materias.array[i].nombre, sizeof(char), materias.array[i].nombreLength, materiasFile);
        materias.array[i].nombre[materias.array[i].nombreLength] = '\0'; // Asegurar que el nombre sea una cadena válida

        // Extraer array de correlativas de la materia
        fread(&materias.array[i].correlativasLength, sizeof(int), 1, materiasFile); // Cantidad de correlativas
        materias.array[i].correlativas = malloc(sizeof(int) * materias.array[i].correlativasLength);
        fread(materias.array[i].correlativas, sizeof(int), materias.array[i].correlativasLength, materiasFile);

        // Inicializar el estado de la materia
        materias.array[i].estado = 0;
    }
    
    return materias;
}