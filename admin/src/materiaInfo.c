#include <stdio.h>
#include <stdlib.h> 
#include "../headers/funciones.h"

int materiaInfo() {
    int opcion;
    char buffer[10];

    do {
        system("cls");
        printf("Materia: fisica-1\n");
        printf("Descripcion:\n");
        printf("Correlativas: matematica-1, algebra-1\n");
        printf("Estado: no cursada\n");
        printf("----------------\n");
        printf("1 - Volver\n");
        printf("2 - Editar estado\n");
        printf("Seleccione una opcion: ");

        scanf("%d", &opcion);
        fgets(buffer, sizeof(buffer), stdin);

        switch (opcion) {
            case 1:
                break;
            case 2:
                editarEstadoDeMateria();
                break;
            default:
                errorOpcionNoValida();
                break;
        }
    } while (opcion != 1);
    
}