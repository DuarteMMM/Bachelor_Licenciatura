
/***************************************
 *                                     *
 *  Programa para calcular as 20       *
 *  primeiras iteradas da funcao       *
 *  intervalo x_n+1= 0.1*x_n           *
 *  - Lei de Malthus                   *
 *                                     *
 *        Versao 1.1 (C)               *
 *                                     *
 *  Autor: Joao Seixas 2004            *
 *  Alteracoes: Samuel Eleuterio 2008  *
 *                                     *
 ***************************************/

#include <stdio.h> 

int
main ()
{
/* Declaracao das variaveis */

  float x ;
  int   i ;

/* Inicializacao das variaveis */
  
  i = 0;
  x = .7;
  
/* Ciclo das iteradas */

  while (i <= 20) 
    {
      printf ("Iter %d *** x = %.20f\n", i, x); 
      x = 0.1 * x;
      i = i + 1;
    }

  return 0;
}          
