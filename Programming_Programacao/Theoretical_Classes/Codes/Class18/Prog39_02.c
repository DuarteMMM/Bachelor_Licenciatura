/********************************************
 *                                          *
 *     Exemplos de <stdio.h>                *
 *     Leitura e Escrita de caracteres      *
 *                                          *
 *     Versao: 1.0                          *
 *     Samuel Eleuterio 2008                *
 *                                          *
 ********************************************/

#define DATA_FILE1 "Prog39_02__Data_01.txt"
#define DATA_FILE2 "Prog39_02__Data_02.txt"

#define LEN_STR  128

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *linhas[] = {
  "A1. Esta e a primeira linha da file de teste.",
  "A2. Quando se le ou escreve caracteres numa file",
  "A3. as funcoes podem ler linhas ou ler char a char",
  "A4. Quando se escreve por cima parte do texto pode perder-se.",
  "A5. Para tal nao acontecer e preciso ir para o fim da file.",
  NULL};

char *mais_linhas[] = {
  "X1",
  "X2. Isto e a variante da segunda linha que muda?",
  "X3. Esta e uma terceira linha",
  NULL};

int
escreve_com_fputs (char *fname)
{
  int   i1    ;
  FILE *fich1 ;

  if (!(fich1 = fopen (fname, "wt"))) 
    return (-1);

  i1 = 0;
  while (linhas[i1])
    {
      fputs (linhas[i1++], fich1);
      fputs ("\n", fich1);
    }
  fclose (fich1);

  return 1;
}

int
escreve_com_fputc (char *fname)
{
  int   i1, i2 ;
  FILE *fich1  ;

  if (!(fich1 = fopen (fname, "wt")))
    return (-1);

  i1 = 0;
  while (linhas[i1])
    {
      i2 = 0;
      while (linhas[i1][i2])
        fputc (linhas[i1][i2++], fich1);
      fputc ('\n', fich1);
      ++i1;
    }
  fclose (fich1);

  return 1;
}

int
le_com_fgets (char *fname ,
              int   qt    )
{
  int   conta         ;
  char  str1[LEN_STR] ;
  FILE *fich1         ;

  if (!(fich1 = fopen (fname, "rt")))
    return (-1);

  conta = 0;
  while (conta < qt)
    {
      if (!fgets (str1, LEN_STR, fich1))
	break;
      printf ("%s", str1);
      ++conta;
    }
  fclose (fich1);

  return 1;
}

int
le_com_fgetc (char *fname ,
              int   qt    )
{
  int    conta, i1, i2 ;
  char   str1[LEN_STR] ;
  FILE  *fich1         ;

  if (!(fich1 = fopen (fname, "rt")))
    return (-1);

  conta = 0;
  while (conta < qt)
    {
      i1 = 0;
      while ((i2 = fgetc (fich1)) != EOF)
        {
          str1[i1++] = i2;
          if ((i2 == 10) || (i1 >= (LEN_STR - 2)))
	    {
	      if (i2 == 10)
		++conta;
	      break;
	    }
	}
      str1[i1] = 0;
      printf ("%s", str1);
    }
  fclose (fich1);

  return 1;
}

void
testa_unix_diff (char  *fname1 ,
                 char  *fname2 )
{
#if defined(__unix__)
  int    status, len ;
  char  *str1        ;

  len = 16 + strlen (fname1) + strlen (fname2);
  str1 = (char *) malloc (len);
  snprintf (str1, len, "diff -s %s %s", fname1, fname2);
  printf ("*** Vai testar se ha diferencas '%s': \n", str1);
  status = system (str1);
  printf ("Status: %d\n", status);

  free (str1);

#endif
}

void
show_help (int status)
{
  printf ("  Prog39 <Opcao>  -  Escreve files com 'fputs' e 'fputc'\n");
  printf ("    1 : Le com fgets' e 'fgetc' usa comando unix 'diff'\n");
  printf ("    2 : Abre a primeira file com 'r+' e escreve uma linha\n");
  printf ("    3 : Abre a primeira file com 'r+', le uma linha e escreve outra\n");
  printf ("    4 : Abre a primeira file com 'r+', vai para o fim e escreve\n");
  printf ("    5 : Abre a primeira file com 'w+' e escreve duas linhas\n");
  printf ("    6 : Abre a primeira file com 'w+', vai para o fim e escreve duas linhas\n");
  printf ("    7 : Abre a primeira file com 'a+' e escreve duas linha\n");
  printf ("    8 : Abre a primeira file com 'a+', faz 'rewind' e escreve duas linhas\n");
  printf ("\n");

  exit (status);
}

