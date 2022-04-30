/*
     Programa para ler uma variável de ambiente
      
     Autores: Samuel Eleuterio 2011
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
  char *ptr, *str1 ;

  if (argc != 2)
    {
      printf("\n  Prog41_02 <variavel_de_ambiente>\n\n");
      exit(1);
    }

  ptr = getenv(argv[1]);

  if (!ptr)
    {
      printf("\n  Nao existe nenhuma variavel com esse nome\n\n");
      exit (1);
    }
  else
    printf("Resultado de 'getenv' - O seu valor e:\n  '%s'\n\n", ptr);

  str1 = (char *) malloc (strlen(argv[1]) + 20);
  sprintf (str1, "env | grep %s", argv[1]);
  
  printf ("Resuldado obtido a partir de 'env' (Comando: '%s'):\n", str1);
  system (str1);

  printf ("\n");
  free (str1);

  return 0;
}
