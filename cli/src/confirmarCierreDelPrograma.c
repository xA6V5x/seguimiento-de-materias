#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/funciones.h"

int confirmarCierreDelPrograma(){
  char confirmarCierre[1];
  char buffer[10];
  int isPressedS = 0;
  int isPressedN = 0;
  
  do {
      system("cls");
      printf("Esta seguro que desea salir? (S/N)\n");
      printf("\nSeleccione una opcion: ");
      scanf("%c", &confirmarCierre);
      fgets(buffer, sizeof(buffer), stdin); // limpiar buffer

      
      isPressedS = !strcmp(confirmarCierre, "S") || !strcmp(confirmarCierre, "s");
      isPressedN = !strcmp(confirmarCierre, "N") || !strcmp(confirmarCierre, "n");
      
      if(isPressedS) {
        printf("Saliendo del programa...\n");
        return 1;
      } else if (!isPressedN) {
        errorOpcionNoValida();
      } 
  } while (!isPressedS && !isPressedN);
  
  return 0;
}
