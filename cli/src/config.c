#include <stdio.h>
#include <stdlib.h>
#include "../headers/config.h"

static const char MAX_STRING[] = "max";
static const char MIN_STRING[] = "min";
static const char *horarios[3] = {"1000", "1400", "1800"};

const char *config_get_max_string(void)
{
    return MAX_STRING;
}

const char *config_get_min_string(void)
{
    return MIN_STRING;
}

const char **config_get_horarios_array(void)
{
    return horarios;
}
