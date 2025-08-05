#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/funciones.h"

void confirmarEliminarMateria(char *materiaNombre, int materiasLength, materia_archivo_t *materiasArray)
{
  char confirmarEliminacion[1];
  int isPressedS = 0;
  int isPressedN = 0;

  do
  {
    system("cls");
    printf("Seguro que quiere eliminar %s? (S/N)\n", materiaNombre);
    printf("\nSeleccione una opcion: ");
    scanf("%c", &confirmarEliminacion);
    limpiarBuffer();

    isPressedS = !strcmp(confirmarEliminacion, "S") || !strcmp(confirmarEliminacion, "s");
    isPressedN = !strcmp(confirmarEliminacion, "N") || !strcmp(confirmarEliminacion, "n");

    if (isPressedS)
    {
      actualizarBinMaterias(materiasLength, materiasArray);
      system("cls");
      printf("Se elimino correctamente la materia %s incluyendo su rol como correlativa.\n", materiaNombre);
      esperarEnter();
      // free(materiaNombre); // ERROR
      return;
    }
  } while (!isPressedS && !isPressedN);

  return;
}
