#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "types.h"

// Archivos
void crearArchivosMock();
materias_t leerBinDeMaterias();

// Utilidades
void *miMalloc(char *contexto, size_t size);
void esperarEnter();
void limpiarBuffer();
void sortMateriasPorNombre(int materiasLength, materia_archivo_t *materiasArray);

// Menus
int menuPrincipal();
void menuSeleccionMateria(int estadoId, char *titulo, int *materiasLength, materia_archivo_t **materiasArray);
void menuEditarMaterias();
void menuAgregarMaterias();
void menuEliminarMaterias();
void menuMateriaInfo(materia_archivo_t materia, int materiasLength, materia_archivo_t *materiasArray);

// Texto
void printMenuPrincipal();
void printEstadoMateria(int estado);
void printMateriasCorrelativas(materia_archivo_t materia, int materiasLength, materia_archivo_t *materiasArray);
int confirmarCierreDelPrograma();

// Errores
void errorOpcionNoValida();

#endif