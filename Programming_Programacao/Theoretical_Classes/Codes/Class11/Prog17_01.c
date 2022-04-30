/*****************************************************
 *                                                   *
 *      Exemplo de Estrutura - 'typedef'             *
 *                                                   *
 *      Versao: 1.0                                  *
 *      Samuel Eleuterio 2008                        *
 *                                                   *
 *****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct 
{
  double r ;
  double i ;
} complexo ;


void
help (int status)
{
  printf ("\n  Prog17_01 <parte_real> <parte_imaginaria>\n\n");
  exit (status) ;
}

double
cpx_modulo (complexo *z1)
{
  double  x1 ;

  x1 = sqrt (z1->r * z1->r + z1->i * z1->i);

  return x1 ;
} 

int
main (int argc, char **argv)
{
  double    x1 ;
  complexo  z1 ;

  if (argc != 3)
    help (-1);

  if (sscanf (argv[1], "%lf", &z1.r) != 1)
    help (-1);

  if (sscanf (argv[2], "%lf", &z1.i) != 1)
    help (-1);

  if (z1.i < 0)
    printf ("  z1 = %lf - %lf i\n", z1.r, -z1.i);
  else
    printf ("  z1 = %lf + %lf i\n", z1.r, z1.i);

  x1 = cpx_modulo (&z1);
  printf ("  |z1|   = %lf\n", x1);

  return 0;
}
