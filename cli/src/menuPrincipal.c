#include <stdio.h>
#include <stdlib.h>
#include "../headers/funciones.h"

int menuPrincipal() {
    int opcion;
    int confirmarSalida = 0;
    char buffer[10];

    do{
        textoMenuPrincipal();
        scanf("%d", &opcion);
        fgets(buffer, sizeof(buffer), stdin); // limpiar buffer

        switch (opcion) {
            case 1:
                listadoDeMaterias();
                break;
            case 2:
                materiasCursables();
                break;
            case 3:
                materiasCursables();
                break;
            case 4:
                materiasCursables();
                break;
            case 5:
                materiasCursables();
                break;
            case 6:
                materiasCursables();
                break;
            case 0:
                int salir = confirmarCierreDelPrograma();
                if(!salir) {
                  opcion = -1; // Resetear opcion para no salir del bucle
                }
                break;
            default:
                errorOpcionNoValida();
                break;
        }
  } while (opcion != 0);

  return 0;
}