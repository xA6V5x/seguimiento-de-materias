#include <stdio.h>
#include <stdlib.h>
#include "../headers/funciones.h"

void textoMenuPrincipal() {
    system("cls");
    printf("=== SEGUIMIENTO DE MATERIAS ===\n");
    printf("1 - Ver listado de materias\n");
    printf("2 - Filtrar materias Cursables\n");
    printf("3 - Filtrar materias En Curso\n");
    printf("4 - Filtrar materias Siguiente Cuatrimestre\n");
    printf("5 - Filtrar materias Final Pendiente\n");
    printf("6 - Filtrar materias Aprobadas\n");
    printf("-------------------------------\n");
    printf("0 - Salir\n");
    printf("\nSeleccione una opcion: ");
}
