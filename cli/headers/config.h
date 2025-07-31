#ifndef CONFIG_H_INCLUDED
#define CONFIG_H_INCLUDED
#include "types.h"

// Menu Principal
const int config_get_opcion_accion_array_length(void);
const opcion_accion_t *config_get_opcion_accion_array(void);

// Estado de la materia id
const int config_get_no_cursada_id(void);
const int config_get_en_curso_id(void);
const int config_get_siguiente_cuatrimestre_id(void);
const int config_get_final_pendiente_id(void);
const int config_get_aprobada_id(void);

// Estado de la materia string
const char *config_get_no_cursada_string(void);
const char *config_get_en_curso_string(void);
const char *config_get_siguiente_cuatrimestre_string(void);
const char *config_get_final_pendiente_string(void);
const char *config_get_aprobada_string(void);

#endif // CONFIG_H_INCLUDED
