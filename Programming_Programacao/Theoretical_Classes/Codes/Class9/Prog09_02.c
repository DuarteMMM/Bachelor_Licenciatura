/*****************************************************
 *                                                   *
 *      Strings e Vectores de Strings                *
 *                                                   *
 *      Versao: 1.1                                  *
 *      Samuel Eleuterio 2008                        *
 *                                                   *
 *****************************************************/

#include <stdio.h>

int
main ()
{
  char  texto1[80] = "Isto e um texto" ;
  char *texto2     = "Isto e outro texto" ;
  int   n1 ;

  printf ("\n");
  printf ("Texto1: '%s'\n", texto1);
  printf ("Texto2: '%s'\n", texto2);
  printf ("\n");

  printf ("'texto1':\n");
  printf ("  2a letra: %c (%3d)\n", texto1[1], texto1[1]);
  printf ("  8a letra: %c (%3d)\n", texto1[7], texto1[7]);

  printf ("\nImpressao feita caracter a caracter:\n");
  n1 = 0;
  while (texto1[n1] != 0)
    {
      printf ("%c", texto1[n1]);
      ++n1;
    }
  printf ("\n\n");
  
  return 0;
}
