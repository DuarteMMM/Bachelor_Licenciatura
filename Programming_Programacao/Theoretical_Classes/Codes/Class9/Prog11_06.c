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
help (int  status)
{
  printf ("\n");
  printf ("Prog11_06 <opcoes> <str1> <str2>\n");
  printf ("  Opcoes:\n");
  printf ("    len    : 'strlen' da o comprimento de uma string (So str1)\n");
  printf ("    cpy    : 'strcpy' copia a 'str1' (So str1)\n");
  printf ("    cat    : 'strcat' junta 'str2' no final da 'str1'\n");
  printf ("    cmp    : 'strcmp' compara 'str1' com 'str2'\n");
  printf ("    help   : mostra esta informacao\n");
  printf ("\n");
  exit (status);
}

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

  if ((argc == 1) || (strcmp (argv[1], "help") == 0))
    help (0);

  if (strcmp (argv[1], "len") == 0)
    {
      if (argc != 3)
        help (-1);

      printf ("\nA string '%s' tem de comprimento: %ld\n\n", argv[2], strlen (argv[2]));
      
      printf ("Nota Extra:\n");
      printf ("  Se escrevermos '&argv[2][1]' com '%%s' tem-se: '%s'\n", &argv[2][1]);
      printf ("  E se escrevermos 'argv[2][1]' com '%cc' tem-se: '%c'\n\n", 37, argv[2][1]);
    }

  else if (strcmp (argv[1], "cpy") == 0)
    {
      if (argc != 3)
        help (-1);
      if (strlen (argv[2]) >= LEN1)
	string_grande();

      strcpy (str3, argv[2]);
      printf ("\nO resultado da copia da string '%s' e:\n", argv[2]);
      printf ("  '%s'\n\n", str3);
    }

  else if (strcmp (argv[1], "cat") == 0)
    {
      if (argc != 4)
        help (-1);
      if ((strlen (argv[2]) + strlen (argv[3])) >= LEN1)
	string_grande();

      strcpy (str3, argv[2]);
      strcat (str3, argv[3]);
      printf ("\nO resultado de acrescentar '%s' no final de '%s' da:\n", 
              argv[3], argv[2]);
      printf ("  '%s'\n\n", str3);
    }

  else if (strcmp (argv[1], "cmp") == 0)
    {
      if (argc != 4)
        help (-1);
      printf ("\nComparacao das duas strings. Resultado: '%d'.\n", 
              strcmp (argv[2], argv[3]));
      printf ("  [str1]: '%s'\n", argv[2]);
      printf ("  [str2]: '%s'\n\n", argv[3]);
    }

  else
    {
      printf ("\nOpcao invalida: '%s'\n", argv[1]);
      printf ("Tente novamente.\n");
      help (-1);
    }

  return 0;
}
