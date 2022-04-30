/********************************************
 *                                          *
 *     Exemplos de <stdlib.h>               *
 *                                          *
 *     Versao: 1.0                          *
 *     Samuel Eleuterio 2008                *
 *                                          *
 ********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int
main (int argc, char **argv)
{
  printf ("\n");
  printf ("  EXIT_SUCCESS: %d\n", EXIT_SUCCESS);
  printf ("  EXIT_FAILURE: %d\n", EXIT_FAILURE);
  printf ("\n");
  printf ("  RAND_MAX:     %d\n", RAND_MAX);
  printf ("\n");

  printf ("Antes de executar a função 'setlocale':\n");
  printf ("  MB_CUR_MAX:   %ld\n", MB_CUR_MAX);
  printf ("\n");

  setlocale (LC_CTYPE, "");

  printf ("Depois de executar a função 'setlocale':\n");
  printf ("  MB_CUR_MAX:   %ld\n", MB_CUR_MAX);
  printf ("\n");

  return EXIT_SUCCESS;
}
