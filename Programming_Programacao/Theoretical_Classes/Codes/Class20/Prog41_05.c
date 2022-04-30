/********************************************
 *                                          *
 *     Exemplos de <stdlib.h>               *
 *                                          *
 *     Versao: 1.0                          *
 *     Samuel Eleuterio 2016                *
 *                                          *
 ********************************************/

#include <stdio.h>
#include <stdlib.h>

int
main (int argc, char **argv)
{
  int   i1, i2 ;
  div_t result ;

  i1 = 59;
  i2 = 7;

  result = div(i1, i2);

  printf ("\nResultado de 'div (%d, %d)':\n", i1, i2);
  printf ("  result.quot: %d\n  result.rem: %d\n\n", result.quot, result.rem);

  return EXIT_SUCCESS;
}
