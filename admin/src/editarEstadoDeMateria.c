#include <stdio.h>
#include <stdlib.h> 
#include "../headers/funciones.h"

void editarEstadoDeMateria() {
    int opcion;
    char buffer[10];

    do {
        system("cls");
        printf("Nuevo estado para fisica-1\n");
        printf("1 - no cursada\n");
        printf("2 - aprobada\n");
        printf("----------------\n");
        printf("3 - cancelar\n");
        printf("Seleccione una opcion: ");
        
        scanf("%d", &opcion);
        fgets(buffer, sizeof(buffer), stdin);

        if(opcion != 1 && opcion != 2 && opcion != 3) {
            errorOpcionNoValida();
        }
    } while (opcion != 1 && opcion != 2 && opcion != 3);
}