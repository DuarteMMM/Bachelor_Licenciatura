/***************************************
 *                                     *
 *  Programa para calcular as 20       *
 *  primeiras iteradas da funcao       *
 *  intervalo x_n+1= 0.1*x_n            *
 *  - Lei de Malthus                   *
 *                                     *
 *        Versao 1.3 (C)               *
 *                                     *
 *  Autor: Joao Seixas 2004            *
 *  Alteracoes: Samuel Eleuterio 2008  *
 *                                     *
 ***************************************/

#include <stdio.h> 

int main ()
{
/* Declaracao e inicializacao das variaveis */

  float x = .7;
  int   i = 0;

/* Ciclo das iteradas */
  
  printf ("Iter %3d: x = %f\n", i, x); 
  while (i < 20)
    printf ("Iter %3d: x = %f\n", ++i, x *= 0.1); 

  return 0;
}          
