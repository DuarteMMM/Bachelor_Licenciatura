/*****************************************************
 *                                                   *
 *      Exemplo de Estrutura - Bit Fields            *
 *                                                   *
 *      Versao: 1.0                                  *
 *      J.Seixas, Samuel Eleuterio 2008              *
 *                                                   *
 *****************************************************/

#include <stdio.h>
#include <stdlib.h>

struct quadrado
{
  int          cor      : 16 ;
  int          diagonal : 15 ;
  unsigned int pintado  :  1 ;
};

int
main (int argc, char **argv)
{
  int             i1                     ;
  struct quadrado fig1 = {16000, 800, 1} ;

  printf ("\n**** Valores de fig1:\n");
  printf ("  sizeof(struct quadrado): %ld\n", sizeof (struct quadrado));

  printf ("  pintado: %d\n", fig1.pintado);
  printf ("  cor: %d\n", fig1.cor);
  printf ("  diagonal: %d\n", fig1.diagonal);

  printf ("\n");
  for (i1 = 0 ; i1 < 5 ; ++i1)
    {
      printf ("  [%d] pintado: %2d ; cor: %d ; diagonal: %d\n", 
              i1, fig1.pintado, fig1.cor, fig1.diagonal);
      ++fig1.pintado;
    }
  printf ("\n");

  return 0;
}
