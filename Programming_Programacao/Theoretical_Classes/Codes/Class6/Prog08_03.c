/***********************************************
 *                                             *
 *      Meu Segundo Programa em C              *
 *      Para gerar números aleatórios (double) *
 *                                             *
 *      Versao: 1.2                            *
 *      Samuel Eleuterio 2008                  *
 *                                             *
 ***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int 
main ()
{
  int     i1 ;
  double  r1 ;

  srand (time (NULL));

  printf ("Aleatorios no intervalo [-1, 1]\n");
  for (i1 = 0 ; i1 < 10 ; ++i1)
    {
      r1 = ((double) rand ()) / ((double) RAND_MAX);        // [ 0, 1]
      r1 = 2. * r1;                                         // [ 0, 2]
      r1 = r1 - 1.;                                         // [-1, 1]
      // r1 = 2. * ((double) rand ()) / ((double) RAND_MAX) - 1.;
      printf ("%3d - %12.8lf\n", i1, r1);
    }

  return 0;
}
