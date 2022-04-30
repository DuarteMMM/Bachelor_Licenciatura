/*
    Programa demonstrando o uso de manipulacao 
    de blocos de memoria
     
    Autor: Samuel Eleuterio, 2015
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int
main (int argc, char **argv)
{
  int    len1, len2, len3, len4, i1 ;
  char  *str1                       ;

  if (argc != 3)
    {
      printf ("\n  Prog42_03 <string1> <string2>\n\n");
      return 1;
    }

  len1 = strlen (argv[1]);
  len2 = strlen (argv[2]);
  len3 = (len1 > 2 ? 2 : len1 / 2);
  len4 = (len1 > len2 ? len2 : len1) + 1;

  printf ("\n");
  printf ("* argv[1]: '%s' (len1): %d\n", argv[1], len1);
  printf ("* argv[2]: '%s' (len2): %d\n", argv[2], len2);
  printf ("* len4 = (len1 > len2 ? len2 : len1) + 1: %d\n", len4);
  printf ("\n");

  str1 = (char *) malloc ((2 * len1 + len2 + 1) * sizeof (char));

  memcpy (str1, argv[1], len1 + 1);
  printf ("Resultado de 'memcpy (str1, argv[1], len1 + 1)':\n  '%s'\n\n", str1);

  memcpy (&str1[len1], argv[2], len2 + 1);
  printf ("Resultado de 'memcpy (&str1[len1], argv[2], len2 + 1)':\n  '%s'\n\n", str1);

  memcpy (str1, argv[1], len1 + 1);
  memcpy (&str1[len3], str1, len1 + 1);
  printf ("Resultado de 'memcpy (&str1[len3], str1, len1 + 1)':\n  '%s'\n\n", str1);

  memcpy (str1, argv[1], len1 + 1);
  memmove (&str1[len3], str1, len1 + 1);
  printf ("Resultado de 'memmove (&str1[len3], str1, len1 + 1)':\n  '%s'\n\n", str1);

  memset (str1, 55, len1);
  str1[len1] = 0;
  printf ("Resultado de 'memset (str1, 55, len1)' mais terminador:\n  '%s'\n\n", str1);

  memset (str1, 0, len1);
  str1[len1] = 0;
  printf ("Resultado de 'memset (str1, 0, len1)' mais terminador:\n  '%s'\n\n", str1);

  i1 = memcmp (argv[1], argv[2], len4);
  printf ("Resultado de 'memcmp (argv[1], argv[2], len4)': %d\n\n", i1);

  i1 = memcmp (argv[1], argv[2], 2);
  printf ("Resultado de 'memcmp (argv[1], argv[2], 2)': %d\n\n", i1);

  free (str1);

  return 0;
}
