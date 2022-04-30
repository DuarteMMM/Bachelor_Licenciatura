/***********************************************
 *                                             *
 *      Meu Segundo Programa em C              *
 *      Para gerar números aleatórios          *
 *                                             *
 *      Versao: 1.1                            *
 *      Samuel Eleuterio 2008                  *
 *                                             *
 ***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int 
main ()
{
  int  i1, r1 ;

  printf ("time(NULL): %ld\n", time (NULL));

  srand (time (NULL));

  for (i1 = 0 ; i1 < 10 ; ++i1)
    {
      r1 = rand ();
      printf ("%3d - %10d\n", i1, r1);
    }

  return 0;
}
