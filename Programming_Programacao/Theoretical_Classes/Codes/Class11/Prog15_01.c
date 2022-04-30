/*****************************************************
 *                                                   *
 *      Exemplo de Uniao                             *
 *                                                   *
 *      Versao: 1.0                                  *
 *      J.Seixas, Samuel Eleuterio 2008              *
 *                                                   *
 *****************************************************/

#include <stdio.h>
#include <stdlib.h>

union numeros
{
  int    i ;
  float  x ;
};

int
main (int argc, char **argv)
{
  union numeros v1, v2, v3 ;

  v1.i = 4;
  v2.i = 6;
  v3.i = v1.i * v2.i;

  printf ("\n");
  printf ("Uso como inteiros:\n");
  printf (" v3.i = v1.i * v2.i  ==> %d = %d * %d\n", v3.i, v1.i, v2.i);

  printf ("Mostrando enquanto 'float' (uso incorrecto):\n");
  printf ("  v3.x = v1.x * v2.x  ==> %f = %f * %f\n", v3.x, v1.x, v2.x);

  v1.x = 4.;
  v2.x = 6;
  v3.x = v1.x * v2.x;

  printf ("\n");
  printf ("Uso como float:\n");
  printf (" v3.x = v1.x * v2.x  ==> %f = %f * %f\n", v3.x, v1.x, v2.x);

  printf ("Mostrando enquanto 'int' (uso incorrecto):\n");
  printf ("  v3.i = v1.i * v2.i  ==> %d = %d * %d\n", v3.i, v1.i, v2.i);
  printf ("\n");

  printf ("sizeof (float): %ld\n", sizeof (float));
  printf ("sizeof (int): %ld\n", sizeof (int));
  printf ("sizeof (union numeros): %ld\n", sizeof (union numeros));
  printf ("\n");

  return 1;
}
