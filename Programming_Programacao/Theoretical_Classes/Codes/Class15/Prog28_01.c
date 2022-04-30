/********************************************
 *                                          *
 *      Funcao: Ponteiros para Funcoes      *
 *                                          *
 *      Versao: 1.0                         *
 *      Samuel Eleuterio 2008               *
 *                                          *
 ********************************************/

/*
   Nota: É essencial incluir "stdlib.h" para que funções como 'strtod', 'strtol', etc. funcionem correctamente.
*/


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

int
main (int argc, char **argv)
{
  char    ch1, *pt1        ;
  double  x, y             ;
  double  (*func) (double) ;

  if (argc != 2)
    {
      printf ("\n  Prog28_01 <numero>\n\n");
      return -1;
    }

  x = strtod (argv[1], &pt1);
  if ((*pt1) != 0)
    {
      if (pt1 == argv[1])
        printf ("\n  *** Nao indicou um numero.\n\n");
      else
	printf ("\n  *** Existem caracteres nao numericos depois do numero: '%s'\n\n", pt1);
      return -1;
    }

  printf ("\n  Leu o numero: %lf\n", x);

  printf ("  Quer o [q]uadrado ou  [c]ubo? ");
  while (1)
    {
      ch1 = getchar();
      if ((ch1 == 'q') || (ch1 == 'c'))
	break;
      //printf ("%c  (%d)\n", ch1, ch1);
    }

  if (ch1 == 'q')
    func = quadrado;
  else if (ch1 == 'c')
    func = cubo;
  else
    func = NULL;

  if (!func)
    {
      printf ("  *** Tem de escolher 'q' ou 'c'\n\n");
      return (-1);
    }

  y = func(x);
  printf ("  O resultado de '%c' e: %lf\n\n", ch1, y);

  return 0;
}

