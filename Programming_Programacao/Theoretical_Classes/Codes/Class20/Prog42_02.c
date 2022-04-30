/**************************************
 *                                    *
 *     Exemplos de <string.h>         *
 *     Exemplos retirados de 'libc'   *
 *                                    *
 *     Versao: 1.0                    *
 *     Samuel Eleuterio 2008          *
 *                                    *
 **************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

int
main ()
{
  char       *cp, *cp2 ;
  const char  string[] = "Isto sao palavras. Elas vao-se separando por: caracteres especiais, etc.";
  const char  delimiters[] = " .,;:!-" ;

  printf ("\n***** 'strtok' *****\n\n");
  cp = (char *) malloc (strlen(string) + 1);
  strcpy(cp, string);
  
  printf("  A aplicacao sucessiva de strtok a '%s':\n", cp);
  printf("  Com os separadores: '%s'\n", delimiters);

  printf("    ==> %s\n", strtok (cp, delimiters));
  while((cp2 = strtok (NULL, delimiters)))
    printf("    ==> %s\n", cp2);

  printf("\n");
  free(cp);

  return 0;
}
     
