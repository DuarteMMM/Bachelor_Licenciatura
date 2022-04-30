/***************************************
 *                                     *
 *  Programa para o Calculo do         *
 *  Factorial de um numero:            *
 *                                     *
 *     n! = n x (n -1) x ... x 1       *
 *                                     *
 *  Versao 1.1 (C)                     *
 *                                     *
 *  Autor: Joao Seixas 2004            *
 *  Alteracoes: Samuel Eleuterio 2008  *
 *                                     *
 ***************************************/

#include <stdio.h>

int
factorial (int  n1)
{
  int  n2 ;

  n2 = 1;
  while (n1 > 1)
    {
      n2 = n2 * n1;
      --n1;
    }

  return n2;
}

int 
main ()
{
  int  i1, i2 ;

  printf ("Escreva, por favor, o numero para calcular o factorial: ");
  i2 = scanf ("%d", &i1);

  if (i2 != 1)
    {
      printf ("Erro: Nao leu nenhum numero! Tente outra vez.\n");
      return (-1);
    }

  if (i1 < 0)
    {
      printf ("Erro: Tem de por um numero nao negativo.\n");
      return (-1);
    }

  i2 = factorial (i1);
  printf ("  O factorial de '%d' é: %d\n", i1, i2);

  return 0;
}

