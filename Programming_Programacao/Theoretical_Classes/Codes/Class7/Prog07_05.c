/***************************************
 *                                     *
 *  Programa para o Calculo do         *
 *  Factorial de um numero:            *
 *  (Usando uma funcao recursiva)      *
 *  (Com valores reais)                *
 *                                     *
 *     n! = n x (n - 1) x ... x 1      *
 *                                     *
 *  Versao 1.4 (C)                     *
 *                                     *
 *  Autor: Joao Seixas 2004            *
 *  Alteracoes: Samuel Eleuterio 2008  *
 *                                     *
 ***************************************/

#include <stdio.h>

double
factorial (int  n1)
{
  double x2 ;

  if (n1 == 0)
    return 1.;

  x2 = n1 * factorial (n1 - 1);

  return x2;
}

int 
main ()
{
  int     i1, i2 ;
  double  x2     ;

  printf ("Escreva, por favor, o numero para calcular o factorial: ");
  i2 = scanf ("%d", &i1);
  if (i2 == 0)
    {
      printf ("Erro: Nao leu nenhum numero! Tente outra vez.\n");
      return (-1);
    }

  if (i1 < 0)
    {
      printf ("Erro: Tem de por um numero nao negativo.\n");
      return (-1);
    }

  x2 = factorial (i1);
  printf ("  O factorial de '%d' é (formato '%%lf'): %lf\n", i1, x2);
  printf ("  O factorial de '%d' é (formato '%%le'): %le\n", i1, x2);
  printf ("  O factorial de '%d' é (formato '%clg'): %lg\n", i1, '%', x2);

  return 0;
}
