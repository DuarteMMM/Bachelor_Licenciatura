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
  char **ptr ;

  // Usando um ponteiro e incrementando-o 

  ptr = env;
  while (*ptr)
    {
      printf ("%s\n", *ptr);
      ++ptr;
    }

  return 0;
}
