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
            menuListadoDeMaterias();
            break;
        case 2:
            menuMateriasCursables();
            break;
        case 3:
            menuMateriasEnCurso();
            break;
        case 4:
            menuMateriasSiguienteCuatrimestre();
            break;
        case 5:
            menuMateriasFinalPendiente();
            break;
        case 6:
            menuMateriasAprobadas();
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