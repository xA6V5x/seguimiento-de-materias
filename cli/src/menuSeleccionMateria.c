#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/funciones.h"
#include "../headers/types.h"

// materiasArray es un puntero doble por si al momento de filtrar quedan menos elementos entoces se tiene que Realocar
// El puntero apunta a un puntero que podria cambiar (si la cantidad de materias cambia entonces el materiasLength tambien cambia)
void menuSeleccionMateria(int estadoId, char *titulo, int *materiasLength, materia_t **materiasArray, ptr_funcion_filtro_t funcionFiltro)
{
    int opcion;

    sortMateriasPorNombre(*materiasLength, *materiasArray);

    do
    {
        system("cls");
        refrescarEstadosDeMaterias(*materiasLength, *materiasArray);
        if (funcionFiltro != NULL)
        {
            funcionFiltro(estadoId, materiasLength, materiasArray); // Modifica el puntero a materiasArray
        }
        printf("== %s ==\n", titulo);
        printf("0 - Volver\n");
        printf("-------------------------------\n");

        if (*materiasLength == 0)
        {
            printf("\n**NO SE ENCONTRARON MATERIAS CON ESTE ESTADO**\n");
        }
        else
        {
            for (int i = 0; i < *materiasLength; i++)
            {
                printf("%d - %s\n", i + 1, (*materiasArray)[i].nombre);
            }
        }
        printf("\nSeleccione una opcion: ");
        scanf("%d", &opcion);
        limpiarBuffer();

        if (opcion == 0)
        {
            break;
        }
        else if (opcion >= 1 && opcion <= *materiasLength)
        {
            int indexMateriaSeleccionada = opcion - 1;
            menuMateriaInfo((*materiasArray)[indexMateriaSeleccionada]);
        }
        else
        {
            errorOpcionNoValida();
        }

    } while (opcion != 0);
}
