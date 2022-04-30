/*****************************************************
 *                                                   *
 *      Strings e Vectores de Strings                *
 *                                                   *
 *      Versao: 1.1                                  *
 *      Samuel Eleuterio 2008                        *
 *                                                   *
 *****************************************************/

#include <stdio.h>

void
escreve_vector_vch (char v[][16] ,
                    int  n       )
{
  int i1 ;

  printf ("\n");
  printf ("Funcao 'escreve_vector_vch'.\n");
  for (i1 = 0 ; i1 < n ; ++i1)
    printf ("  vector[%d]: %p - '%s'\n", i1, v[i1], v[i1]);
  printf ("\n");
}

int
main ()
{
  int i1 ;
  char vch[5][16] = {"Isto e um texto", "que serve para", "exemplificar",
		     "como e o vetor", "de strings"};

  printf ("\nPonteiro para vch: %p\n", vch);
  for (i1 = 0 ; i1 < 5 ; ++i1)
    printf ("  vch[%d]: %p - '%s'\n", i1, vch[i1], vch[i1]);

  escreve_vector_vch (vch, 5);

  return 1;
}
