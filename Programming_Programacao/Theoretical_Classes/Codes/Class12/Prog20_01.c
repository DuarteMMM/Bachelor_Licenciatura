/*****************************************************
 *                                                   *
 *      Exemplo de Leitura de Files                  *
 *                                                   *
 *      Versao: 1.0                                  *
 *      Samuel Eleuterio 2008                        *
 *                                                   *
 *****************************************************/

#define FILE_NAME "Prog20_01_Data.txt"


#include <stdio.h>
#include <stdlib.h>

int 
main (int argc, char **argv)
{
  int    i1    ;
  FILE  *fich1 ;

  fich1 = fopen (FILE_NAME, "wt");
  if (!fich1)
    {
      printf ("Erro a escrever o ficheiro '%s'\n", FILE_NAME);
      return (-1);
    }

  printf ("\n*** Escrita de uma File ... ***\n");
  for (i1 = 0 ; i1 < 10 ; ++i1)
    fprintf (fich1, "%d\n", i1 + 10);
  fclose (fich1);

  fich1 = fopen (FILE_NAME, "rt");
  if (fich1 == NULL)
    {
      printf ("Nao conseguiu abrir a file %s\n", FILE_NAME);
      return 0;
    }

  printf ("\n*** Leitura de uma File com fscanf e 'EOF'  (Valor: %d) ***\n", EOF);
  while (fscanf (fich1, "%d", &i1) != EOF)
    printf ("  i1: %d\n", i1);
  fclose (fich1);

  printf ("\n");

  return 0;
}
