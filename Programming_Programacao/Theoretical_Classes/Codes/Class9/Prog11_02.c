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
  if (argc != 2)
    {
      printf ("\n     Prog11_02 <string>\n\n");
      return 0;
    }

  printf ("\nA string '%s' tem de comprimento: %ld\n\n", argv[1], strlen(argv[1]));
      
  printf ("Nota Extra:\n");
  printf ("  Se escrevermos '&argv[1][1]' com '%%s' tem-se: '%s'\n", &argv[1][1]);
  printf ("  E se escrevermos 'argv[1][1]' com '%cc' tem-se: '%c'\n\n", 37, argv[1][1]);

  return 0;
}
