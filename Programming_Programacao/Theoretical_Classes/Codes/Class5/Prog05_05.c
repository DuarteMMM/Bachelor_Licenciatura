/***************************************
 *                                     *
 *  Programa para calcular as 20       *
 *  primeiras iteradas da funcao       *
 *  intervalo (Funcao Logistica)       *
 *                                     *
 *     x_n+1 = r * x_n * (1 - x_n)     *
 *                                     *
 *  Exemplo: r = 1.2                   *
 *                                     *
 *  Versao 1.5 (C)                     *
 *                                     *
 *  Autor: Joao Seixas 2004            *
 *  Alteracoes: Samuel Eleuterio 2008  *
 *                                     *
 ***************************************/

#include <stdio.h>

int 
main ()
{
  float x, x1, r ;
  int   i        ;
  int   s1       ;

  x = 0.75;

  printf ("Escreva, por favor, o valor do parametro 'r': ");
  s1 = scanf ("%f", &r);
  printf ("A funcao 'scanf' retornou o valor '%d' e leu o valor 'r': %f\n", s1, r);

  if (s1 != 1)
    {
      printf ("Erro na leitura\n");
      return 0;
    }
  
  // Ciclo de calculo

  i = 0;
  x1 = x;
  while (i <= 1000)
    {
      printf ("%4d: x = %.20f\n", i, x);
      x = r * x * (1. - x);
      if (x1 == x)
        break;
      x1 = x;
      ++i;
    }

  printf ("Valor do parametro 'r': %f\n", r);

  return 0;
}
