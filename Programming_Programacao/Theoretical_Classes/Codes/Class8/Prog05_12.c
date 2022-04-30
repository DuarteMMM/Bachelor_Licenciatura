/***************************************
 *                                     *
 *  Programa para calcular as 20       *
 *  primeiras iteradas da funcao       *
 *  intervalo (Funcao Logistica)       *
 *                                     *
 *     x_n+1 = r * x_n * (1 - x_n)     *
 *                                     *
 *  Versao 1.10 (C)                    *
 *                                     *
 *  Autor: Joao Seixas 2004            *
 *  Alteracoes: Samuel Eleuterio 2008  *
 *                                     *
 ***************************************/

#include <stdio.h>
#include <math.h>

void
troca_valores (double  *x1 , 
               double  *x2 )
{
  double y1 ;

  y1 = (*x1);
  (*x1) = (*x2);
  (*x2) = y1;
}

void
bubble_sort (double  *vx , 
             int      qt )
{
  int teste, i1 ;

  while (1)
    {
      teste = 0;
      for (i1 = 0 ; i1 < qt - 1 ; ++i1)
	{
          if (vx[i1] > vx[i1 + 1])
	    {
	      troca_valores (vx+i1, vx+i1+1);
	      teste = 1;
	    }
	}
      if (teste == 0)
	break;
    }
}

double
logistica (double  x ,
           double  r )
{
  x = r * x * (1.0 - x);

  return x;
}

int 
main ()
{
  double  x, x0, x_ref     ;
  double  r1, r2, dr, r    ;
  double  delta            ;
  int     i0, i1, i2, imax ;
  double  vx[128]          ;
  FILE   *fich1            ;

  x0 = 0.75;
  r1 = 2.5;
  r2 = 3.55;
  dr = 0.01;
  delta = 1.e-4;

  i0 = 4000;
  imax = 128;

  /* Abertura da File de Escrita */

  fich1 = fopen ("Prog05_12_Data.txt", "wt");
  if (fich1 == NULL)
    {
      printf ("ERR-Nao conseguiu abrir para escrita a file 'Prog05_12_Data.txt'\n");
      return (-1);
    }

  /* Ciclo de Calculo */

  for (r = r1 ; r <= r2 ; r += dr)
    {
      x = x0;
      for (i1 = 0 ; i1 <= i0 ; ++i1)
        x = logistica (x, r);

      x_ref = x;
      for (i1 = 0 ; i1 < imax ; ++i1)
	{
          x = logistica (x, r);
          vx[i1] = x;
          if (fabs (x - x_ref) < delta)
	    break;
	}
      ++i1;

      bubble_sort (vx, i1);
      printf ("r = %.2lf , Qt: %d  - ", r, i1);
      fprintf (fich1, "r = %.2lf , Qt: %d  - ", r, i1);
      for (i2 = 0 ; i2 < i1 ; ++i2)
	{
	  printf (" %lf", vx[i2]);
	  fprintf (fich1, " %lf", vx[i2]);
	}
      printf ("\n");
      fprintf (fich1, "\n");
    }

  /* Fecho da File */

  fclose (fich1);

  return 0;
}
