/*************************************************
 *                                               *
 *  Ficheiro: UtilsVect.c                        *
 *                                               *
 *  Ficheiro onde vou guardar funcoes uteis      *
 *  sobre vectores                               *
 *                                               *
 *  Ver: Seixas - Cap. 7 (util.c e util.h)       *
 *                                               *
 *************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Utils.h"
#include "UtilsVect.h"

// Criacao de espaco para vector

void *
vec_new (unsigned int  num    ,         // Numero de elementos do vector
  	 size_t        nbytes )         // Numero de bytes por elemento.
{
  void *vect ;

  vect = calloc (num, nbytes);   //  malloc (num * nbytes) e poe tudo a '0'

  return vect;
}

// Calculo do modulo dum vector

double
vec_modulo (double        *vect ,
            unsigned int   num  )
{
  unsigned int  n1     ;
  double        modulo ;

  modulo = 0.;
  for (n1 = 0 ; n1 < num ; ++n1)
    modulo += QUAD(vect[n1]);     // modulo = modulo + QUAD(vect[n1]);

  modulo = sqrt(modulo);
  
  return modulo;
}

// Calculo do produto interno de dois vectores

double
vec_pint (double       *vect1 ,
          double       *vect2 ,
          unsigned int  num   )
{
  unsigned int  n1   ;
  double        pint ;

  pint = 0.;
  for (n1 = 0 ; n1 < num ; ++n1)
    pint += vect1[n1] * vect2[n1];

  return pint ;
}

// Criacao de espaco para matriz

void **
matx_new (unsigned int  ncols  ,         /* Numero de colunas da matriz    */
          unsigned int  nrows  ,         /* Numero de linhas da matriz     */
          size_t        nbytes )         /* Numero de bytes por elemento.  */
{
  unsigned int    n1            ;
  void          **matriz, *temp ;

  if (!(matriz = malloc (nrows * sizeof (void *))))
    return NULL;

  if (!(temp = calloc (nrows * ncols, nbytes)))
    {
      vec_free(matriz);
      return NULL;
    }

  for (n1 = 0 ; n1 < nrows ; ++n1)
    matriz[n1] = temp + n1 * ncols * nbytes;
  
  //for (n1 = 0 ; n1 < nrows ; ++n1)
  //  matriz[n1] = calloc (ncols, nbytes);
  
  return matriz;
}

// Calculo do traco de uma matriz

double
matx_trac (double       **matriz ,
           unsigned int   num    )
{
  unsigned int  n1 ;
  double        t1 ;

  t1 = 0.;
  for (n1 = 0 ; n1 < num ; ++n1)
    t1 += matriz[n1][n1];

  return t1;
}
