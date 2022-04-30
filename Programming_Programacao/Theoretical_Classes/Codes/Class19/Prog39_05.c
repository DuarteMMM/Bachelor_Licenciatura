/****************************************
 *                                      *
 *     Criacao de Ficheiros             *
 *     Temporarios                      *
 *                                      *
 *     Versao: 1.0                      *
 *     Samuel Eleuterio 2014            *
 *                                      *
 ****************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int
main ()
{
  int      i1, i2    ;
  double   x1, x2[5] ;
  FILE    *f1        ;

  srand (time (NULL));

  f1 = tmpfile();

  printf ("\nEscrita:\n");
  for (i1 = 0 ; i1 < 5 ; ++i1)
    {
      x1 = 10. * ((double) rand()) / ((double) RAND_MAX) - 5;
      i2 = fwrite (&x1, sizeof(double), 1, f1);
      printf ("  (%d)   %+6.4lf\n", i2, x1);
    }

  rewind (f1);

  i2 = fread (x2, sizeof(double), 5, f1);
  printf ("\nA leitura após 'rewind' retornou: %d\n", i2);  
  
  printf ("\nLeitura:\n");
  for (i1 = 0 ; i1 < 5 ; ++i1)
    printf ("%10.4lf\n", x2[i1]);

  fclose (f1);

  return 0;
}
