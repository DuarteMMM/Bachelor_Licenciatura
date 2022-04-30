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
#include <string.h>

struct particula 
{
  char    nome[20]   ;
  int     carga      ;
  int     paridade   ;
  float   spin       ;
  double  massa      ;
  double  vida_media ;
};

int
main (int argc, char **argv)
{
  struct particula elect = {"electrao", -1, 1, 0.5, 0.511, 1.0e40};

  printf ("\n");
  printf ("Nome da particula: %s\n", elect.nome);
  printf ("  Carga:      %d\n", elect.carga);
  printf ("  Paridade:   %d\n", elect.paridade);
  printf ("  Spin:       %f\n", elect.spin);
  printf ("  Massa:      %lf\n", elect.massa);
  printf ("  Vida Media: %lg\n", elect.vida_media);
  printf ("\n");

  return 0;
}
