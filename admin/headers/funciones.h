#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "types.h"

// Archivos
void crearArchivosMock();
opciones_acciones_t leerTxtConfig(const ptr_funcion_void_t *funcionesArray);
materias_t leerBinDeMaterias();
void agregarMateria();

// Utilidades
void procesarOpcion(int *opcion, const int opcionesArrayLength, const opcion_accion_t *opcionesArray);
void limpiarBuffer();
void esperarEnter();
void *miMalloc(char *contexto, size_t size);
void sortMateriasPorNombre(int materiasLength, materia_archivo_t *materiasArray);

// Menus
int menuPrincipal();
void menuSeleccionMateria(int estadoId, char *titulo, int *materiasLength, materia_archivo_t **materiasArray);
void menuEditarMaterias();
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