/***************************************************************
 *                                                             *
 *   Fazer uma operacao com um numero variavel de argumentos   *
 *                                                             *
 *   Versao: 1.0                                               *
 *   Autor: Samuel Eleuterio 2015                              *
 *                                                             *
 ***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/* prototipo com numero variavel de argumentos */

double 
exec_variavel (char oper1, int quantos, ...)
{
  int      n1   ;
  double   x, y ;
  va_list  vp   ;             // vp: lista de argumentos

  if (!((oper1 == '+') || (oper1 == 'x')))
    {
      printf ("\n   Operacao invalida '%c'.\n\n", oper1);
      exit (1);
    }

  va_start(vp, quantos);      // inicializacao da lista

  y = 0;

  for (n1 = 0 ; n1 < quantos ; ++n1)
    {
      x = va_arg (vp, double);
      printf ("%2d - x: %lf\n", n1, x);
      if (n1 == 0)
	y = x;
      else if (oper1 == '+')
	y = y + x;
      else
	y = y * x;
    }
  printf ("Recebeu %d valores Sinal: '%c' - Resultado: %lf\n", n1, oper1, y);

  va_end(vp);  // termina o acesso a lista de argumentos

  return y;
}

int main()
{
  printf ("\n");
  exec_variavel ('+', 0);
  printf ("\n");
  exec_variavel ('+', 2, 1., 3.);
  printf ("\n");
  exec_variavel ('x', 3, 2., 3., 6.);
  printf ("\n");
  exec_variavel ('+', 7, 2., 4., 0., 5., 6., 7., 8.);
  printf ("\n");

  return 0;
}

