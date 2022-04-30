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
#include <langinfo.h>
#include <wchar.h>

/*

  Os programas de C herdam as variáveis de ambiente quando começam. 
  No entanto, o programa não herda automaticamente a parte referente aos idiomas,
  porque a norma do C diz que um programa deve iniciar-se com o "locale" padrão 'C'.
  Para usar os "locales" específicos do ambiente deve chamar-se a função 'setlocale'
  da seguinte forma:

     setlocale (LC_ALL, "");    ou    setlocale (LC_CTYPE, "");

  Para aceder a cada elemento das categorias do 'locale', pode usar-se a função 

     char * nl_langinfo (nl_item item)

  Se se usar com CODESET, obter-se o conjunto de caracteres que se está a usar.

 */

int 
main (int argc, char **argv)
{
  int  i1, len, len1, len2, testa_utf8 ;

  if (argc != 2)
    {
      printf ("\n  Prog43_01 <string>\n\n");
      return 0;
    }

  // Testa se o programa se o "locale" actual está a usar o UTF-8

  testa_utf8 = 0;
  //printf ("(1) nl_langinfo(CODESET): %s\n", nl_langinfo(CODESET));
  if (!strcmp(nl_langinfo(CODESET), "UTF-8"))
    testa_utf8 = 1;

  printf ("\n");
  printf ("Antes de usar a função 'setlocale'\n");
  printf ("  Teste UTF-8: %d\n", testa_utf8);
  printf ("  MB_CUR_MAX: %ld\n", MB_CUR_MAX);
  printf ("\n");

  setlocale(LC_CTYPE, "");

  testa_utf8 = 0;
  //printf ("(2) nl_langinfo(CODESET): %s\n", nl_langinfo(CODESET));
  if (!strcmp(nl_langinfo(CODESET), "UTF-8"))
    testa_utf8 = 1;

  printf ("Depois de usar a função 'setlocale'\n");
  printf ("  Teste UTF-8: %d\n", testa_utf8);
  printf ("  MB_CUR_MAX: %ld\n", MB_CUR_MAX);

  len1 = strlen (argv[1]);
  printf ("\nComprimento de argv[1]: %d\n", len1);

  // Mostra os comprimentos associados a cada valor da string (formato UTF-8)

  i1 = len = 0;
  len2 = 0;
  while (argv[1][i1] != 0)
    {
      len = mblen (&argv[1][i1], MB_CUR_MAX);
      printf ("i1: %2d  ;  len: %2d  ;  len2: %2d  ;  s: %s\n", i1, len, len2, &argv[1][i1]);
      i1 += len;
      ++len2;
    }
  printf ("\nNúmero de caracteres: %d\n\n", len2);

  return 0;
}
