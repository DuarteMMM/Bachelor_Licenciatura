/********************************************
 *                                          *
 *      Funcao: Quadrado                    *
 *                                          *
 *      Versao: 1.0                         *
 *      Joao Seixas 2004                    *
 *      Samuel Eleuterio 2008               *
 *                                          *
 ********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double faz_quadrado (double x);  /*  Prototipo  */


int
main ()
{
  double x, y ;

  printf ("Escreva um numero: ");
  if (scanf ("%lf", &x) != 1)
    {
      printf ("\n   ***** Valor inválido. Tente outra vez ...\n\n");
      return 1;
    }

  y = faz_quadrado (x);
  printf ("O seu quadrado e: '%lg'\n", y);

  return 0;
}

double faz_quadrado (double x)
{
  return x * x;
}
