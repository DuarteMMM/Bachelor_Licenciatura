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
  char    nome[20]   ;
  int     carga      ;
  int     paridade   ;
  float   spin       ;
  double  massa      ;
  double  vida_media ;
};

void
print_particula1 (struct particula  part1)
{
  /* 
     Nesta versao da funcao e' feita a copia da estrutura para 'part1'.
     Uma vez que e' feita uma copia, se fizermos uma alteracao
     na estrutura, essa alteracao so' sera efectiva dentro desta funcao.

     Alem disso, este tipo de transferencia tem o inconveniente de copiar
     toda a estrutura o que em alguns casos podera ter um tamanho consideravel.
   */

  printf ("\n");
  //  part1.massa=8;
  printf ("Nome da particula: %s\n", part1.nome);
  printf ("  Carga:      %d\n", part1.carga);
  printf ("  Paridade:   %d\n", part1.paridade);
  printf ("  Spin:       %f\n", part1.spin);
  printf ("  Massa:      %lf\n", part1.massa);
  printf ("  Vida Media: %lg\n", part1.vida_media);
  printf ("\n");
}


void
print_particula2 (struct particula  *prt1)
{
  /* 
     Nesta versao da funcao e' apenas transferida para a funcao a posicao
     inicial da estrutura na memoria, isto e', o seu ponteiro.
     Assim, qualquer alteracao feita na estrutura manter-se-a' depois
     da funcao ter sido terminada.
   */
  printf ("\n");
  //  prt1->massa = 4;
  printf ("Nome da particula: %s\n", (*prt1).nome);
  printf ("  Carga:      %d\n", (*prt1).carga);
  printf ("  Paridade:   %d\n", prt1->paridade);
  printf ("  Spin:       %f\n", prt1->spin);
  printf ("  Massa:      %lf\n", prt1->massa);
  printf ("  Vida Media: %lg\n", prt1->vida_media);
  printf ("\n");
}

int
main (int argc, char **argv)
{
  struct particula elect = {"electrao", -1, 1, 0.5, 0.511, 1.0e40};

  print_particula1 (elect);
  //  printf ("Massa: %lf\n", elect.massa);
  
  print_particula2 (&elect);
  //  printf ("Massa: %lf\n", elect.massa);
  return 0;
}
