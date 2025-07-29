#include <stdio.h>
#include <stdlib.h>
#include "../headers/funciones.h"
#include "../headers/config.h"

void menuEditarEstadoDeMateria(int materiaId)
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

        // Si la opcion seleccionada es 5 (Aprobada), checkear que los estados de las correlativas sean Aprobadas (5)
        // De no tener alguna de las correlativas requeridas con estado de aprobación devolver el error
        // "Error: Esta materia requiere que la correlativa ${NombreDeMateria} esté aprobada antes de marcarla como aprobada."

        char filename[50];

        // Construir el path para cada archivo binario individual de materia
        sprintf(filename, "./bin/%d.dat", materiaId);

        FILE *fw = fopen(filename, "wb");
        if (fw == NULL)
        {
            fclose(fw);
            perror("Error al actualizar el estado de la materia.");
            esperarEnter();
            exit(1);
        }
        fwrite(&opcion, sizeof(int), 1, fw);
        fclose(fw);

    } while (opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4 && opcion != 5 && opcion != 0);
}