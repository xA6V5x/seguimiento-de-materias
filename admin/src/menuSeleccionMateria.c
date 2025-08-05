#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/funciones.h"
#include "../headers/types.h"

// materiasArray es un puntero doble por si al momento de filtrar quedan menos elementos entoces se tiene que Realocar
// el puntero apunta a un puntero que podria cambiar (si la cantidad de materias cambia entonces el materiasLength tambien cambia)
void menuSeleccionMateria(char *titulo, ptr_funcion_editar_eliminar_materia_t funcion)
{
    int opcion;

    do
    {
        // ----------------------------------------------------
        // Leer materias y ordenarlas dentro del bucle por si la cantidad de materias cambia o si el nombre es modificado
        materias_t *materias = leerBinDeMaterias();

        int *materiasLength = &materias->length;

        materia_archivo_t *materiasArray = materias->array;

        sortMateriasPorNombre(*materiasLength, materiasArray);
        // ----------------------------------------------------

        system("cls");
        printf("== %s ==\n", titulo);
        printf("0 - Volver\n");
        printf("-------------------------------\n");

        if (*materiasLength == 0)
        {
            printf("\n**NO SE ENCONTRARON MATERIAS**\n");
        }
        else
        {
            for (int i = 0; i < *materiasLength; i++)
            {
                printf("%d - %s\n", i + 1, materiasArray[i].nombre);
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
            char tituloFuncion[15] = "EDITAR MATERIA";
            int indexMateriaSeleccionada = opcion - 1;
            funcion(tituloFuncion, &materiasArray[opcion - 1], materiasLength, &materiasArray);
        }
        else
        {
            errorOpcionNoValida();
        }

    } while (opcion != 0);
}
