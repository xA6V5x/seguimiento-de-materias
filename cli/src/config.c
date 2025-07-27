#include <stdio.h>
#include <stdlib.h>
#include "../headers/config.h"

static const int NO_CURSADA_ID = 1;
static const int EN_CURSO_ID = 2;
static const int SIGUIENTE_CUATRIMESTRE_ID = 3;
static const int FINAL_PENDIENTE_ID = 4;
static const int APROBADA_ID = 5;

static const char NO_CURSADA_STRING[] = "No cursada";
static const char EN_CURSO_STRING[] = "En curso";
static const char SIGUIENTE_CUATRIMESTRE_STRING[] = "Siguiente cuatrimestre";
static const char FINAL_PENDIENTE_STRING[] = "Final pendiente";
static const char APROBADA_STRING[] = "Aprobada";

// IDs
const int config_get_no_cursada_id(void)
{
    return NO_CURSADA_ID;
}

const int config_get_en_curso_id(void)
{
    return EN_CURSO_ID;
}

const int config_get_siguiente_cuatrimestre_id(void)
{
    return SIGUIENTE_CUATRIMESTRE_ID;
}

const int config_get_final_pendiente_id(void)
{
    return FINAL_PENDIENTE_ID;
}

const int config_get_aprobada_id(void)
{
    return APROBADA_ID;
}

// Strings
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