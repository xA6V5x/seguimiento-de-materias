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
                menuListadoDeMaterias();
                break;
            case 2:
                materiasCursables();
                break;
            case 3:
                menuAgregarMaterias();
                break;
            case 4:
                eliminarTodasLasMaterias();
                break;
            case 5:
                int salir = confirmarCierreDelPrograma();
                if(!salir) {
                  opcion = 0; // Resetear opcion para no salir del bucle
                }
                break;
            default:
                errorOpcionNoValida();
                break;
        }
  } while (opcion != 5);

  return 0;
}