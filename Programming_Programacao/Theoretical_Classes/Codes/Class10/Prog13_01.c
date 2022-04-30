/*****************************************************
 *                                                   *
 *      Exemplos de Enumerate (enum)                 *
 *                                                   *
 *      Versao: 1.0                                  *
 *      Samuel Eleuterio 2008                        *
 *                                                   *
 *****************************************************/

#include <stdio.h>
#include <stdlib.h>

enum cor {
/*  0 */  branco,
/*  1 */  preto,
/*  1 */  negro = 1,
/*  2 */  cinzento,
/*  3 */  amarelo,
/*  4 */  vermelho,
/*  4 */  encarnado = vermelho,
/*  5 */  violeta 
} ;


int
main (int argc, char **argv)
{
  int       i1   ;
  enum cor  cor1 ;

  printf ("branco: %d\n", branco);
  printf ("preto: %d\n", preto);
  printf ("negro: %d\n", negro);
  printf ("cinzento: %d\n", cinzento);
  printf ("amarelo: %d\n", amarelo);
  printf ("vermelho: %d\n", vermelho);
  printf ("encarnado: %d\n", encarnado);
  printf ("violeta: %d\n", violeta);

  printf ("\n");
  cor1 = vermelho;
  printf ("  cor1(vermelho): %d\n", cor1);

  cor1 = (enum cor) 2;
  printf ("  cor1(2): %d\n", cor1);

  i1 = (int) violeta;
  printf ("  i1(violeta): %d\n", i1);
  printf ("\n");

  return 0;
}
