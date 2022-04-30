/***************************************
 *                                     *
 *  Programa para calcular as 20       *
 *  primeiras iteradas da funcao       *
 *  intervalo (Funcao Logistica)       *
 *                                     *
 *     x_n+1 = r * x_n * (1 - x_n)     *
 *                                     *
 *  Versao 1.4 (C)                     *
 *                                     *
 *  Autor: Joao Seixas 2004            *
 *  Alteracoes: Samuel Eleuterio 2008  *
 *                                     *
 ***************************************/

#include <stdio.h>

int 
main ()
{
  float x, x0, r ;
  int   i, n, s1 ;

  /* 
     Experimentar com os valores do parametro:
       r = 0.4, 0.6, 1.2, 2.97, 2.99, 3.2, 3.5, 3.56, 
            3.5699 (ponto de acumulacao de Feigenbaum) 
     E os pontos seguintes na zona (3.82 <= r <= 3.87)
       r = 3.8, 3.8235, 3.84
  */

  x = 0.75;
  r = 0.4;

  printf ("Escreva os valores do parametro, da condicao inicial e numero de iterações ('r x0 n'): ");
  s1 = scanf ("%f %f %d", &r, &x0, &n);

  // Testes de leitura correcta
  
  printf ("A funcao 'scanf' retornou o valor '%d' e leu os valores\n", s1);
  printf ("   r = %f ; x0 = %f ; n = %d\n", r, x0, n);

  if (s1 != 3)
    {
      printf ("Erro na leitura\n");
      return 0;
    }

  /* Ciclo de calculo */

  i = 0;
  x = x0;
  while (i <= n)
    {
      printf ("%d: x = %f\n", i, x);
      x = r * x * (1. - x);
      ++i;
    }

  printf ("--------\nOs valores dados foram: r = %f ; x0 = %f ; n = %d\n", r, x0, n);

  return 0;
}
