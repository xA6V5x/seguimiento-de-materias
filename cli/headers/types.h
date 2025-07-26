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

#endif // TYPES_H_INCLUDED
