#include <stdio.h>
#include <stdlib.h>
#include "../headers/funciones.h"

void menuAgregarMaterias() {
    int opcion;
    char buffer[10];

    do {
        system("cls");
        printf("Como quieres agregar las nuevas materias?\n");
        printf("1 - Volver\n");
        printf("2 - Direccion de documento txt\n");
        printf("3 - Manualmente\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        fgets(buffer, sizeof(buffer), stdin); // limpiar buffer

        switch (opcion) {
            case 1:
                break;
            case 2:
                extraccionDeMateriasDesdeArchivoTxt();
                break;
            case 3:
                agregarMateriaManualmente();    
                break;
            default:
                errorOpcionNoValida();
                break;
        }
    } while (opcion != 1);
}