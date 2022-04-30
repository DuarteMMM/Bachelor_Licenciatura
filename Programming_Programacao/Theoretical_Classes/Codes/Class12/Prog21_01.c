/*****************************************************
 *                                                   *
 *      Exemplo de constantes                        *
 *                                                   *
 *      Versao: 1.0                                  *
 *      Samuel Eleuterio 2008                        *
 *                                                   *
 *****************************************************/

#include <stdio.h>

#define NUM 15

int 
main (int argc, char **argv)
{
  int               i1, i3   ;
  const int         i2 = 14  ;
  const int        *x1 = &i1 ;
  int *const        x2 = &i1 ;
  const int *const  x3 = &i1 ;
  
  /* Descomentar as linhas seguintes e tentar compilar o programa */

  i3 = 7;
  i1 = i2;

  /* Nao pode fazer-se: */
  //  ++i2;    
  //  i2 = i3; 
  //  NUM = i3;
  //  (*x1) = 21;

  /* Caso NUM: */

  printf ("NUM: %d\n", NUM);
  //NUM = i3;

  /* Caso i2: */

  printf ("i2:  %d\n", i2);
  // i2 = i3;

  /* Caso x1:     const int *x1 = &i1          */

  printf ("x1-A:  %p   %d\n", x1, *x1);
  x1 = &i3;
  printf ("x1-B:  %p    %d\n", x1, *x1);
  //  (*x1) = 21;

  /* Caso x2:     int *const x2 = &i1          */

  printf ("x2-A:  %p - %d\n", x2, *x2);
  //  x2 = &i3;
  (*x2) = 34;
  printf ("x2-B:  %p - %d\n", x2, *x2);

  /* Caso x3:     const int *const  x3 = &i1   */

  printf ("x3:    %p\n", x3);
  //  x3 = &i3;
  //  (*x3) = 34;

  return 0;
}
