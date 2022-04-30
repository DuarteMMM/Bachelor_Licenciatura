/***************************************
 *                                     *
 *  Programa para calcular as 20       *
 *  primeiras iteradas da funcao       *
 *  intervalo (Funcao Logistica)       *
 *                                     *
 *     x_n+1 = r * x_n * (1 - x_n)     *
 *                                     *
 *  Versao 1.1 (C)                     *
 *                                     *
 *  Autor: Joao Seixas 2004            *
 *  Alteracoes: Samuel Eleuterio 2008  *
 *                                     *
 ***************************************/

#include <stdio.h>

int 
main ()
{
  // Declaracao das variaveis
  
  float x, r ;
  int   i    ;

  /* 
     Experimentar com os valores do parametro:
       r = 0.4, 0.6, 1.2, 2.97, 2.99, 3.2, 3.5, 3.56, 3.5699 
       (ponto de acumulacao de Feigenbaum) 
     E os pontos seguintes na zona (3.82 <= r <= 3.87)
       r = 3.8, 3.8235, 3.84
  */

  // Inicializacao das variaveis
  
  r = 0.4;
  x = 0.75;

  // Ciclo de calculo

  i = 0;
  while (i <= 20)
    {
      printf ("%d: x = %f\n", i, x);
      x = r * x * (1.0 - x);
      i = i + 1;
    }
  printf ("--------\n");
  printf ("Valor de 'r': %f\n", r);

  return 0;
}
