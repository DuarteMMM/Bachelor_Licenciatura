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

#define LEN1  2000

void
string_grande (void)
{
  printf ("\n  ***** 'Strings' desmasiado grandes\n\n");
  exit (1);
}

int
main (int argc, char **argv)
{
  char   str3[LEN1] ;

  if (argc != 3)
    {
      printf ("\n     Prog11_04 <string> <string>\n\n");
      return 0;
    }

  if (strlen(argv[1]) + strlen(argv[2]) >= LEN1)
    string_grande();

  strcpy (str3, argv[1]);
  strcat (str3, argv[2]);
  printf ("\nO resultado de acrescentar '%s' no final de '%s' da:\n", 
	  argv[2], argv[1]);
  printf ("  '%s'\n\n", str3);

  return 0;
}
