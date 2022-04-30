#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int
main (int argc, char **argv)
{
  int i1, i2 ;

  if (argc != 1)
    {
      printf ("\n   Prog25_04_Inicio: O programa nao pode ter argumentos!\n");
      return 100;
    }

  srand (time (NULL));

  i1 = rand();
  i2 = i1 % 2;

  if (i2 == 0)
    {
      printf ("\n   Prog25_04_Inicio: O resultado foi: %d - logo e' PAR !\n\n", i1);
      i2 = 2;
    }
  else
    printf ("\n   Prog25_04_Inicio: O resultado foi: %d - logo e' IMPAR !\n\n", i1);

  return i2;
}
