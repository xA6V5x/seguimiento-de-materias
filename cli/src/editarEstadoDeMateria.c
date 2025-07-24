#include <stdio.h>
#include <stdlib.h> 
#include "../headers/funciones.h"

void editarEstadoDeMateria() {
    int opcion;
    char buffer[10];

    do {
        system("cls");
        printf("== NUEVO ESTADO DE Fisica-1 ==\n");
        printf("1 - No cursada\n");
        printf("2 - En curso\n");
        printf("3 - Siguiente cuatrimestre\n");
        printf("4 - Final pendiente\n");
        printf("5 - Aprobada\n");
        printf("----------------\n");
        printf("0 - Cancelar\n");
        printf("\nSeleccione una opcion: ");
        
        scanf("%d", &opcion);
        fgets(buffer, sizeof(buffer), stdin);

        if(opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4 && opcion != 5 && opcion != 0) {
            errorOpcionNoValida();
        }
    } while (opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4 && opcion != 5 && opcion != 0);
}