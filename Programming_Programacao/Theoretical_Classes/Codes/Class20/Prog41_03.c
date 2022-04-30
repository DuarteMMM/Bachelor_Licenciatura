/*
     Programa demonstrando o uso de strtol para uma sequencia binaria
      
     Autor: Samuel Eleuterio 2015
*/

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
  char      *ptr ;
  long int   i1  ;

  if (argc != 2)
    {
      printf ("\n    prog41_03 <sequencia binaria>\n\n");
      return 0;
    }

  i1 = strtol (argv[1], &ptr, 2);

  printf ("\n  Valor em decimal: %ld\n", i1);

  if (ptr[0])
    printf ("  String nao lida: %s\n", ptr);

  printf ("\n");

  return 0;
}
