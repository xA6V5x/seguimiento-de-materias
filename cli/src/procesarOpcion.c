#include <stdio.h>
#include <stdlib.h>
#include "../headers/funciones.h"
#include "../headers/types.h"

void procesarOpcion(int *opcion, const int opcionesArrayLength, const opcion_accion_t *opcionesArray)
{
    if (*opcion == 0)
    {
        int salir = confirmarCierreDelPrograma();
        if (!salir)
        {
            *opcion = -1; // Resetear opcion para no salir del bucle
        }
        return;
    }

    if (*opcion >= 1 && *opcion <= opcionesArrayLength)
    {
        int indexFuncionSeleccionada = *opcion - 1;
        opcionesArray[indexFuncionSeleccionada].funcion();
    }
    else
    {
        errorOpcionNoValida();
    }

    return;
}