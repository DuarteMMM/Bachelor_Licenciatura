/*****************************************************
 *                                                   *
 *      Strings e Vectores de Strings - 'main'       *
 *                                                   *
 *      Versao: 1.0                                  *
 *      Samuel Eleuterio 2008                        *
 *                                                   *
 *****************************************************/

#include <stdio.h>


int
main (int argc, char **argv)
{
  int i1 ;

  printf ("\n");
  printf ("A funcao 'main' tem %d argumentos:\n", argc);

  for (i1 = 0 ; i1 < argc ; ++i1)
    printf ("  [%d] - '%s'\n", i1, argv[i1]);

  printf ("\n");

  return 0;
}
