/********************************************
 *                                          *
 *     Exemplos de <stdio.h>                *
 *       Leitura e Escrita Binaria          *
 *                                          *
 *     Versao: 1.0                          *
 *     Samuel Eleuterio 2008                *
 *                                          *
 ********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOME_FILE  "Prog39_04_Data.txt"
#define INICIO     0
#define QUANTOS    1000

void
help (int status)
{
  printf ("\n  Prog39_04 <opcoes>\n");
  printf ("    Opcoes:\n");
  printf ("      wb  : para escrever ficheiro de dados\n");
  printf ("      rb  : para ler ficheiro de dados\n");
  printf ("      del : apaga o ficheiro de dados '%s'\n", NOME_FILE);
  printf ("\n");
  exit (status);
}

int
pede_numero (int    qt   ,
             FILE  *fich )
{
  int  i1 ;

  printf ("\nDiga a posicao no vector a ler [inteiro ate %d ; q - sair]: ", qt);
  while (1)
    {
      if (scanf ("%d", &i1) == 1)
	{
          if ((i1 > qt) || (i1 < 0))
	    {
              printf ("Deu um numero fora dos limites. Tente outra vez [inteiro ate %d ; q - sair]: ", qt);
              continue;
	    }
	  break;
	}
      if (getchar() == 'q')
	{
	  fclose (fich);
	  exit (0);
	}
      while (getchar() != 10);
    }

  return i1;
}


int
main (int argc, char **argv)
{
  int   i1, i2, i3  ;
  int   vi[QUANTOS] ;
  FILE *fich1       ;

  if (argc != 2)
    help (-1);

  if (strcmp (argv[1], "del") == 0)
    {
      printf ("Tem a certeza que quer apagar a file '%s'? [s/n] ", NOME_FILE);
      if (getchar () == 's')
	{
	  i1 = remove (NOME_FILE);
          printf ("Retorno de 'remove': %d\n", i1);
	}
      return 0;
    }

  if (!((strcmp (argv[1], "rb") == 0) || (strcmp (argv[1], "wb") == 0)))
    help (-2);

  if (!(fich1 = fopen (NOME_FILE, argv[1])))
    {
      printf ("\n  ERR-Não conseguiu abrir a file '%s' em modo '%s'\n\n", 
              NOME_FILE, argv[1]);
      return (-1);
    }

  /* Cria a file e escreve nela */

  if (argv[1][0] == 'w')
    {
      for (i1 = 0 ; i1 < QUANTOS ; ++i1)
	vi[i1] = INICIO + i1;

      i1 = fwrite (vi, sizeof(int), QUANTOS, fich1);
      printf ("\n  Retorno de 'fwrite': %d\n\n", i1);
      fclose (fich1);
      return 0;
    }

  /* Le da file e mostra valores */

  while (1)
    {
      i1 = pede_numero (QUANTOS, fich1);  // QUANTOS-1

      i2 = i1 * sizeof(int);
      if (fseek (fich1, i2, SEEK_SET) == 1)
	{
	  printf ("\n  ERR-Erro a posicionar-se em '%s'\n", NOME_FILE);
	  continue;
	}
      if (fread (&i3, sizeof(int), 1, fich1) != 1)
	{
	  printf ("\n  ERR-Erro a ler da posicao '%d' em '%s'\n", i3, NOME_FILE);
	  continue;
	}
      printf ("  O valor do elemento do vector '%d' lido na posicao '%d' foi de %d\n",
              i1, i2, i3);
    }

  return 1;
}
