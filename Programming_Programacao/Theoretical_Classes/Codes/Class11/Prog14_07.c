/*****************************************************
 *                                                   *
 *      Exemplo de Estrutura - offsetof              *
 *                                                   *
 *      Versao: 1.0                                  *
 *      Samuel Eleuterio 2015                        *
 *                                                   *
 *****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct particula
{
  char               nome[20]   ;
  int                carga      ;
  int                paridade   ;
  double             spin       ;
  double             massa      ;
  double             vida_media ;
  struct particula  *anti       ;
} elementar;

int
main (int argc, char **argv)
{
  char    *ch1, *delta ;
  int      pos         ;
  double  *pt_massa    ;

  elementar fermiao[3] = {
    {"electrao", -1, 1, 0.5, 0.51, 1.0e40, NULL},
    {"positrao", 1, 1, 0.5, 0.511, 1.0e40, NULL},
    {"protao", 1, 1, 0.5, 938, 1.0e40, NULL}
  };

  printf ("\n");
  printf ("Tamanho de 'elementar': %lu\n", sizeof (elementar));
  
  pos = offsetof (elementar, massa);
  //pos = offsetof (struct particula, massa);
  printf ("  Pos(massa): %d  ;  Valor: %lg\n\n", pos, fermiao[0].massa);

  printf ("Ponteiro para electrao (&fermiao[0]):      %p\n", &fermiao[0]);
  printf ("Ponteiro para a massa (&fermiao[0].massa): %p\n", &fermiao[0].massa);
  
  delta = (char *) ((char *) (&fermiao[0].massa) - ((char *) (&fermiao[0])));
  printf ("  Diferenca: %p (hexa), %lu (decimal)\n\n", delta, (unsigned long int) (delta));

  ch1 = ((char *) &fermiao[0]);
  pt_massa = (double *) (ch1 + pos);

  (*pt_massa) = 0.511;
  printf ("Massa do electrao alterada: %lg\n\n", fermiao[0].massa);

  return 0;
}
