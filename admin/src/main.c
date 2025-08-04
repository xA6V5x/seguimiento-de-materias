#include <stdio.h>
#include <stdlib.h>
#include "../headers/funciones.h"
#include "../headers/config.h"
#include "../headers/types.h"

int main()
{

  int opcion;
  int confirmarSalida = 0;

  const int opcionesArrayLength = config_get_opciones_acciones_object()->length;
  const opcion_accion_t *opcionesArray = config_get_opciones_acciones_object()->array;

  do
  {
    printMenuPrincipal();
    scanf("%d", &opcion);
    limpiarBuffer();
    procesarOpcion(&opcion, opcionesArrayLength, opcionesArray);
  } while (opcion != 0);

  return 0;
}