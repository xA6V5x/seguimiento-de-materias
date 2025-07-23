#include <stdio.h>
#include <stdlib.h>
#include "../headers/funciones.h"

int eliminarTodasLasMaterias() {
  int confirmarEliminacion;
  char buffer[10];
  
  do {
    system("cls");
    printf("Seguro que desea eliminar TODAS las materias?\n");
    printf("Esta accion no se puede deshacer\n");
    printf("1 - confirmar\n");
    printf("2 - cancelar\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &confirmarEliminacion);
    fgets(buffer, sizeof(buffer), stdin); // limpiar buffer

    if(confirmarEliminacion == 1) {
      printf("Eliminando todas las materias...\n");
      return 1;
    } else if (confirmarEliminacion != 2) {
      errorOpcionNoValida();
    } 
  } while (confirmarEliminacion != 1 && confirmarEliminacion != 2);
  
  return 0;
}
