#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/funciones.h"

void confirmarEliminarMateria(materia_archivo_t *materia, int materiasLength, materia_archivo_t *materiasArray)
{
  char confirmarEliminacion[1];
  int isPressedS = 0;
  int isPressedN = 0;

  char *materiaNombre = miMalloc("inicializar nombre de la materia", sizeof(char) * materia->nombreLength);
  strcpy(materiaNombre, materia->nombre);

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
      printf("Se eliminó correctamente la materia %s incluyendo su rol como correlativa.\n", materia->nombre);
      esperarEnter();
      free(materiaNombre);
      return;
    }
    else if (!isPressedN)
    {
      errorOpcionNoValida();
    }
  } while (!isPressedS && !isPressedN);

  return;
}
