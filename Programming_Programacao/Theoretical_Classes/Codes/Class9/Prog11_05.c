/*****************************************************
 *                                                   *
 *      Strings e Funcoes                            *
 *                                                   *
 *      Versao: 1.0                                  *
 *      Samuel Eleuterio 2008                        *
 *                                                   *
 *****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main (int argc, char **argv)
{
  if (argc != 3)
    {
      printf ("\n     Prog11_05 <string> <string>\n\n");
      return 0;
    }

  printf ("\nComparacao das duas strings. Resultado: '%d'.\n", 
	  strcmp (argv[1], argv[2]));
  printf ("  [str1]: '%s'\n", argv[1]);
  printf ("  [str2]: '%s'\n\n", argv[2]);

  return 0;
}
