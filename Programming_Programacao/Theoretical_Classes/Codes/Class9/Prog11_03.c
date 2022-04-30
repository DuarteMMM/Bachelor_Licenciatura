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
  printf ("\n  ***** 'String' desmasiado grande\n\n");
  exit (1);
}

int
main (int argc, char **argv)
{
  char   str3[LEN1] ;

  if (argc != 2)
    {
      printf ("\n     Prog11_03 <string>\n\n");
      return 0;
    }

  if (strlen (argv[1]) >= LEN1)
    string_grande();

  strcpy (str3, argv[1]);
  printf ("\nO resultado da copia da string '%s' e:\n", argv[1]);
  printf ("  '%s'\n\n", str3);
  
  return 0;
}
