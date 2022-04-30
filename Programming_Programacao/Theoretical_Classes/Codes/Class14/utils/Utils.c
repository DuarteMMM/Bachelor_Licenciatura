/*************************************************
 *                                               *
 *  Ficheiro: Utils.c                            *
 *                                               *
 *  Ficheiro onde vou guardar coisas uteis que   *
 *  podem ser usadas em programas futuros        *
 *                                               *
 *************************************************/

#include <stdlib.h>
#include <time.h>

#include "Utils.h"

/* 'tsrand' usa como 'seed' o tempo actual */

void
tsrand (void)
{
  srand (time (NULL));
}

/* 'xrand' gera um double aleatorio no intervalo [0,max] */

double
xrand (double  max)
{
  return max * ((double) rand ()) / ((double) RAND_MAX);
}

float
fxrand (float  max)
{
  return max * ((float) rand ()) / ((float) RAND_MAX);
}
