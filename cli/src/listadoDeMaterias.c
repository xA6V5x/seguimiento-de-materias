#include <stdio.h>
#include <stdlib.h>
#include "../headers/funciones.h"
#include "../headers/types.h"

void listadoDeMaterias() {
    int opcion;
    char buffer[10];

    // Consumir materias-length.dat y materias.dat
    FILE *materiasLengthFile = fopen("../bin/materias-length.dat", "rb");
    if (materiasLengthFile == NULL) {
        fclose(materiasLengthFile);
        printf("Error al abrir materias-length.dat\n");
        esperarEnter();
        return;
    }   
    
    int materiasLength;
    
    size_t materiasLengthLeidos = fread(&materiasLength, sizeof(int), 1, materiasLengthFile);
    
    if (materiasLengthLeidos != 1) {
        printf("Error al leer la cantidad de materias.\n");
        fclose(materiasLengthFile);
        esperarEnter();
        return;
    }

    fclose(materiasLengthFile);

    // ---------------------------------------------------

    materia_con_estado_t *materiasArray = malloc(materiasLength * sizeof(materia_con_estado_t));

    FILE *materiasFile = fopen("../bin/materias.dat", "rb");
    if (materiasFile == NULL) {
        fclose(materiasFile);
        printf("Error al abrir materias.dat\n");
        esperarEnter();
        return;
    }

    for(int i = 0; i < materiasLength; i++) {
        // Extraer ID de la materia
        fread(&materiasArray[i].id, sizeof(int), 1, materiasFile);
        
        // Extraer el nombre de la materia
        fread(&materiasArray[i].nombreLength, sizeof(int), 1, materiasFile); // Largo del nombre
        materiasArray[i].nombre = malloc((materiasArray[i].nombreLength + 1) * sizeof(char));
        fread(materiasArray[i].nombre, sizeof(char), materiasArray[i].nombreLength, materiasFile);
        materiasArray[i].nombre[materiasArray[i].nombreLength] = '\0'; // Asegurar que el nombre sea una cadena válida

        // Extraer array de correlativas de la materia
        fread(&materiasArray[i].correlativasLength, sizeof(int), 1, materiasFile); // Cantidad de correlativas
        materiasArray[i].correlativas = malloc(sizeof(int) * materiasArray[i].correlativasLength);
        fread(materiasArray[i].correlativas, sizeof(int), materiasArray[i].correlativasLength, materiasFile);

        // Inicializar el estado de la materia
        materiasArray[i].estado = 0;
    }   

    // for(int i = 0; i < materiasLength; i++) {
    //     printf("Materia ID: %d\n", materiasArray[i].id);
    //     printf("NombreLength: %d\n", materiasArray[i].nombreLength);
    //     printf("Nombre: %s\n", materiasArray[i].nombre);
    //     printf("Correlativas: ");
    //     int correlativasLength = materiasArray[i].correlativasLength;
    //     if (correlativasLength > 0) {
    //         for(int j = 0; j < correlativasLength; j++) {
    //             int materiaIdBuscada = materiasArray[i].correlativas[j];
    //             for(int k = 0; k < materiasLength; k++) {
    //                 if(materiasArray[k].id == materiaIdBuscada) {
    //                     printf("%s (id: %d); ", materiasArray[k].nombre, materiaIdBuscada);
    //                     break;
    //                 }
    //             }
    //         }
    //     } else {
    //         printf("--");
    //     }
    //     printf("\nEstado: %d\n", materiasArray[i].estado);
    // }
    //--------------------------------------------------------------------------------------------

    do {
        system("cls");
        printf("== LISTADO DE MATERIAS ==\n");
        printf("0 - Volver\n");
        printf("-------------------------------\n");
        for (int i = 0; i < materiasLength; i++) {
            printf("%d - %s\n", i + 1, materiasArray[i].nombre);
        }
        printf("\nSeleccione una opcion: ");
        scanf("%d", &opcion);
        fgets(buffer, sizeof(buffer), stdin); // limpiar buffer

       if (opcion == 0) {
            break;
        } else if (opcion >= 1 && opcion <= materiasLength) {
            int indexMateriaSeleccionada = opcion - 1;
            materiaInfo(materiasArray[indexMateriaSeleccionada]);
        } else {
            errorOpcionNoValida();
        }
    } while (opcion != 0);
}
