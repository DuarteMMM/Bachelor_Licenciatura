/*****************************************************
 *                                                   *
 *      Exemplos de Estruturas                       *
 *                                                   *
 *      Versao: 1.0                                  *
 *      J.Seixas, Samuel Eleuterio 2008              *
 *                                                   *
 *****************************************************/

#include <stdio.h>
#include <stdlib.h>

struct particula 
{
  char               nome[20]   ;
  int                carga      ;
  int                paridade   ;
  float              spin       ;
  double             massa      ;
  double             vida_media ;
  struct particula  *anti       ;
};

void
print_particula (struct particula  *prt1)
{
  printf ("\n");
  printf ("Nome da particula: %s\n", (*prt1).nome);
  printf ("  Carga:      %d\n", (*prt1).carga);
  printf ("  Paridade:   %d\n", prt1->paridade);
  printf ("  Spin:       %f\n", prt1->spin);
  printf ("  Massa:      %lf\n", prt1->massa);
  printf ("  Vida Media: %lg\n", prt1->vida_media);

  if (prt1->anti)
    {
      printf ("Anti-Particula:\n");
      print_particula (prt1->anti);
    }
  else
    printf ("  Não foi indicada anti-particula.\n");

  printf ("\n");
}

int
main (int argc, char **argv)
{
  struct particula elect = {"electrao", -1, 1, 0.5, 0.511, 1.0e40, NULL};

  print_particula (&elect);

  return 1;
}
