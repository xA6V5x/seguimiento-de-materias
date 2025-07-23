#include <stdio.h>
#include <stdlib.h>
#include "../headers/funciones.h"

void materiasCursables() {
    int opcion;
    char buffer[10];

    do {
        system("cls");
        printf("Materias Cursables\n");
        printf("1 - Volver\n");
        printf("2 - fisica-1\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        fgets(buffer, sizeof(buffer), stdin); // limpiar buffer

        switch (opcion) {
            case 1:
                break;
            case 2:
                materiaInfo();
                break;
            default:
                errorOpcionNoValida();
                break;
        }
    } while (opcion != 1);
}
