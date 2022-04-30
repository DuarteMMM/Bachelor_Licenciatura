/*****************************************
 *                                       *
 *      Exemplo de Ponteiros             *
 *                                       *
 *      Versao: 1.0                      *
 *      Samuel Eleuterio 2008            *
 *                                       *
 *****************************************/

#include <stdio.h>
#include <stdlib.h>


int
main (int argc, char **argv)
{
  double x, y, z    ;
  double *p, *q, *r ;

  x = 1.0;
  y = 2.0;
  z = 3.0;

  p = &x;
  q = &y;
  r = &z;

  printf ("\n");
  printf ("  x:      %lf       ; y:      %lf       ; z:      %lf\n", x, y, z);
  printf ("  &x:     %p ; &y:     %p ; &z:     %p\n",        &x, &y, &z);
  printf ("  p:      %p ; q:      %p ; r:      %p\n",        p, q, r);
  printf ("  *p:     %lf       ; *q:     %lf       ; *r:     %lf\n", *p, *q, *r);
  printf ("  *(&x):  %lf       ; *(&y):  %lf       ; *(&z):  %lf\n", *(&x), *(&y), *(&z));
  printf ("\n");

  return 0;
}
