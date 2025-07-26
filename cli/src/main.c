#include <stdio.h>
#include <stdlib.h>
#include "../headers/funciones.h"

int main()
{
  // materias-length.dat y materias.dat en seguimiento-de-materias/bin
  crearArchivosMock(); // Retirar cuando admin este listo

  // Checkear que todas las materias de materias.dat tenga un archivo de estado en cli/bin/${materiaId}.dat,
  // si no lo crea con el estado inicial 1 (No cursada)
  crearArchivosDeEstado();

  menuPrincipal();

  return 0;
}