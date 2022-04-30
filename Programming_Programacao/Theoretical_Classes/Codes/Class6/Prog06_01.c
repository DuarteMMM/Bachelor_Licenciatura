/***************************************
 *                                     *
 *  Programa de exemplificacao da      *
 *  escrita e leitura em files         *
 *                                     *
 *  Versao 1.1 (C)                     *
 *                                     *
 *  Autor: Samuel Eleuterio 2008       *
 *                                     *
 ***************************************/

#include <stdio.h>
#include <math.h>

int 
main ()
{
  int    i1    ;
  float  x1    ;
  FILE  *fich1 ;

  //  Abrir o ficheiro para escrita e testar a abertura

  fich1 = fopen ("Prog06_01_Data.txt", "wt");
  if (fich1 == NULL)
    {
      printf ("ERR-Nao conseguiu abrir para escrita o ficheiro 'Prog06_01_Data.txt'\n");
      return 1;
    }

  // Mostrar a tabuada no ecran e escreve-la no ficheiro
  
  x1 = 2722.0;
  for (i1 = 0 ; i1 < 10 ; ++i1)
    {
      fprintf (fich1, "%d - %f\n", i1, x1);
      printf ("%d - %f\n", i1, x1);
      //fprintf (stdout, "%d - %f\n", i1, x1);
      x1 = sqrt (x1);
    }

  // Fechar o ficheiro
  
  fclose (fich1);

  return 0;
}
