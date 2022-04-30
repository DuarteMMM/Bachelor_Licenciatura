#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "Prog44_xx.h"


void
stdd_init (StDD **stdd)
{
  *stdd = NULL;
}

StDD *
stdd_create (char   *nome   ,
	     char    sexo   ,
	     int     idade  ,
	     double  altura )
{
  StDD *f1 ;

  f1 = (StDD *) malloc (sizeof (StDD));
  f1->nome = strdup (nome);
  f1->sexo = sexo;
  f1->idade = idade;
  f1->altura = altura;
  f1->next = NULL;

  return f1;
}

int
stdd_read_file (StDD **stdd  ,
		char  *fname )
{
  char    *s1   ;
  FILE    *fich ;

  fich = fopen (fname, "rt");
  if (!fich)
    return -1;

  s1 = (char *) malloc (256);
  while (fgets (s1, 256, fich))
    {
      //printf ("s1: '%s'\n", s1);
      stdd_line_to_stdd (stdd, s1);
    }

  free (s1);
  fclose (fich);

  return 0;
}

void
stdd_insert (StDD  **stdd   ,
	     char   *nome   ,
	     char    sexo   ,
	     int     idade  ,
	     double  altura )
{
  StDD *f1, *f2 ;

  f1 = stdd_create (nome, sexo, idade, altura);

  if (!(*stdd))
    {
      (*stdd) = f1;
      return;
    }

  f2 = (*stdd);
  while (f2 && f2->next)
    f2 = f2->next;
  f2->next = f1;
}

int
stdd_line_to_stdd (StDD **stdd ,
		   char  *s1   )
{
  char    *sv[5]         ;
  char    *seps = ", "   ;
  int      n1, i1, idade ;
  double   altura        ;

  n1 = 0;
  sv[0] = strtok (s1, seps);
  sv[4] = NULL;
  for (i1 = 0 ; i1 < 4 ; ++i1)
    {
      if (!sv[i1])
	break;
      ++n1;
      sv[i1+1] = strtok (NULL, seps);
    }
  if (n1 != 4)
    {
      printf ("\n  Linha inválida (poucos campos): '%s'\n", s1);
      return -1;
    }
  if (sv[4] != NULL)
    {
      printf ("\n  Linha inválida (demasiados campos): '%s'\n", s1);
      return -2;
    }

  if (!((sv[1][1] != 0) || (toupper(sv[1][0]) != 'M') || (toupper(sv[1][0]) != 'F')))
    {
      printf ("\n  Indicação de sexo inválida: '%s'\n", sv[1]);
      return -3;
    }

  idade = (int) strtol (sv[2], &sv[4], 10);
  if ((idade < 0) || (idade > 200))
    {
      printf ("\n  Indicação de idade inválida: '%s' - idade: %d\n", sv[2], idade);
      return -4;
    }

  altura = strtod (sv[3], &sv[4]);
  if ((altura < 0.) || (altura > 3.))
    {
      printf ("\n  Indicação de altura inválida: '%s'\n", sv[3]);
      return -5;
    }

  //printf ("%25s ; Sexo: %c ; Idade:%3d ; Altura: %.2lf\n", 
  //	    sv[0], sv[1][0], idade, altura);
  stdd_insert (stdd, sv[0], sv[1][0], idade, altura);

  return 0;
}

void
stdd_print_element (StDD *stdd)
{
  printf ("%25s ; Sexo: %c ; Idade:%3d ; Altura: %.2lf\n", 
	  stdd->nome, stdd->sexo, stdd->idade, stdd->altura);
}

void
stdd_list (StDD *stdd)
{
  if (!stdd)
    {
      printf ("A fila está vazia\n");
      return;
    }

  while (stdd)
    {
      stdd_print_element (stdd);
      stdd = stdd->next;
    }
}

int
stdd_write_file (StDD  *stdd  ,
	  	 char  *fname )
{
  FILE  *fich ;

  if (!stdd)
    return -1;

  fich = fopen (fname, "wt");
  if (!fich) {
    return -1;
  }

  while (stdd)
    {
      fprintf (fich, "%s, %c, %d, %.2lf\n", stdd->nome, stdd->sexo, 
	       stdd->idade, stdd->altura);
      stdd = stdd->next;
    }

  fclose (fich);

  return 0;
}

void
stdd_delete (StDD **stdd)
{
  StDD *ptr ;

  if ((!stdd) || (!(*stdd)))
    return;

  while (*stdd)
    {
      ptr = (*stdd);
      (*stdd) = (*stdd)->next;
      free (ptr);
    }
}

