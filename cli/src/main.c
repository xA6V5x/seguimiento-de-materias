#include <stdio.h>
#include <stdlib.h>
#include "../headers/funciones.h"
#include "../headers/types.h"
#include "../headers/config.h"

int main()
{
  // Checkear que todas las materias de materias.dat tenga un archivo de estado en cli/bin/${materiaId}.dat,
  // si no lo crea con el estado inicial 1 (No cursada)
  crearArchivosDeEstado();

  int opcion;
  int confirmarSalida = 0;

  const int opcionesArrayLength = config_get_opciones_acciones_object()->length;
  const opcion_accion_t *opcionesArray = config_get_opciones_acciones_object()->array;

  do
  {
    printMenuPrincipal(opcionesArrayLength, opcionesArray);
    scanf("%d", &opcion);
    limpiarBuffer();
    procesarOpcion(&opcion, opcionesArrayLength, opcionesArray);
  } while (opcion != 0);

  return 0;
}