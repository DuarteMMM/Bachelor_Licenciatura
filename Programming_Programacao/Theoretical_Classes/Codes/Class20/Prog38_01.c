/********************************************
 *                                          *
 *     Exemplos de <time.h>                 *
 *                                          *
 *     Versao: 1.0                          *
 *     Samuel Eleuterio 2008                *
 *                                          *
 ********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <locale.h>

#define QT_LOOP 100000000

int
main (int argc, char **argv)
{
  long int       i1, i2          ;
  double         d1, x1, x2      ;
  clock_t        ct1, ct2        ;

  printf ("\n");
  printf ("CLOCKS_PER_SEC: %ld\n", CLOCKS_PER_SEC);
  printf ("\n");

  // Calculo do 'sin'
  
  x1 = 0.4;
  ct1 = clock ();
  for (i1 = 0 ; i1 < QT_LOOP ; ++i1)
    x1 = sin (x1);
  ct2 = clock ();

  d1 = ((double) (ct2 - ct1)) / ((double) CLOCKS_PER_SEC);
  printf ("Tempo de CPU para calcular %d vezes 'sin(x)': %lg s  (ct2: %ld, ct1: %ld)\n", 
          QT_LOOP, d1, ct2, ct1);  

  // Soma de inteiros
  
  i2 = 73;
  ct1 = clock ();
  for (i1 = 0 ; i1 < QT_LOOP ; ++i1)
    i2 = (i2 + 1159);
  ct2 = clock ();

  d1 = ((double) (ct2 - ct1)) / ((double) CLOCKS_PER_SEC);
  printf ("Tempo de CPU para calcular %d vezes 'i+1159': %lg s  (ct2: %ld, ct1: %ld)\n", 
          QT_LOOP, d1, ct2, ct1);  

  // Operacao de doubles com 'fmod'
  
  x2 = 73;
  ct1 = clock ();
  for (i1 = 0 ; i1 < QT_LOOP ; ++i1)
    x2 = fmod (x2 * 1.4, 1.);
  ct2 = clock ();

  d1 = ((double) (ct2 - ct1)) / ((double) CLOCKS_PER_SEC);
  printf ("Tempo de CPU para calcular %d vezes 'fmod (x*1.4,1.0)': %lg s\n", QT_LOOP, d1);  

  // Soma '1' em inteiros
  
  i2 = 0;
  ct1 = clock ();
  for (i1 = 0 ; i1 < QT_LOOP ; ++i1)
    i2 = i2 + 1;
  ct2 = clock ();

  d1 = ((double) (ct2 - ct1)) / ((double) CLOCKS_PER_SEC);
  printf ("Tempo de CPU para calcular %d vezes 'i2 = i2 + 1' (em 'int'): %lg s\n", QT_LOOP, d1);  

  // Soma '1.' em double
  
  x1 = 0.;
  ct1 = clock ();
  for (i1 = 0 ; i1 < QT_LOOP ; ++i1)
    x1 = x1 + 1.;
  ct2 = clock ();

  d1 = ((double) (ct2 - ct1)) / ((double) CLOCKS_PER_SEC);
  printf ("Tempo de CPU para calcular %d vezes 'x1 = x1 + 1' (em 'double'): %lg s\n", QT_LOOP, d1);  

  // Multiplicacao em doubles
  
  x1 = 1.;
  ct1 = clock ();
  for (i1 = 0 ; i1 < QT_LOOP ; ++i1)
    x1 = x1 * 1.00000001;
  ct2 = clock ();
  //printf ("x1: %.15lf\n", x1);

  d1 = ((double) (ct2 - ct1)) / ((double) CLOCKS_PER_SEC);
  printf ("Tempo de CPU para calcular %d vezes 'x1 = x1 * 1.00000001' (em 'double'): %lg s\n", QT_LOOP, d1);  

  printf ("\n");

  return 1;
}
