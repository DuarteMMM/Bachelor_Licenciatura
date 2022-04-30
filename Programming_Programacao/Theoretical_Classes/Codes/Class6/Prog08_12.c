/***********************************************
 *                                             *
 *      Meu Segundo Programa em C              *
 *      Para gerar números aleatórios          *
 *                                             *
 *      Versao: 1.1                            *
 *      Samuel Eleuterio 2008                  *
 *                                             *
 ***********************************************/

/*
   Nota:
     O resto da divisão de 'a' por 'b' em inteiros representa-se 
     por 'a % b' e lê-se como 'a' módulo 'b'.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int 
main ()
{
  int  i1, r1 ;

  srand (time (NULL));

  /* Gera numero inteiro aleatorio entre '0' e '5' */

  printf ("\nNumeros inteiros entre '0' e '5':\n");
  for (i1 = 0 ; i1 < 100 ; ++i1)
    {
      r1 = rand () % 6;
      printf ("%d     ", r1);
      if (i1 % 10 == 9)
	printf("\n");
    }
  
  if ((i1-1) % 10 != 9) 
    printf("\n");

  return 0;
}
