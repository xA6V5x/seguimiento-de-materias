#include <stdio.h>
#include <stdlib.h>
#include "../headers/funciones.h"

int confirmarCierreDelPrograma(){
  int confirmarCierre;
  char buffer[10];
  
  do {
    system("cls");
    printf("Seguro que desea salir?\n");
    printf("1 - confirmar\n");
    printf("2 - cancelar\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &confirmarCierre);
    fgets(buffer, sizeof(buffer), stdin); // limpiar buffer

    if(confirmarCierre == 1) {
      printf("Saliendo del programa...\n");
      return 1;
    } else if (confirmarCierre != 2) {
      errorOpcionNoValida();
    } 
  } while (confirmarCierre != 1 && confirmarCierre != 2);
  
  return 0;
}
