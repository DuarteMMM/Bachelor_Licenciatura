/***********************************************************
 *                                                         *
 *      Meu Terceiro Programa em C                         *
 *      Converte polegadas em centimetros e faz um ciclo   *
 *                                                         *
 *      Versao: 1.5                                        *
 *      Samuel Eleuterio                                   *
 *                                                         *
 ***********************************************************/

#include <stdio.h>

int 
main ()
{
  float  p, c ;

  p = 1.;
  while (p < 10.1)
    {
      c = 2.54 * p;
      printf ("%5.2f in <--> %5.2f cm\n", p, c);
      p = p + 1.;
    }

  return 0;
}
