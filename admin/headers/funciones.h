#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "types.h"

// Archivos
opciones_acciones_t leerTxtConfig(const ptr_funcion_void_t *funcionesArray);
materias_t *leerBinDeMaterias();
int leerBinDeContadorId();
int actualizarBinDeContadorId(int *materiasLength, materia_archivo_t *materiasArray);
void actualizarBinMaterias(int materiasLength, materia_archivo_t *materiasArray);
void confirmarEliminarMateria(char *materiaNombre, int materiasLength, materia_archivo_t *materiasArray);
void eliminarMateria(char *title, materia_archivo_t *materia, int *materiasLength, materia_archivo_t **materiasArray);

// Utilidades
void procesarOpcion(int *opcion, const int opcionesArrayLength, const opcion_accion_t *opcionesArray);
void limpiarBuffer();
void esperarEnter();
int esOpcionNumericaValida(const char *input, int min, int max, int *opcionTraducida);
void *miMalloc(char *contexto, size_t size);
void sortMateriasPorNombre(int materiasLength, materia_archivo_t *materiasArray);
void sortMateriasPorId(int materiasLength, materia_archivo_t *materiasArray);
void editarMateriaNombre(materia_archivo_t *materia);
void editarMateriaCorrelativas(materia_archivo_t *materia);
void copiarMateria(materia_archivo_t *materiaCpy, materia_archivo_t *materia);
materia_archivo_t *buscarMateriaPorId(int *materiaBuscadaIndex, int materiaId, int materiasLength, materia_archivo_t *materiasArray);
void filtrarMateriaDelArray(int materiaBuscadaId, int *materiasLength, materia_archivo_t **materiasArray);
void agregarCorrelativa(int correlativaId, materia_archivo_t *materia);
void eliminarCorrelativa(int correlativaId, materia_archivo_t *materia);
materia_archivo_t *agregarMateriaAlArray(materia_archivo_t materia, int *materiasLength, materia_archivo_t **materiasArray);

// Menus
void menuSeleccionMateriaParaEditar();
void menuAgregarMateria();
void menuSeleccionMateriaParaEliminar();
void menuEditarMateria(char *title, materia_archivo_t *materia, int *materiasLength, materia_archivo_t **materiasArray);
void menuSeleccionMateria(char *titulo, char *tituloFuncion, ptr_funcion_editar_eliminar_materia_t funcion);
void menuMateriaInfo(materia_archivo_t materia, int materiasLength, materia_archivo_t *materiasArray);

// Texto
void printMenuPrincipal(const int opcionesArrayLength, const opcion_accion_t *opcionesArray);
void printEstadoMateria(int estado);
void printMateriasCorrelativas(materia_archivo_t materia, int materiasLength, materia_archivo_t *materiasArray);
void printSeleccionarCorrelativas(int correlativasLength, materia_archivo_t *correlativasArray, int noCorrelativasLength, materia_archivo_t *noCorrelativasArray, int materiasLength, materia_archivo_t *materiasArray);
int confirmarCierreDelPrograma();

// Errores
void errorOpcionNoValida();

#endif