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
  int   i1, q1, q2, cria_outro ;
  int  *vi, *vi2               ;
  

  if (argc != 2)
    {
      printf ("\n");
      printf ("    Prog12_02 <valor>\n");
      printf ("      Valor: 0 - Fazer 'realloc' depois do 'malloc'\n");
      printf ("             1 - fazer novo 'malloc' antes do 'realloc'\n\n");
      return 0;
    }

  if (strcmp (argv[1], "0") == 0)
    cria_outro = 0;
  else if (strcmp (argv[1], "1") == 0)
    cria_outro = 1;
  else
    {
      printf ("\n***** Argumento invalido\n");
      return 0;
    }

  q1 = 4;
  q2 = 8;

  srand (time (NULL));

  // Aloca espaco
  
  vi = (int *) malloc (q1 * sizeof (int));
  printf ("Pt: %p\n", vi);

  // Preenche o vector
  
  for (i1 = 0 ; i1 < q1 ; ++i1)
    vi[i1] = rand ();

  // Mostra o vector
  
  for (i1 = 0 ; i1 < q1 ; ++i1)
    printf ("  [%2d] - %10d       (%p)\n", i1, vi[i1], &vi[i1]);

  // Fazer nova atribuicao de memoria (pode variar...):

  if (cria_outro == 1)
    {
      vi2 = (int *) malloc (q1 * sizeof (int));
      printf ("\nPt: %p - A seguir ao Fim: %p\n", vi2, vi2+q1+1);
    }
  
  // Fazer o 'realloc' do espaco

  vi = (int *) realloc (vi, q2 * sizeof (int));
  printf ("\nPt: %p\n", vi);

  // Acrescenta os novos valores
  
  for (i1 = q1 ; i1 < q2 ; ++i1)
    vi[i1] = rand ();

  // Mostra o vector
  
  for (i1 = 0 ; i1 < q2 ; ++i1)
    printf ("  [%2d] - %10d       (%p)\n", i1, vi[i1], &vi[i1]);

  // Liberta a memoria alocada
  
  free (vi);

  return 0;
}
