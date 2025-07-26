#include <stdio.h>
#include <stdlib.h>
#include "../headers/config.h"

static const char NO_CURSADA_STRING[] = "No cursada";
static const char EN_CURSO_STRING[] = "En curso";
static const char SIGUIENTE_CUATRIMESTRE_STRING[] = "Siguiente cuatrimestre";
static const char FINAL_PENDIENTE_STRING[] = "Final pendiente";
static const char APROBADA_STRING[] = "Aprobada";

const char *config_get_no_cursada_string(void)
{
    return NO_CURSADA_STRING;
}

const char *config_get_en_curso_string(void)
{
    return EN_CURSO_STRING;
}

const char *config_get_siguiente_cuatrimestre_string(void)
{
    return SIGUIENTE_CUATRIMESTRE_STRING;
}

const char *config_get_final_pendiente_string(void)
{
    return FINAL_PENDIENTE_STRING;
}

const char *config_get_aprobada_string(void)
{
    return APROBADA_STRING;
}