/********************************************
 *                                          *
 *      Exemplo de Atribuicao de Memoria    *
 *                                          *
 *      Versao: 1.0                         *
 *      Samuel Eleuterio 2008               *
 *                                          *
 ********************************************/

#include <stdio.h>
#include <stdlib.h>

int
main (int argc, char **argv)
{
  size_t   i1    ;
  int      v[50] ;
  char     s[80] ;

  int      *u    ;
  char     *r    ;
  double   *x    ;

  i1 = sizeof (char);
  printf ("Um 'char' ocupa:          %3ld bytes\n", i1);
  i1 = sizeof (short int);
  printf ("Um 'short int' ocupa:     %3ld bytes\n", i1);
  i1 = sizeof (int);
  printf ("Um 'int' ocupa:           %3ld bytes\n", i1);
  i1 = sizeof (long int);
  printf ("Um 'long int' ocupa:      %3ld bytes\n", i1);
  i1 = sizeof (long long int);
  printf ("Um 'long long int' ocupa: %3zu bytes\n", i1);
  i1 = sizeof (size_t);
  printf ("Um 'size_t' ocupa:        %3zu bytes\n", i1);
  i1 = sizeof (time_t);
  printf ("Um 'time_t' ocupa:        %3zu bytes\n", i1);

  i1 = sizeof (float);
  printf ("Um 'float' ocupa:         %3zu bytes\n", i1);
  i1 = sizeof (double);
  printf ("Um 'double' ocupa:        %3zu bytes\n", i1);
  i1 = sizeof (long double);
  printf ("Um 'long double' ocupa:   %3zu bytes\n", i1);

  i1 = sizeof (FILE);
  printf ("Um 'FILE' ocupa:          %3zu bytes\n", i1);

  i1 = sizeof (void *);
  printf ("Um ponteiro generico:     %3zu bytes     ('void *')\n", i1);

  i1 = sizeof (v);
  printf ("Espaço ocupado por 'v':   %3zu bytes     [ Definido como: 'int v[50];' ]\n", i1);

  i1 = sizeof (s);
  printf ("Espaço ocupado por 's':   %3zu bytes     [ Definido como: 'char s[80];' ]\n", i1);

  u = (int *) malloc (10 * sizeof (int));
  i1 = sizeof (u);
  printf ("Espaço ocupado por 'u':   %3zu bytes     [ Definido como: 'int *u;' ]\n", i1);

  x = (double *) malloc (10 * sizeof (double));
  i1 = sizeof (x);
  printf ("Espaço ocupado por 'x':   %3zu bytes     [ Definido como: 'double *x;' ]\n", i1);

  r = (char *) malloc (100 * sizeof (char));
  i1 = sizeof (r);
  printf ("Espaço ocupado por 'r':   %3zu bytes     [ Definido como: 'char *r;' ]\n", i1);

  return 0;
}
