/*****************************************************
 *                                                   *
 *     Exemplo de Estruturas de Dados Dinâmicas      *
 *       FIFO (First In, First Out)                  *
 *                                                   *
 *     Versao: 1.0                                   *
 *     Samuel Eleuterio 2015                         *
 *                                                   *
 *     Para compilar:                                *
 *       gcc -o Prog44_01 Prog44_01.c Prog44_xx.c    *
 *                                                   *
 *****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "Prog44_xx.h"

#define FILE_NAME "Prog44_01_Data.txt"


void
stdd_get_remove_first (StDD **stdd , 
		       int    opt  )
{
  StDD *ptr ;

  if ((!stdd) || (!(*stdd)))
    {
      printf ("A fila está vazia\n");
      return;
    }
  if (opt == 1)
    stdd_print_element (*stdd);

  ptr = (*stdd);
  (*stdd) = (*stdd)->next;
  free (ptr);
}

int
main (int argc, char **argv)
{
  char  ch1, *str1 ;
  StDD *stdd       ;

  str1 = (char *) malloc (256);

  stdd_init (&stdd);

  stdd_read_file (&stdd, FILE_NAME);

  while (1)
    {
      do
	{
	  printf ("\n  Opções:\n");
	  printf ("    'i' : Inserir nova entrada\n");
	  printf ("    't' : Tirar o próximo\n");
	  printf ("    'l' : Listar informação\n");
	  printf ("    'a' : Apagar lista\n");
	  printf ("    'w' : Guardar informação no ficheiro\n");
	  printf ("    'q' : Sair sem guardar informação no ficheiro\n");
	  printf ("    'x' : Sair guardando informação no ficheiro\n");
	  printf ("Que deseja fazer? ");
	  ch1 = getchar ();
	  ch1 = tolower (ch1);
	  while (getchar() != 10);
	} while (strchr ("ailqstwx", ch1) == NULL);

      switch (ch1)
	{
	case 'a' :
	  stdd_delete (&stdd);
	  break;
	case 'i' : 
	  printf ("Escreva a entrada [nome, sexo, idade, altura]: ");
	  fgets (str1, 256, stdin);
	  if (stdd_line_to_stdd (&stdd, str1) != 0)
	    printf ("\n  Falhou a entrada da informação. Tente outra vez se desejar...\n\n");
	  break;
	case 'l' : 
	  stdd_list (stdd);
	  break;
	case 'q' :
	  break;
	case 't' :
	  stdd_get_remove_first (&stdd, 1);
	  break;
	case 'w' :
	  if (stdd_write_file (stdd, FILE_NAME) < 0)
	    printf("\n    ***** Erro a escrever no ficheiro\n\n");
	  break;
	case 'x' :
	  stdd_write_file (stdd, FILE_NAME);
	  ch1 = 'q';
	  break;
	default :
	  break;
	}
      if (ch1 == 'q')
	break;
    }

  //stdd_list (stdd);

  //stdd_write_file (stdd, FILE_NAME);

  free (str1);
  return 0;
}

