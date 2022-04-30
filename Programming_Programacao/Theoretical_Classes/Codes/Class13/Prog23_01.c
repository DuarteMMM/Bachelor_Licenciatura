/********************************************
 *                                          *
 *      Exemplo de Instrucoes Condicionais  *
 *        ( Condicao ? Se_V : Se_F )        *
 *                                          *
 *      Versao: 1.0                         *
 *      Samuel Eleuterio 2008               *
 *                                          *
 ********************************************/

#include <stdio.h>
#include <stdlib.h>

int
main ()
{
  double x1, y1, x2, y2 ;

  x1 = 2.;
  y1 = -3;

  x2 = (x1 >= 0 ? x1 : -x1);
  y2 = (y1 >= 0 ? y1 : -y1);

  printf ("\n");
  printf ("  x1: %6.3lf ------> x2: %6.3lf         [  x2 = (x1 >= 0 ? x1 : -x1)  ]\n", x1, x2);
  printf ("  y1: %6.3lf ------> y2: %6.3lf         [  y2 = (y1 >= 0 ? y1 : -y1)  ]\n", y1, y2);
  printf ("\n");

  return 0;
}
