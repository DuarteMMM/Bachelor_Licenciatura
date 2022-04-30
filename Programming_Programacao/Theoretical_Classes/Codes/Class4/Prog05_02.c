/***************************************
 *                                     *
 *  Programa para calcular as 20       *
 *  primeiras iteradas da funcao       *
 *  intervalo (Funcao Logistica)       *
 *                                     *
 *     x_n+1 = r * x_n * (1 - x_n)     *
 *                                     *
 *  Versao 1.2 (C)                     *
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

  float x, r  ;
  int   i, s1 ;

  /* 
     Experimentar com os valores do parametro:
       r = 0.4, 0.6, 1.2, 2.97, 2.99, 3.2, 3.5, 3.56, 3.5699 
       (ponto de acumulacao de Feigenbaum) 
     E os pontos seguintes na zona (3.82 <= r <= 3.87)
       r = 3.8, 3.8235, 3.84
  */

  // Inicializacao das variaveis
  
  x = 0.75;

  printf ("Escreva, por favor, o valor do parametro r: ");
  s1 = scanf ("%f", &r);
  printf ("A funcao 'scanf' retornou '%d' e leu 'r': %f\n", s1, r);
  
  // Testes de leitura correcta
  
  if (s1 != 1)
    {
      printf ("Falhou a leitura de 'r'\n");
      return 1;
    }

  // Ciclo de calculo

  i = 0;
  while (i <= 200)
    {
      printf ("%4d: x = %f\n", i++, x);
      x = r * x * (1.0 - x);
    }
  
  printf ("--------\n");
  printf ("Valor de 'r': %f\n", r);

  return 0;
}
