#include <stdio.h>
#include <stdlib.h>
#include "../headers/funciones.h"

void esperarEnter() {
    char buffer[10];
    printf("Presionar Enter para continuar...");
    fgets(buffer, sizeof(buffer), stdin);
}