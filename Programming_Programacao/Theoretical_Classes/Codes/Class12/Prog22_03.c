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
mostra_logicas (void)
{
  int  i1, i2, i3, i4 ;

  i1 = 20;
  i2 = 30;
  i3 = 7;
  i4 = i1;

  printf ("\n*** Operacoes Lógicas ***\n\n");
  printf ("  %2d == %2d  ==>  %2d\n", i1, i4, i1 == i4);
  printf ("  %2d == %2d  ==>  %2d\n", i1, i2, i1 == i2);
  printf ("!(%2d == %2d) ==>  %2d\n", i1, i2, !(i1 == i2));
  printf ("  %2d >  %2d  ==>  %2d\n", i1, i4, i1 > i4);
  printf ("  %2d >= %2d  ==>  %2d\n", i1, i4, i1 >= i4);
  printf ("  %2d <  %2d  ==>  %2d\n", i1, i4, i1 < i4);
  printf ("  %2d <= %2d  ==>  %2d\n", i1, i4, i1 <= i4);
  printf ("------------\n");
  printf ("  (%2d == %2d) && (%2d < %2d)  ==>  %2d\n", 
          i1, i4, i1, i2, (i1 == i4) && (i1 < i2));
  printf ("  (%2d == %2d) && (%2d > %2d)  ==>  %2d\n", 
          i1, i4, i1, i2, (i1 == i4) && (i1 > i2));
  printf ("  (%2d == %2d) || (%2d > %2d)  ==>  %2d\n", 
          i1, i4, i1, i2, (i1 == i4) || (i1 > i2));
  printf ("!((%2d == %2d) || (%2d > %2d)) ==>  %2d\n", 
          i1, i4, i1, i2, !((i1 == i4) || (i1 > i2)));
  printf ("------------\n");
  printf ("  x = (%d >= 0 ? %d : %d)  ==>  %2d\n",
          i3, i1, i2, (i3 >= 0 ? i1 : i2));
  printf ("  x = (%d <  0 ? %d : %d)  ==>  %2d\n",
          i3, i1, i2, (i3 < 0 ? i1 : i2));
}

int 
main (int argc, char **argv)
{
  mostra_logicas ();
  printf ("\n");

  return 0;
}
