#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "types.h"

// Archivos
void crearArchivosMock();
void crearArchivosDeEstado();
materias_t leerBinDeMaterias();
void editarEstadoDeMateria();
void materiaInfo();

// Utilidades
void esperarEnter();
void limpiarBuffer();

// Menus
int menuPrincipal();
void menuSeleccionMateria(char *titulo, int materiasLength, materia_t *materiasArray);
void menuListadoDeMaterias();
void menuMateriasCursables();
void menuMateriasEnCurso();
void menuMateriasSiguienteCuatrimestre();
void menuMateriasFinalPendiente();
void menuMateriasAprobadas();

// Texto
void printMenuPrincipal();
void printEstadoMateria();
void printMateriasCorrelativas();
int confirmarCierreDelPrograma();

// Errores
void errorOpcionNoValida();

#endif