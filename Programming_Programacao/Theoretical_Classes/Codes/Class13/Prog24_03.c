/********************************************
 *                                          *
 *      Exemplos de 'goto'                  *
 *                                          *
 *      Versao: 1.0                         *
 *      Samuel Eleuterio 2008               *
 *                                          *
 ********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *texto = "Bom dia!" ;

char **
cria_vector_de_strings (int  qt  ,
                        int  len )
{
  int    i1, i2 ;
  char **vch    ;

  vch = (char **) malloc (qt * sizeof (char *));
  if (vch == NULL)
    return NULL;
  
  for (i1 = 0 ; i1 < qt ; ++i1)
    vch[i1] = NULL;

  for (i1 = 0 ; i1 < qt ; ++i1)
    {
      vch[i1] = (char *) malloc (len * sizeof (char));
      if (vch[i1] == NULL)
	goto deu_erro;
      sprintf (vch[i1], "%4d - %s", i1, texto);
    }

  return vch;

deu_erro:
  for (i2 = 0 ; i2 < i1 ; ++i2)
    if (vch[i2])
      free (vch[i2]);
  free (vch);
  
  return NULL;
}

int
main (int argc, char **argv)
{
  int    i1 ;
  char **vi ;

  vi = cria_vector_de_strings (10, 20);
  if (!vi)
    {
      printf ("\n  ****** Deu erro ******\n\n");
      return -1;
    }

  for (i1 = 0 ; i1 < 10 ; ++i1)
    printf ("%s\n", vi[i1]);

  return 0;
}
