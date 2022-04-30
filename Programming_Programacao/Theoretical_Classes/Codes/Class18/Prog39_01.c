/********************************************
 *                                          *
 *     Exemplos de <stdio.h>                *
 *                                          *
 *     Versao: 1.0                          *
 *     Samuel Eleuterio 2008                *
 *                                          *
 ********************************************/

#include <stdio.h>

int
main (int argc, char **argv)
{
  printf ("BUFSIZ: %d\n", BUFSIZ);
  printf ("EOF: %d\n", EOF);
  printf ("NULL (%%p): %p\n", NULL);
  printf ("FILENAME_MAX: %d\n", FILENAME_MAX);
  printf ("FOPEN_MAX: %d\n", FOPEN_MAX);
  printf ("L_tmpnam: %d\n", L_tmpnam);
  printf ("TMP_MAX: %d\n", TMP_MAX);

  return 0;
}
