/********************************************
 *                                          *
 *      Variáveis de Ambiente               *
 *                                          *
 *      Versao: 1.0                         *
 *      Joao Seixas 2004                    *
 *      Samuel Eleuterio 2008               *
 *                                          *
 ********************************************/

#include <stdio.h>

int
main (int argc, char **argv)
{
  int valor ;

  valor = 0;
  if (argc == 1)
    valor = 1;
  else
    {
      if (sscanf (argv[1], "%d", &valor) != 1)
        valor = -2;
    }

  printf ("\n====> Programa: Valor de return: %d\n\n", valor);

  return valor;
}
