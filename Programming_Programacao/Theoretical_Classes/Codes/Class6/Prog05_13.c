/***************************************
 *                                     *
 *  Programa para calcular as 20       *
 *  primeiras iteradas da funcao       *
 *  intervalo (Funcao Logistica)       *
 *                                     *
 *     x_n+1 = r * x_n * (1 - x_n)     *
 *                                     *
 *  Versao 1.7 (C)                     *
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
  double  x, x0, x_ref      ;
  double  r1, r2, dr, r     ;
  double  delta             ;
  int     i1, nCiclos, imax ;
  FILE   *f1                ;

  x0 = 0.75;          // Valor inicial em 'x'
  r1 = 0;             // Valor inicial em 'r'
  r2 = 4.0;           // Valor final em 'r'
  dr = 0.01;          // Incremento em 'r'
  delta = 1.e-6;      // Valor maximo para considerar igual

  nCiclos = 4000;     // Numero de ciclo ate estabilizar
  imax = 128;         // Numero maximo de valores por 'r'

  //r1 = 2.5;
  //r2 = 3.55;

  // Abertura do ficheiro de escrita

  f1 = fopen("Prog05_13.txt", "wt");
  if (f1 == NULL)
    {
      printf ("Não conseguiu abrir o ficheiro 'Prog05_13.txt'\n");
      return 1;
    }

  // Ciclo de calculo

  for (r = r1 ; r <= r2 ; r += dr)
    {
      // Valor inicial

      x = x0;

      // Ciclo para estabilizar os valores (fazer i0 vezes)

      for (i1 = 0 ; i1 <= nCiclos ; ++i1)
	x = r * x * (1. - x);
      
      // Tomar um valor para valor de comparacao

      x_ref = x;

      // Ciclo para testar a repeticao ('imax' - limite dos testes)

      for (i1 = 0 ; i1 < imax ; ++i1)
	{
          x = r * x * (1. - x);
          fprintf (f1, "%lf %lf\n", r, x);
          if (fabs (x - x_ref) < delta)
	    break;
	}
    }

  fclose(f1);
  
  return 0;
}
