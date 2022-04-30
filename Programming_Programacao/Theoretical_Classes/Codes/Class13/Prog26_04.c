/********************************************
 *                                          *
 *      Funcao: Quadrado                    *
 *                                          *
 *      Versao: 1.2                         *
 *      Joao Seixas 2004                    *
 *      Samuel Eleuterio 2008, 2014         *
 *                                          *
 ********************************************/

/*
   gcc -c Prog26_04.c
   gcc -c Prog26_04_func.c
   gcc -o Prog26_04 Prog26_04.o Prog26_04_func.o
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Prog26_04_func.h"

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

  return 0;
}
