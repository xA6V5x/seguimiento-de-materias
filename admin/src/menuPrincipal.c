#include <stdio.h>
#include <stdlib.h>
#include "../headers/funciones.h"

int menuPrincipal()
{
    int opcion;
    int confirmarSalida = 0;

    do
    {
        printMenuPrincipal();
        scanf("%d", &opcion);
        limpiarBuffer();

        switch (opcion)
        {
        case 1:
            menuEditarMaterias();
            break;
        case 2:
            menuAgregarMaterias();
            break;
        case 3:
            menuEliminarMaterias();
            break;
        case 0:
            int salir = confirmarCierreDelPrograma();
            if (!salir)
            {
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