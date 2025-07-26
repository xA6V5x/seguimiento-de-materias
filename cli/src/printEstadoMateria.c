#include <stdio.h>
#include <stdlib.h>
#include "../headers/funciones.h"

void printEstadoMateria(int estado)
{
    estado == 1 ? printf("no cursada\n") : estado == 2 ? printf("en curso\n")
                                       : estado == 3   ? printf("siguiente cuatrimestre\n")
                                       : estado == 4   ? printf("final pendiente\n")
                                       : estado == 5   ? printf("aprobada\n")
                                                       : printf("estado desconocido\n");
}
