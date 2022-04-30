/***********************************************
 *                                             *
 *      Programa de explificação de            *
 *      incrementos de variáveis               *
 *                                             *
 *      Versao: 1.0                            *
 *      Samuel Eleutério                       *
 *                                             *
 ***********************************************/

#include <stdio.h>

int 
main ()
{
  int inicial, i ;

  inicial = 20;
  printf ("\n");
  printf ("Valor inicial do 'i': %d\n\n", inicial);
  printf ("Resultados\n");
  i = inicial;   printf ("  '++i'     ==> %2d", ++i); printf ("    ( Depois: %d )\n", i);
  i = inicial;   printf ("  'i++'     ==> %2d", i++); printf ("    ( Depois: %d )\n", i);

  i = inicial;   printf ("  '--i'     ==> %2d", --i); printf ("    ( Depois: %d )\n", i);
  i = inicial;   printf ("  'i--'     ==> %2d", i--); printf ("    ( Depois: %d )\n", i);

  i = inicial;   printf ("  'i += 5'  ==> %2d\n", i += 5);
  i = inicial;   printf ("  'i -= 5'  ==> %2d\n", i -= 5);
  i = inicial;   printf ("  'i *= 4'  ==> %2d\n", i *= 4);
  i = inicial;   printf ("  'i /= 4'  ==> %2d\n", i /= 4);
  printf ("\n");

  float x = 5.4;
  printf ("x++: %f\n", x++);
  x=5.4;
  printf ("++x: %f\n", ++x);
  
  return 0;
}
