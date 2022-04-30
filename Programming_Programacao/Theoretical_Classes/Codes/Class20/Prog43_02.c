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
  int     len1, len2, len3   ;
  int     i1, i2, i3         ;
  char    str1[LEN_STRING]   ;
  wchar_t wstr1[LEN_STRING]  ;

  if ((argc != 2) || (strlen (argv[1]) >= 255))
    {
      printf ("\n  Prog43_02 <string no maximo com 255 caracteres>\n\n");
      return 0;
    }

  setlocale(LC_CTYPE, "");

  len1 = strlen (argv[1]);
  printf ("\nComprimento de argv[1]: %d\n", len1);

  // Converte UTF-8 para wide char

  i1 = i2 = 0;
  len2 = 0;
  while (argv[1][i1] != 0)
    {
      //i2 = mblen (&argv[1][i1], MB_CUR_MAX);

      i2 = mbtowc (&wstr1[len2], &argv[1][i1], MB_CUR_MAX);
      printf ("i1: %2d  ;  i2: %2d  ;  wc: %4d - %lc (%c) ;  len2: %2d  ;  s: %s\n", 
	      i1, i2, wstr1[len2], wstr1[len2], wstr1[len2], len2, &argv[1][i1]);
      i1 += i2;
      ++len2;
    }
  wstr1[len2] = 0;

  printf ("\nResultado de converter UTF-8 em wide char:\n");
  printf ("  Número de caracteres: %d\n", len2);
  printf ("  wc1: %ls\n\n", wstr1);

  // Converte wide char para UTF-8

  i1 = 0;
  len3 = 0;
  while (wstr1[i1] != 0)
    {
      i3 = wctomb (&str1[len3], wstr1[i1]);
      printf ("i1: %2d  ;  i3: %2d  ;  s: %ls\n", i1, i3, &wstr1[i1]);
      len3 += i3;
      ++i1;
    }
  str1[len3] = 0;

  printf ("\nResultado de converter wide char em UTF-8:\n");
  printf ("  Número de caracteres: %d\n", len3);
  printf ("  str1: %s\n", str1);
  printf ("\n");

  return 0;
}
