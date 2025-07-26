#include <stdio.h>
#include <stdlib.h> 
#include "../headers/funciones.h"

int main() {
  crearArchivosMock(); // materias-length.dat y materias.dat en seguimiento-de-materias/bin

  crearArchivosDeEstado(); // Checkear que todas las materias de materias.dat tenga un archivo de estado en cli/bin/${materiaId}.dat
  
  menuPrincipal();

  return 0;
}