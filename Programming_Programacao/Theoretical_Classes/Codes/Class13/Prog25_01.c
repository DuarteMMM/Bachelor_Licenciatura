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
#include <stdlib.h>

int
main (int argc, char **argv, char **env)
{
  int i1  ;

  // Usando a variável da 'main' como vector.

  i1 = 0;
  while (env[i1])
    printf ("%s\n", env[i1++]);

  return 0;
}
