/*
    Programa demonstrando o uso de assert

    Autor: J. Seixas 2004
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <assert.h>

void
erro_divide_zero__assert (void)
{
  int x;

  printf ("*** 1/0. - Teste de 'assert.h' ***\n");

  printf ("\n  Resultado de 'assert': \n");
  for (x = -4 ; x < 4 ; ++x)
    {
      assert( x != 0 );
      printf("X: %d ; Inv:  %d \n", x, 16/x);
    }
}

int 
main(int argc, char **argv)
{
  printf ("\n");

  erro_divide_zero__assert ();
  printf ("\n");

  return 0;
}
