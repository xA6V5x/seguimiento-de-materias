#include <stdio.h>
#include <stdlib.h>
#include "../headers/funciones.h"
#include "../headers/config.h"

void editarEstadoDeMateria()
{
    int opcion;

    do
    {
        system("cls");
        printf("== NUEVO ESTADO DE Fisica-1 ==\n");
        printf("1 - %s\n", config_get_no_cursada_string());
        printf("2 - %s\n", config_get_en_curso_string());
        printf("3 - %s\n", config_get_siguiente_cuatrimestre_string());
        printf("4 - %s\n", config_get_final_pendiente_string());
        printf("5 - %s\n", config_get_aprobada_string());
        printf("----------------\n");
        printf("0 - Cancelar\n");
        printf("\nSeleccione una opcion: ");

        scanf("%d", &opcion);
        limpiarBuffer();

        if (opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4 && opcion != 5 && opcion != 0)
        {
            errorOpcionNoValida();
        }
    } while (opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4 && opcion != 5 && opcion != 0);
}