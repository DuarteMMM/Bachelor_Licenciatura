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
  char ch1 ;

  ch1 = '?';
  printf ("\n***** 'strchr' *****\n\n");
  printf ("  O resultado de 'strchr (\"hello, world\", 'l');' é:\n");
  printf ("     ==> '%s'\n",  strchr ("hello, world", 'l'));
  printf ("  e de O resultado de 'strchr (\"hello, world\", '?');' é:\n");
  printf ("     ==> '%s'\n",  strchr ("hello, world", ch1));

  printf ("\n***** 'strrchr' *****\n\n");
  printf ("  O resultado de 'strrchr (\"hello, world\", 'l');' é:\n");
  printf ("     ==> '%s'\n",  strrchr ("hello, world", 'l'));

  printf ("\n***** 'strspn' *****\n\n");
  printf ("  O resultado de 'strspn (\"hello, world\", \"abcdefghijklmnopqrstuvwxyz\");' é:\n");
  printf ("    ==> %ld\n", strspn ("hello, world", "abcdefghijklmnopqrstuvwxyz"));
   printf ("  O resultado de 'strspn (\"Hello, world\", \"abcdefghijklmnopqrstuvwxyz\");' é:\n");
  printf ("    ==> %ld\n", strspn ("Hello, world", "abcdefghijklmnopqrstuvwxyz"));
             
  printf ("\n***** 'strcspn' *****\n\n");
  printf ("  O resultado de 'strcspn (\"hello, world\", \" \\t\\n,.;!?\");' é:\n");
  printf ("    ==> %ld\n", strcspn ("hello, world", " \t\n,.;!?"));

  printf ("\n***** 'strpbrk' *****\n\n");
  printf ("  O resultado de 'strpbrk (\"hello, world\", \" \\t\\n,.;!?\");' é:\n");
  printf ("    ==> '%s'\n", strpbrk ("hello, world", " \t\n,.;!?"));

  printf ("\n***** 'strstr' *****\n\n");
  printf ("  O resultado de 'strstr (\"hello, world\", \"l\");' é:\n");
  printf ("    ==> '%s'\n", strstr ("hello, world", "l"));
  printf ("  O resultado de 'strstr (\"hello, world\", \"wo\");' é:\n");
  printf ("    ==> '%s'\n", strstr ("hello, world", "wo"));

  return 0;
}
     
