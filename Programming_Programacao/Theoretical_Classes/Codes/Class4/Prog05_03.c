/***************************************
 *                                     *
 *  Programa para calcular as 20       *
 *  primeiras iteradas da funcao       *
 *  intervalo (Funcao Logistica)       *
 *                                     *
 *     x_n+1 = r * x_n * (1 - x_n)     *
 *                                     *
 *  Versao 1.3 (C)                     *
 *                                     *
 *  Autor: Joao Seixas 2004            *
 *  Alteracoes: Samuel Eleuterio 2008  *
 *                                     *
 ***************************************/

#include <stdio.h>

int 
main ()
{
  float x, r, x0 ;
  int   i = 0    ;
  int   s1, s2   ;

  /* 
     Experimentar com os valores do parametro:
       r = 0.4, 0.6, 1.2, 2.97, 2.99, 3.2, 3.5, 3.56, 3.5699 
            (ponto de acumulacao de Feigenbaum) 
     E os pontos seguintes na zona (3.82 <= r <= 3.87)
       r = 3.8, 3.8235, 3.84
  */

  //x = 0.75;
  //r = 1.2;

  printf ("Escreva, por favor, o valor do parametro 'r': ");
  s1 = scanf ("%f", &r);

  printf ("Escreva, por favor, a condicao inicial de 'x': ");
  s2 = scanf ("%f", &x0);

  // Testes de leitura correcta
  
  printf ("A funcao 'scanf' retornou o valor '%d' e leu o valor 'r': %f\n", s1, r);
  printf ("A funcao 'scanf' retornou o valor '%d' e leu o valor 'x': %f\n", s2, x0);

  if (s1 + s2 != 2)
    {
      printf ("Erro na leitura\n");
      return 0;
    }

  // Ciclo de calculo

  x = x0;
  while (i <= 200)
    {
      printf ("%d: x = %f\n", i++, x);
      x = r * x * (1.0 - x);
    }
  
  printf ("-------\nOs valores dados foram: r = %f ; x0: %f\n", r, x0);

  return 0;
}
