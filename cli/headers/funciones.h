#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "types.h"

// Archivos
void crearArchivosDeEstado();
opciones_acciones_t leerTxtConfig(const ptr_funcion_void_t *funcionesArray);
materias_t leerBinDeMaterias();
void leerBinEstadoDeMateria(materia_t *materia);
void refrescarEstadosDeMaterias(int materiasLength, materia_t *materiasArray);

// Utilidades
void procesarOpcion(int *opcion, const int opcionesArrayLength, const opcion_accion_t *opcionesArray);
void esperarEnter();
void limpiarBuffer();
void *miMalloc(char *contexto, size_t size);
void sortMateriasPorNombre(int materiasLength, materia_t *materiasArray);
void filtrarMateriasCursables(int estadoId, int *materiasLength, materia_t **materiasArray);
void filtrarMateriasPorEstado(int estadoId, int *materiasLength, materia_t **materiasArray);
int comprobarCorrelativasAprobadas(materia_t *materia);

// Menus
void menuSeleccionMateria(int estadoId, char *titulo, int *materiasLength, materia_t **materiasArray, ptr_funcion_filtro_t funcionFiltro);
void menuListadoDeMaterias();
void menuMateriasCursables();
void menuMateriasEnCurso();
void menuMateriasSiguienteCuatrimestre();
void menuMateriasFinalPendiente();
void menuMateriasAprobadas();
void menuMateriaInfo(materia_t materia);
void menuEditarEstadoDeMateria(materia_t *materia);

// Texto
void printMenuPrincipal(const int opcionesArrayLength, const opcion_accion_t *opcionesArray);
void printEstadoMateria(int estado);
void printMateriasCorrelativas(materia_t materia);
int confirmarCierreDelPrograma();

// Errores
void errorOpcionNoValida();

#endif