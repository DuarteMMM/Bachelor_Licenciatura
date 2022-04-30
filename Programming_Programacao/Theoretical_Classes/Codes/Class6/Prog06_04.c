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
  int    i2, i3 ;
  float  x1     ;
  FILE  *fich1  ;

  //  Abrir o ficheiro para leitura e testar a abertura

  fich1 = fopen ("Prog06_01_Data.txt", "rt");
  if (fich1 == NULL)
    {
      printf ("ERR-Nao conseguiu abrir para leitura o ficheiro 'Prog06_01_Data.txt'\n");
      return (-1);
    }

  while (1)
    {
      i3 = fscanf (fich1, "%d - %f\n", &i2, &x1);
      if (i3 != 2)
        {
          printf ("Saida por erro do 'scanf' (nao há mais nada para ler...): %d\n", i3);
	  break;
	}
      printf ("Leituras: i2: %d ; x1: %f\n", i2, x1); 
    }

  // Fechar o ficheiro

  fclose (fich1);

  return 0;
}
