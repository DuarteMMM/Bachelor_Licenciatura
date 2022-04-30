/***********************************************
 *                                             *
 *      Meu Segundo Programa em C              *
 *      Converte polegadas em centimetros      *
 *                                             *
 *      Versao: 1.1                            *
 *      Samuel Eleuterio                       *
 *                                             *
 ***********************************************/

#include <stdio.h>

int main ()
{
  float  p, c ;

  p = 4.;
  c = 2.54 * p;

  printf ("Resultado: %f in ---> %f cm\n", p, c);

  return 0;
}
