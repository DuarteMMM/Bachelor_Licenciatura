/*****************************************************
 *                                                   *
 *      Exemplos de Operacoes                        *
 *                                                   *
 *      Versao: 1.0                                  *
 *      Samuel Eleuterio 2008                        *
 *                                                   *
 *****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
mostra_unarias (void)
{
  int  i1, i2 ;
  double  x1, x2 ;

  i1 = i2 = 20;
  printf ("\n*** Operacoes Unarias - Inteiros *** (i1 = %d)\n\n", i1);
  i1 = i2; printf ("  ++i1 = %d\n", ++i1);
  i1 = i2; printf ("  i1++ = %d\n", i1++);
  i1 = i2; printf ("  --i1 = %d\n", --i1);
  i1 = i2; printf ("  i1-- = %d\n", i1--);

  x2 = 20.5;
  printf ("\n*** Operacoes Unarias - Reais (double) *** (i1 = %lf)\n\n", x2);
  x1 = x2; printf ("  ++x1 = %3.1lf\n", ++x1);
  x1 = x2; printf ("  x1++ = %3.1lf\n", x1++);
  x1 = x2; printf ("  --x1 = %3.1lf\n", --x1);
  x1 = x2; printf ("  x1-- = %3.1lf\n", x1--);
}

int 
main (int argc, char **argv)
{
  mostra_unarias ();
  printf ("\n");

  return 0;
}
