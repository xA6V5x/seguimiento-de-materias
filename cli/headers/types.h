#ifndef TYPES_H_INCLUDED
#define TYPES_H_INCLUDED

typedef struct
{
     int id;                 // ID único de la materia
     int nombreLength;       // Largo del nombre
     char *nombre;           // Nombre de la materia
     int correlativasLength; // Cantidad de correlativas
     int *correlativas;      // IDs de materias correlativas
} materia_archivo_t;

typedef struct
{
     int id;                 // ID único de la materia
     int nombreLength;       // Largo del nombre
     char *nombre;           // Nombre de la materia
     int correlativasLength; // Cantidad de correlativas
     int *correlativas;      // IDs de materias correlativas
     int estado;             // Estado de la materia (1: no cursada, 2: en curso, 3: siguiente cuatrimestre, 4: final pendiente, 5: aprobada)
} materia_t;

typedef struct
{
     int length;       // Cantidad de materias
     materia_t *array; // Array de materias
} materias_t;

typedef void (*ptr_funcion_void_t)(void);
typedef struct
{
     char *text;
     ptr_funcion_void_t funcion;
} opcion_accion_t;

typedef struct
{
     int length;             // Cantidad de opciones
     opcion_accion_t *array; // Array de opciones con acciones
} opciones_acciones_t;

typedef void (*ptr_funcion_filtro_t)(int estadoId, int *materiasLength, materia_t **materiasArray);

#endif // TYPES_H_INCLUDED
