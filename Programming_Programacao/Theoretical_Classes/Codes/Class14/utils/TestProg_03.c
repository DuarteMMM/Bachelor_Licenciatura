/*  
   TestProg_03.c  

   Para compilar:
      gcc -c Utils.c
      gcc -c UtilsVect.c
      gcc -c TestProg_03.c 
      gcc -o TestProg_03 TestProg_03.o Utils.o UtilsVect.o -lm

   ou mais simplesmente
      gcc -o TestProg_03 TestProg_03.c Utils.c UtilsVect.c -lm
*/

#include <stdio.h>
#include <stdlib.h>

#include "Utils.h"
#include "UtilsVect.h"

#define QUANTOS  5

int
main (int argc, char **argv)
{
  long int  i1            ;
  double    limite, xx    ;
  double   *vect1, *vect2 ;

  if ((argc != 2) || (sscanf (argv[1], "%lg", &limite) != 1))
    {
      printf ("\n  TesteProg1 <Valor>     (Aleatarios no intervalo [0,Valor])\n\n");
      exit (-1);
    }

  tsrand ();
  vect1 = (double *) vec_new (QUANTOS, sizeof (double));
  vect2 = (double *) vec_new (QUANTOS, sizeof (double));

  for (i1 = 0 ; i1 < QUANTOS ; ++i1)
    {
      vect1[i1] = xrand (limite);
      vect2[i1] = xrand (limite);
    }

  printf ("\n*** Primeiro vector:\n");
  for (i1 = 0 ; i1 < QUANTOS ; ++i1)
    printf ("  %.3f  ;", vect1[i1]);

  xx = vec_modulo (vect1, QUANTOS);
  printf ("  ===>  |v1| = %lg\n", xx);

  printf ("\n*** Segundo vector:\n");
  for (i1 = 0 ; i1 < QUANTOS ; ++i1)
    printf ("  %.3f  ;", vect2[i1]);

  xx = vec_modulo (vect2, QUANTOS);
  printf ("  ===>  |v2| = %lg\n", xx);

  xx = vec_pint (vect1, vect2, QUANTOS);
  printf ("\n*** O seu produto interno e': %lg\n\n", xx);

  vec_free (vect1);
  vec_free (vect2);

  return 0;
}
