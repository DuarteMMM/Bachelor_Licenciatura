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
mostra_binarias (void)
{
  int  i1, i2, i3 ;
  double  x1, x2  ;

  i1 = 20; i2 = 3; 
  printf ("\n*** Operacoes Binarias - Inteiros ***\n\n");
  printf ("  %d + %d = %2d\n",  i1, i2, i1 + i2);
  printf ("  %d - %d = %2d\n",  i1, i2, i1 - i2);
  printf ("  %d * %d = %2d\n",  i1, i2, i1 * i2);
  printf ("  %d / %d = %2d\n",  i1, i2, i1 / i2);
  printf ("  %d %% %d = %2d\n", i1, i2, i1 % i2);

  x1 = 20.; x2 = 3.; 
  printf ("\n*** Operacoes Binarias (double) ***\n\n");
  printf ("  %4.1lf + %3.1lf = %8.5lf\n",  x1, x2, x1 + x2);
  printf ("  %4.1lf - %3.1lf = %8.5lf\n",  x1, x2, x1 - x2);
  printf ("  %4.1lf * %3.1lf = %8.5lf\n",  x1, x2, x1 * x2);
  printf ("  %4.1lf / %3.1lf = %8.5lf\n",  x1, x2, x1 / x2);

  i3 = 20; i2 = 3; 
  printf ("\n*** Operacoes Binarias (int) - Operadores Compostos ***\n\n");
  i1 = i3; i1 += i2;                              //  i1 = i1 + i2;
  printf ("  %2d += %d ==> %3d\n",  i3, i2, i1);
  i1 = i3; i1 -= i2;
  printf ("  %2d -= %d ==> %3d\n",  i3, i2, i1);
  i1 = i3;  i1 *= i2;
  printf ("  %2d *= %d ==> %3d\n",  i3, i2, i1);
  i1 = i3; i1 /= i2;
  printf ("  %2d /= %d ==> %3d\n",  i3, i2, i1);
  i1 = i3; i1 %= i2;
  printf ("  %2d %%= %d ==> %3d\n",  i3, i2, i1);
}

void
mostra_ternarias (void)
{
  int  i1, i2 ;

  i1 = 7;
  i2 = -5;

  printf ("\n*** Operacoes Ternarias ***\n\n");

  printf ("i1 = %d\n", i1);
  printf ("  i1 = (i1 >= 0 ? i1 : -i1)  ==>  %2d\n",
	  (i1 >= 0 ? i1 : -i1));
  
  printf ("i2 = %d\n", i2);
  printf ("  i2 = (i2 >= 0 ? i2 : -i2)  ==>  %2d\n",
          (i2 >= 0 ? i2 : -i2));
}

int 
main (int argc, char **argv)
{
  mostra_binarias ();
  mostra_ternarias ();
  printf ("\n");

  return 0;
}
