/*  
   TestProg_01.c  

   Para compilar:
      gcc -c Utils.c
      gcc -c TestProg_01.c 
      gcc -o TestProg_01 TestProg_01.o Utils.o 

   ou mais simplesmente
      gcc -o TestProg_01 TestProg_01.c Utils.c
*/

#include <stdio.h>
#include <stdlib.h>

#include "Utils.h"

#define QUANTOS  10

int
main (int argc, char **argv)
{
  int       i1         ;
  double    limite     ;
  double   *aleatorios ;

  if ((argc != 2) || (sscanf (argv[1], "%lg", &limite) != 1))
    {
      printf ("\n  TesteProg1 <Valor>     (Aleatarios no intervalo [0,Valor])\n\n");
      exit (-1);
    }

  tsrand ();
  aleatorios = (double *) malloc (QUANTOS * sizeof (double));

  for (i1 = 0 ; i1 < QUANTOS ; ++i1)
    aleatorios[i1] = xrand (limite);

  printf ("\nValores aleatórios no intervalo: [0 , %lg]  (Ptr: %p)\n", limite, aleatorios);
  for (i1 = 0 ; i1 < QUANTOS ; ++i1)
    printf ("  %.6lf\n", aleatorios[i1]);

  freeNull (aleatorios);

  printf ("\nPtr: %p\n\n", aleatorios);

  return 0;
}
