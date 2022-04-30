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
  int    i1, i2, i3 ;
  float  x1         ;
  FILE  *fich1      ;

  //  Abrir o ficheiro para escrita e testar a abertura

  fich1 = fopen ("Prog06_03_Data.txt", "wt");
  if (!fich1)
    {
      printf ("ERR-Nao conseguiu abrir para escrita a file 'Prog06_03_Data.txt'\n");
      return (-1);
    }

  printf (" ***** Escrita *****\n");
  x1 = 2722.0;
  for (i1 = 0 ; i1 < 10 ; ++i1)
    {
      fprintf (fich1, "%d - %f\n", i1, x1);
      printf ("%d - %f\n", i1, x1);
      x1 = sqrt (x1);
    }

  // Fechar o ficheiro
  
  fclose (fich1);

  //  Abrir o ficheiro para leitura e testar a abertura

  fich1 = fopen ("Prog06_03_Data.txt", "rt");
  if (!fich1)
    {
      printf ("ERR-Nao conseguiu abrir para leitura a file 'Prog06_03_Data.txt'\n");
      return (-1);
    }

  printf ("\n ***** Leitura *****\n");
  for (i1 = 0 ; i1 < 10 ; ++i1)
    {
      i3 = fscanf (fich1, "%d - %f\n", &i2, &x1);
      if (i3 != 2)
	{
          printf ("Erro a ler a linha '%d'\n", i1 + 1);
	  break;
	}
      printf ("Leituras: i2: %d ; x1: %f\n", i2, x1); 
    }

  // Fechar o ficheiro
  
  fclose (fich1);

  return 0;
}
