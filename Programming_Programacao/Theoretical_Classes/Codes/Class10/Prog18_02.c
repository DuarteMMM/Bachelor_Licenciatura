/*****************************************
 *                                       *
 *      Exemplo de Ponteiros             *
 *                                       *
 *      Versao: 1.0                      *
 *      Samuel Eleuterio 2017            *
 *                                       *
 *****************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int
main ()
{
  int  n1, qt, *p ;

  srand(time(NULL));

  qt = 5;

  p = (int *) malloc (qt * sizeof (int));

  printf ("\n");
  for (n1 = 0 ; n1 < qt ; ++n1)
    p[n1] = rand() % 10;

  for (n1 = 0 ; n1 < qt ; ++n1)
    printf ("%5d", p[n1]);
  printf ("\n\n");

  printf ("Novo valor para 'p[1]': ");
  scanf ("%d", &p[1]);

  for (n1 = 0 ; n1 < qt ; ++n1)
    printf ("%5d", p[n1]);
  printf ("\n\n");
  
  printf ("Novo valor para 'p[3]': ");
  scanf ("%d", p+3);

  for (n1 = 0 ; n1 < qt ; ++n1)
    printf ("%5d", *(p+n1));
  printf ("\n\n");

  free (p);
  
  return 0;
}
