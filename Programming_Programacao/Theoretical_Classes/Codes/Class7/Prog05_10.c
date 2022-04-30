/***************************************
 *                                     *
 *  Programa para calcular as 20       *
 *  primeiras iteradas da funcao       *
 *  intervalo (Funcao Logistica)       *
 *                                     *
 *     x_n+1 = r * x_n * (1 - x_n)     *
 *                                     *
 *  Versao 1.9 (C)                     *
 *                                     *
 *  Autor: Joao Seixas 2004            *
 *  Alteracoes: Samuel Eleuterio 2008  *
 *                                     *
 ***************************************/

#include <stdio.h>
#include <math.h>

int 
main ()
{
  double  x, x0, x_ref     ;
  double  r1, r2, dr, r    ;
  double  delta            ;
  int     nCiclos, i1, i2  ;
  double  vx[128]          ;

  x0 = 0.75;
  r1 = 2.5;
  r2 = 3.55;
  dr = 0.01;
  delta = 1.e-6;

  nCiclos = 4000;

  /* Ciclo de calculo */

  for (r = r1 ; r <= r2 ; r += dr)
    {
      x = x0;
      
      for (i1 = 0 ; i1 <= nCiclos ; ++i1)
        x = r * x * (1.0 - x);
      
      x_ref = x;

      for (i1 = 0 ; i1 < 128 ; ++i1)
	{
          x = r * x * (1.0 - x);
          vx[i1] = x;
          printf ("%lf     %lf\n", r, vx[i1]);
          if (fabs (x - x_ref) < delta)
	    break;
	}
      ++i1;

      printf ("r = %4.2lf , Qt:%3d  -", r, i1);
      for (i2 = 0 ; i2 < i1 ; ++i2)
        printf ("  vx[%d]: %8.6lf", i2, vx[i2]);
      printf ("\n\n");
    }

  return 0;
}
