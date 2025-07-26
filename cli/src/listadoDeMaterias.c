#include <stdio.h>
#include <stdlib.h>
#include "../headers/funciones.h"
#include "../headers/types.h"

void listadoDeMaterias() {
    int opcion;
    char buffer[10];

    materias_t materias = leerBinDeMaterias();

    int materiasLength = materias.length;

    materia_t *materiasArray = materias.array;

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
            materiaInfo(materiasArray[indexMateriaSeleccionada], materiasLength, materiasArray);
        } else {
            errorOpcionNoValida();
        }
    } while (opcion != 0);
}
