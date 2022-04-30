/***************************************
 *                                     *
 *  Programa para o Calculo do         *
 *  Factorial de um numero:            *
 *  (Usando uma funcao recursiva)      *
 *                                     *
 *     n! = n x (n -1) x ... x 1       *
 *                                     *
 *  Versao 1.2 (C)                     *
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

  if (n1 == 0)
    return 1;

  n2 = n1 * factorial (n1 - 1);
  //printf ("n1: %d ; n2: %d\n", n1, n2);

  return n2;
}

int 
main ()
{
  int  i1, i2 ;

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

  i2 = factorial (i1);
  printf ("  O factorial de '%d' é: %d\n", i1, i2);

  return 0;
}
