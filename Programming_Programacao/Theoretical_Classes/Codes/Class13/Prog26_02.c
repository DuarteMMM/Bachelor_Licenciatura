/********************************************
 *                                          *
 *      Funcao: Quadrado                    *
 *                                          *
 *      Versao: 1.1                         *
 *      Joao Seixas 2004                    *
 *      Samuel Eleuterio 2008               *
 *                                          *
 ********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QUADRADO(x) (x * x)

#define QUAD(x) ((x) * (x))

double faz_quadrado (double x);  /*  Prototipo  */

int
main ()
{
  int     i1, i2 ;
  double  x, y   ;

  printf ("\n");
  printf ("Escreva um numero: ");
  scanf ("%lf", &x);

  y = QUADRADO (x);
  printf ("  QUADRADO -     O seu quadrado, em 'double', e: '%lg'\n", y);

  y = QUAD (x);
  printf ("  QUAD -         O seu quadrado, em 'double', e: '%lg'\n", y);

  i1 = (int) x;
  i2 = QUADRADO (i1);
  printf ("  QUADRADO -     O seu quadrado, em 'int', e:    '%d'\n", i2);

  y = faz_quadrado (x);
  printf ("  faz_quadrado - O seu quadrado, em 'double', e: '%lg'\n", y);

  printf ("\nOutros testes:\n");

  printf ("  QUADRADO(5): %d\n", QUADRADO (5));
  printf ("  QUADRADO(2+3): %d\n", QUADRADO (2+3));
  
  printf ("\n  QUAD(5): %d\n", QUAD (5));
  printf ("  QUAD(2+3): %d\n", QUAD (2+3));

  printf ("\n");

  return 0;
}

double
faz_quadrado (double x)
{
  return x * x;
}
