#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "types.h"

// Archivos
void crearArchivosMock();
void crearArchivosDeEstado();
materias_t leerBinDeMaterias();
void leerBinEstadoDeMateria(materia_t *materia);
void refrescarEstadosDeMaterias(int materiasLength, materia_t *materiasArray);

// Utilidades
void *miMalloc(char *contexto, size_t size);
void esperarEnter();
void limpiarBuffer();
void sortMateriasPorNombre(int materiasLength, materia_t *materiasArray);
void filtrarMateriasCursables(int estadoId, int *materiasLength, materia_t **materiasArray);
void filtrarMateriasPorEstado(int estadoId, int *materiasLength, materia_t **materiasArray);
int comprobarCorrelativasAprobadas(materia_t *materia);

// Menus
int menuPrincipal();
void menuSeleccionMateria(int estadoId, char *titulo, int *materiasLength, materia_t **materiasArray, ptr_funcion_filtro_t funcionFiltro);
void menuListadoDeMaterias();
void menuMateriasCursables();
void menuMateriasEnCurso();
void menuMateriasSiguienteCuatrimestre();
void menuMateriasFinalPendiente();
void menuMateriasAprobadas();
void menuMateriaInfo(materia_t materia, int materiasLength, materia_t *materiasArray);
void menuEditarEstadoDeMateria(materia_t *materia);

// Texto
void printMenuPrincipal();
void printEstadoMateria(int estado);
void printMateriasCorrelativas(materia_t materia, int materiasLength, materia_t *materiasArray);
int confirmarCierreDelPrograma();

// Errores
void errorOpcionNoValida();

#endif