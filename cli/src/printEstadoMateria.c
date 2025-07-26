#include <stdio.h>
#include <stdlib.h>
#include "../headers/funciones.h"
#include "../headers/config.h"

void printEstadoMateria(int estado)
{
    estado == 1 ? printf("%s\n", config_get_no_cursada_string()) : estado == 2 ? printf("%s\n", config_get_en_curso_string())
                                                               : estado == 3   ? printf("%s\n", config_get_siguiente_cuatrimestre_string())
                                                               : estado == 4   ? printf("%s\n", config_get_final_pendiente_string())
                                                               : estado == 5   ? printf("%s\n", config_get_aprobada_string())
                                                                               : printf("estado desconocido\n");
}
