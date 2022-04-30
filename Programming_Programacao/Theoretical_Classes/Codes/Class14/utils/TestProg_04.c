/*  
   TestProg_04.c  

   Para compilar:
      gcc -c Utils.c
      gcc -c UtilsVect.c
      gcc -c TestProg_04.c 
      gcc -o TestProg_04 TestProg_04.o Utils.o UtilsVect.o -lm

   ou mais simplesmente
      gcc -o TestProg_04 TestProg_04.c Utils.c UtilsVect.c -lm
*/

#include <stdio.h>
#include <stdlib.h>

#include "Utils.h"
#include "UtilsVect.h"

#define QUANTOS  3

int
main (int argc, char **argv)
{
  long int   i1, i2          ;
  double     limite, tr1     ;
  double   **matr1, **matr2  ;
  

  if ((argc != 2) || (sscanf (argv[1], "%lg", &limite) != 1))
    {
      printf ("\n  TesteProg4 <Valor>     (Aleatarios no intervalo [0,Valor])\n\n");
      exit (-1);
    }

  tsrand ();
  matr1 = (double **) matx_new (QUANTOS, QUANTOS, sizeof (double));
  matr2 = (double **) matx_new (QUANTOS, QUANTOS, sizeof (double));
	
  for (i1 = 0 ; i1 < QUANTOS ; ++i1)
    for (i2 = 0 ; i2 < QUANTOS ; ++i2)
      {
        matr1[i1][i2] = xrand (limite);
        matr2[i1][i2] = xrand (limite);
      }

  printf ("\n");          
  printf ("             Matriz1                             Matriz2\n");
  for (i1 = 0 ; i1 < QUANTOS ; ++i1)
    {
      printf ("   ");
      for (i2 = 0 ; i2 < QUANTOS ; ++i2)
        printf ("   %.3f",  matr1[i1][i2]);
      printf ("            ");          
      for (i2 = 0 ; i2 < QUANTOS ; ++i2)
        printf ("   %.3f",  matr2[i1][i2]);
      printf ("\n");          
    }
  printf ("\n");          

  tr1 = matx_trac (matr1, QUANTOS);
  printf ("Traco:        %.3f", tr1);
  tr1 = matx_trac (matr2, QUANTOS);
  printf ("                               %.3f\n\n", tr1);

  matx_free (matr1);
  matx_free (matr2);

  return 0;
}
