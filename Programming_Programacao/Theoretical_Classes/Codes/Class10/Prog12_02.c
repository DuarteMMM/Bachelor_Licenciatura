/********************************************
 *                                          *
 *      Exemplo de Atribuicao de Memoria    *
 *                                          *
 *      Versao: 1.0                         *
 *      Samuel Eleuterio 2008, 2012         *
 *                                          *
 ********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int
main (int argc, char **argv)
{
  int      i1, q1, q2 ;
  double  *vi         ;

  q1 = 4;  q2 = 8;

  srand (time (NULL));

  // Aloca espaco
  
  vi = (double *) malloc (q1 * sizeof (double));
  printf ("Pt: %p\n", vi);

  // Preenche o vector
  
  for (i1 = 0 ; i1 < q1 ; ++i1)
    vi[i1] = ((double) rand ()) / ((double) RAND_MAX);

  // Mostra o vector
  
  for (i1 = 0 ; i1 < q1 ; ++i1)
    printf ("  [%2d] - %lf       (%p)\n", i1, vi[i1], &vi[i1]);

  // Fazer o 'realloc' do espaco

  vi = (double *) realloc (vi, q2 * sizeof (double));
  printf ("\nPt: %p\n", vi);

  // Acrescenta os novos valores
  
  for (i1 = q1 ; i1 < q2 ; ++i1)
    vi[i1] = ((double) rand ()) / ((double) RAND_MAX);

  // Mostra o vector
  
  for (i1 = 0 ; i1 < q2 ; ++i1)
    printf ("  [%2d] - %lf       (%p)\n", i1, vi[i1], &vi[i1]);

  // Liberta a memoria alocada
  
  free (vi);

  return 0;
}
