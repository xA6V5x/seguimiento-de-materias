#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/funciones.h"

int esOpcionNumericaValida(const char *input, int min, int max, int *opcionTraducida)
{
  int len = strlen(input);

  if (len == 0 || strspn(input, "0123456789") != len)
    return 0;

  int num = atoi(input);
  if (num < min || num > max)
    return 0;

  *opcionTraducida = num;
  return 1;
}
