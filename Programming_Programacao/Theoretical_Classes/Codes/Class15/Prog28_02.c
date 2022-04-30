/********************************************
 *                                          *
 *      Funcao: Ponteiros para Funcoes      *
 *                                          *
 *      Versao: 1.2                         *
 *      Samuel Eleuterio 2008               *
 *                                          *
 ********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double
quadrado (double x)
{
  return x * x;
}

double
cubo (double x)
{
  return x * x * x;
}

/*da_resultado (double  func (double ) ,   */
/*da_resultado (double  (*func) (double ) ,*/

void
da_resultado (double  (*func) (double) ,
              double  y                )
{
  double z ;

  z = func (y);
  printf ("  O resultado e: %lf\n\n", z);
}       


int
main (int argc, char **argv)
{
  char   ch1, *pt1 ;
  double x         ;

  if (argc != 2)
    {
      printf ("\n  Prog28_01 <numero>\n\n");
      return -1;
    }

  x = strtod (argv[1], &pt1);
  if ((*pt1) != 0)
    {
      if (pt1 == argv[1])
        printf ("\n  *** Não indicou um número.\n\n");
      else
	printf ("\n  *** Existem elementos não numéricos depois do número: '%s'\n\n", pt1);
      return -1;
    }

  printf ("\n  Leu o numero: %lf\n", x);

  do
    {
      printf ("  Quer o [q]uadrado ou  [c]ubo? ");
      ch1 = getchar ();
      while (getchar () != 10);
    } while (!((ch1 == 'q') || (ch1 == 'c')));

  /*****  É equivalente a expressão seguinte

  if (ch1 == 'q')
    da_resultado (quadrado, x);
  else if (ch1 == 'c')
    da_resultado (cubo, x);

  */

  da_resultado ( (ch1 == 'q' ? quadrado : cubo) , x);
  
  return 0;
}
