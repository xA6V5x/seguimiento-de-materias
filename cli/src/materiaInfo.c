#include <stdio.h>
#include <stdlib.h> 
#include "../headers/funciones.h"

int materiaInfo() {
    int opcion;
    char buffer[10];

    do {
        system("cls");
        printf("== MATERIA Fisica-1 ==\n");
        printf("id: 4\n");
        printf("nombre: Fisica-1\n");
        printf("correlativas: Matematica-1, Algebra-1\n");
        printf("estado: no cursada\n");
        printf("----------------\n");
        printf("1 - Editar estado\n");
        printf("0 - Volver\n");
        printf("\nSeleccione una opcion: ");

        scanf("%d", &opcion);
        fgets(buffer, sizeof(buffer), stdin);

        switch (opcion) {
            case 1:
                editarEstadoDeMateria();
                break;
            case 0:
                break;
            default:
                errorOpcionNoValida();
                break;
        }
    } while (opcion != 0);
    
}