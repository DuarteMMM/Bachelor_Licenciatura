/*****************************************************
 *                                                   *
 *      Strings e Vectores de Strings                *
 *                                                   *
 *      Versao: 1.2                                  *
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

void
escreve_vector_vpch (char **v ,    /* Nota tambem se pode escrever '*v[]' */
                     int  n   )
{
  int i1 ;

  printf ("\n");
  printf ("Funcao 'escreve_vector_vpch' - Posicao de v: %p\n", v);
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

  char ch0[16] = "Isto e um texto";
  //char *ch0a = "Isto e um texto";
  char ch1[15] = "que serve para";
  char ch2[13] = "exemplificar";
  char ch3[15] = "como e o vetor";
  char ch4[12] = "de strings";

  char *vpch[5] ;

  vpch[0] = ch0;
  vpch[1] = ch1;
  vpch[2] = ch2;
  vpch[3] = ch3;
  vpch[4] = ch4;

  printf ("\nPonteiro para vch: %p\n", vch);
  for (i1 = 0 ; i1 < 5 ; ++i1)
    printf ("  vch[%d]: %p \n", i1, vch[i1]);
  escreve_vector_vch (vch, 5);

  printf ("Ponteiro para os 'ch'\n");
  printf ("  ch0: %p - '%s'\n", ch0, ch0);
  printf ("  ch1: %p - '%s'\n", ch1, ch1);
  printf ("  ch2: %p - '%s'\n", ch2, ch2);
  printf ("  ch3: %p - '%s'\n", ch3, ch3);
  printf ("  ch4: %p - '%s'\n", ch4, ch4);

  printf ("\nPonteiro para vpch: %p\n", vpch);
  for (i1 = 0 ; i1 < 5 ; ++i1)
    printf ("  vpch[%d]: %p  %p\n", i1, &vpch[i1], vpch[i1]);

  escreve_vector_vpch (vpch, 5);

  return 0;
}
