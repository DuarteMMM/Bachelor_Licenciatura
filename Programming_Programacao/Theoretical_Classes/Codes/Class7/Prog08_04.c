/***********************************************
 *                                             *
 *      Meu Segundo Programa em C              *
 *      Para gerar números aleatórios (double) *
 *                                             *
 *      Prog08_03 mais vectores                *
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
  double  r1[10] ;

  srand (time (NULL));

  for (i1 = 0 ; i1 < 10 ; ++i1)
    r1[i1] = 2. * ((double) rand ()) / ((double) RAND_MAX) - 1.;

  printf ("10 aleatorios no intervalo [-1, 1]\n");
  for (i1 = 0 ; i1 < 10 ; ++i1)
    printf ("%3d - %12.8lf\n", i1, r1[i1]);

  return 0;
}
