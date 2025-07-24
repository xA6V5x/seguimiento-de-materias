#include <stdio.h>
#include <stdlib.h>
#include "../headers/funciones.h"

void materiasCursables() {
    int opcion;
    char buffer[10];

    do {
        system("cls");
        printf("== MATERIAS CURSABLES ==\n");
        printf("0 - Volver\n");
        printf("-------------------------------\n");
        printf("1 - Algebra-1\n");
        printf("2 - Fisica-1\n");
        printf("3 - Introduccion a la Ingenieria\n");
        printf("4 - Matematica-1\n");
        printf("\nSeleccione una opcion: ");
        scanf("%d", &opcion);
        fgets(buffer, sizeof(buffer), stdin); // limpiar buffer

        switch (opcion) {
            case 1:
                materiaInfo();
                break;
            case 2:
                materiaInfo();
                break;
            case 3:
                materiaInfo();
                break;
            case 4:
                materiaInfo();
                break;
            case 0:
                break;
            default:
                errorOpcionNoValida();
                break;
        }
    } while (opcion != 0);
}