int
main (int argc, char **argv)
{
  int   pos           ;
  char       str1[LEN_STR] ;
  FILE      *fich1         ;

  printf ("\n");

  if (argc != 2)
    show_help (-1);

  escreve_com_fputs (DATA_FILE1);
  if (strcmp (argv[1], "1") == 0)
    printf ("*** Usando a funcao 'fputs' escreveu a file '%s'\n", DATA_FILE1);

  escreve_com_fputc (DATA_FILE2);
  if (strcmp (argv[1], "1") == 0)
    printf ("*** Usando a funcao 'fputc' escreveu a file '%s'\n\n", DATA_FILE2);

  /* Opcao 1 - Depois de escrever testa leituras e diferencas */

  if (strcmp (argv[1], "1") == 0)
    {
      testa_unix_diff (DATA_FILE1, DATA_FILE2);
      printf ("\n");

      printf ("*** Leitura das duas primeiras linhas com 'fgets' (%s):\n", DATA_FILE1);
      le_com_fgets (DATA_FILE1, 2);
      printf ("\n");

      printf ("*** Leitura das duas primeiras linhas com 'fgetc' (%s):\n", DATA_FILE1);
      le_com_fgetc (DATA_FILE1, 2);
      printf ("\n");

      return 0;
    }

  if (strcmp (argv[1], "2") == 0)
    {
      fich1 = fopen (DATA_FILE1, "rt+");
      fputs (mais_linhas[0], fich1);
      fclose (fich1);

      testa_unix_diff (DATA_FILE1, DATA_FILE2);
      printf ("\n");

      return 0;
    }

  if (strcmp (argv[1], "3") == 0)
    {
      fich1 = fopen (DATA_FILE1, "rt+");
      pos = ftell (fich1);
      printf ("  Posicao inicial: %d\n", pos);

      fgets (str1, LEN_STR, fich1);
      pos = ftell (fich1);
      printf ("  Posicao depois de ler a primeira linha: %d\n", pos);
      fputs (mais_linhas[1], fich1);
      pos = ftell (fich1);
      printf ("  Posicao depois de escrever: %d\n", pos);
      fclose (fich1);
      printf ("\n");
  
      testa_unix_diff (DATA_FILE1, DATA_FILE2);
      printf ("\n");

      return 0;
    }

  if (strcmp (argv[1], "4") == 0)
    {
      fich1 = fopen (DATA_FILE1, "rt+");
      pos = ftell (fich1);
      printf ("  Posicao inicial: %d\n", pos);
      fseek (fich1, 0, SEEK_END);
      pos = ftell (fich1);
      printf ("  Posicao final com 'SEEK_END' antes de escrever: %d\n", pos);

      fputs (mais_linhas[1], fich1);
      fputs ("\n", fich1);
      fputs (mais_linhas[2], fich1);
      fputs ("\n", fich1);
      pos = ftell (fich1);
      printf ("  Posicao final depois de escrever: %d\n", pos);
      fclose (fich1);
      printf ("\n");

      testa_unix_diff (DATA_FILE1, DATA_FILE2);
      printf ("\n");

      return 0;
    }

  if (strcmp (argv[1], "5") == 0)
    {
      fich1 = fopen (DATA_FILE1, "w+");
      pos = ftell (fich1);
      printf ("  Posicao inicial: %d\n", pos);
      fputs (mais_linhas[1], fich1);
      fputs ("\n", fich1);
      fputs (mais_linhas[2], fich1);
      fputs ("\n", fich1);
      pos = ftell (fich1);
      printf ("  Posicao final depois de escrever: %d\n", pos);
      fclose (fich1);
      printf ("\n");

      testa_unix_diff (DATA_FILE1, DATA_FILE2);
      printf ("\n");

      return 0;
    }

  if (strcmp (argv[1], "6") == 0)
    {
      fich1 = fopen (DATA_FILE1, "w+");
      pos = ftell (fich1);
      printf ("  Posicao inicial: %d\n", pos);
      fseek (fich1, 0, SEEK_END);
      printf ("  Posicao apos 'SEEK_END': %d\n", pos);
      fputs (mais_linhas[1], fich1);
      fputs ("\n", fich1);
      fputs (mais_linhas[2], fich1);
      fputs ("\n", fich1);
      pos = ftell (fich1);
      printf ("  Posicao final depois de escrever: %d\n", pos);
      fclose (fich1);
      printf ("\n");

      testa_unix_diff (DATA_FILE1, DATA_FILE2);
      printf ("\n");

      return 0;
    }

  if (strcmp (argv[1], "7") == 0)
    {
      fich1 = fopen (DATA_FILE1, "a+");
      pos = ftell (fich1);
      printf ("  Posicao inicial: %d\n", pos);
      fputs (mais_linhas[1], fich1);
      fputs ("\n", fich1);
      pos = ftell (fich1);
      printf ("  Posicao depois de escrever uma linha: %d\n", pos);
      fputs (mais_linhas[2], fich1);
      fputs ("\n", fich1);
      pos = ftell (fich1);
      printf ("  Posicao final depois de escrever: %d\n\n", pos);

      rewind (fich1);
      pos = ftell (fich1);
      printf ("  Posicao depois de 'rewind': %d\n", pos);
      fgets (str1, LEN_STR, fich1);
      printf ("  Linha depois de fazer 'rewind': %s", str1);
      pos = ftell (fich1);
      printf ("  Posicao depois de ler a primeira linha: %d\n", pos);
      fclose (fich1);
      printf ("\n");

      testa_unix_diff (DATA_FILE1, DATA_FILE2);
      printf ("\n");

      return 0;
    }

  if (strcmp (argv[1], "8") == 0)
    {
      fich1 = fopen (DATA_FILE1, "a+");
      pos = ftell (fich1);
      printf ("  Posicao inicial: %d\n", pos);
      rewind (fich1);
      printf ("  Posicao apos 'rewind': %d\n", pos);
      fputs (mais_linhas[1], fich1);
      fputs ("\n", fich1);
      fputs (mais_linhas[2], fich1);
      fputs ("\n", fich1);
      pos = ftell (fich1);
      printf ("  Posicao final depois de escrever: %d\n", pos);
      rewind (fich1);
      pos = ftell (fich1);
      printf ("  Posicao apos 'rewind': %d\n", pos);
      fgets (str1, LEN_STR, fich1);
      printf ("  Leitura feita apos 'rewind': %s", str1);
      fclose (fich1);
      printf ("\n");

      testa_unix_diff (DATA_FILE1, DATA_FILE2);
      printf ("\n");

      return 0;
    }
  
  printf ("\n");
  return 1;
}
