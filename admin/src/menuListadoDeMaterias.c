#include <stdio.h>
#include <stdlib.h>
#include "../headers/funciones.h"

void menuListadoDeMaterias() {
    int opcion;
    char buffer[10];

    do {
        system("cls");
        printf("Listado de Materias\n");
        printf("1 - Volver\n");
        printf("2 - matematica-1\n");
        printf("3 - algebra-1\n");
        printf("4 - fisica-1\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        fgets(buffer, sizeof(buffer), stdin); // limpiar buffer

        switch (opcion) {
            case 1:
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
            default:
                errorOpcionNoValida();
                break;
        }
    } while (opcion != 1);
}