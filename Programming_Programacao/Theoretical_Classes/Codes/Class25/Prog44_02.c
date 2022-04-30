/*****************************************************
 *                                                   *
 *     Exemplo de Estruturas de Dados Dinâmicas      *
 *       LIFO (Last In, First Out)                   *
 *                                                   *
 *     Versao: 1.0                                   *
 *     Samuel Eleuterio 2015                         *
 *                                                   *
 *     Para compilar:                                *
 *       gcc -o Prog44_02 Prog44_02.c Prog44_xx.c    *
 *                                                   *
 *****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "Prog44_xx.h"

#define FILE_NAME "Prog44_02_Data.txt"


void
stdd_get_remove_last (StDD **stdd , 
		      int    opt  )
{
  StDD *ptr1, *ptr2 ;

  if ((!stdd) || (!(*stdd)))
    {
      printf ("A fila está vazia\n");
      return;
    }

  ptr1 = (*stdd);
  ptr2 = NULL;
  while (ptr1->next)
    {
      ptr2 = ptr1;
      ptr1 = ptr1->next;
    }

  if (opt == 1)
    stdd_print_element (ptr1);

  free (ptr1);
  if (ptr2)
    ptr2->next = NULL;
  else
    (*stdd) = NULL;
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
	  stdd_get_remove_last (&stdd, 1);
	  break;
	case 'w' :
	  stdd_write_file (stdd, FILE_NAME);
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

