/********************************************
 *                                          *
 *     Exemplo de UTF-8 e wide chars        *
 *                                          *
 *     Versao: 1.0                          *
 *     Samuel Eleuterio 2014                *
 *                                          *
 ********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <wchar.h>

#define LEN_STRING 256

int 
main (int argc, char **argv)
{
  int     len1, len2        ;
  char    str1[LEN_STRING]  ;
  wchar_t wstr1[LEN_STRING] ;

  if ((argc != 2) || (strlen (argv[1]) >= LEN_STRING - 1))
    {
      printf ("\n  Prog43_03 <string no maximo com %d caracteres>\n\n", LEN_STRING - 1);
      return 0;
    }

  setlocale(LC_CTYPE, "");

  len1 = strlen (argv[1]);
  printf ("\nComprimento de argv[1]: %d\n", len1);

  // Converte UTF-8 para wide char

  len2 = mbstowcs (wstr1, argv[1], LEN_STRING);

  printf ("\nResultado de converter UTF-8 em wide char:\n");
  printf ("  Número de caracteres: %d\n", len2);
  printf ("  wc1: %ls\n", wstr1);

  // Converte wide char para UTF-8

  len2 = wcstombs (str1, wstr1, LEN_STRING);

  printf ("\nResultado de converter wide char em UTF-8:\n");
  printf ("  Número de caracteres: %d\n", len2);
  printf ("  str1: %s\n", str1);
  printf ("\n");

  return 0;
}
