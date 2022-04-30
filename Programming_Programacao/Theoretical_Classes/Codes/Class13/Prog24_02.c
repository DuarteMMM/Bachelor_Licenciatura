/********************************************
 *                                          *
 *      Exemplos de ciclos (loops)          *
 *        ( while, do ... while, for )      *
 *                                          *
 *      Versao: 1.0                         *
 *      Samuel Eleuterio 2008               *
 *                                          *
 ********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void
show_help (int status)
{
  printf ("\n  Prog24_01 <numero>\n");
  printf ("    1 : Exemplo de 'for' com 'if'\n");
  printf ("    2 : Exemplo de 'for' com 'continue'\n");
  printf ("    3 : Exemplo de 'while' com 'continue'\n");
  printf ("    4 : Exemplo de 'while' com 'break'\n");
  printf ("    5 : Exemplo de 'do ... while'\n");
  printf ("    6 : Exemplo de 'goto'\n");
  printf ("\n");
  printf ("  Mostra os valores aleatórios maiores do que 0.5\n");
  printf ("\n");
  exit (status);
}

int
main (int argc, char **argv)
{
  int     i1 ;
  double  x1 ;

  if (argc != 2)
    show_help (-1);

  srand (time (NULL));

  switch (argv[1][0])
    {
    case '1' :
      for (i1 = 0 ; i1 < 20 ; ++i1)
	{
	  x1 = ((double) rand ()) / ((double) RAND_MAX);
	  if (x1 > 0.5)
	    printf ("%2d: %lf\n", i1, x1);
	}
      break;

    case '2' :
      for (i1 = 0 ; i1 < 20 ; ++i1)
	{
	  x1 = ((double) rand ()) / ((double) RAND_MAX);
	  if (x1 <= 0.5)
	    continue;
	  printf ("%2d: %lf\n", i1, x1);
	}
      break;

    case '3' :
      i1 = 0;
      while (i1 < 20)
        {
          x1 = ((double) rand ()) / ((double) RAND_MAX);
          ++i1;
          if (x1 <= 0.5)
            continue;
          printf ("%2d: %lf\n", i1 - 1, x1);
	}
      break;

    case '4' :
      i1 = 0;
      while (1)
        {
          if (i1 >= 20)
	    break;
          x1 = ((double) rand ()) / ((double) RAND_MAX);
          ++i1;
          if (x1 <= 0.5)
            continue;
          printf ("%2d: %lf\n", i1 - 1, x1);
	}
      break;

    case '5' :
      i1 = 0;
      do
        {
          x1 = ((double) rand ()) / ((double) RAND_MAX);
          ++i1;
          if (x1 <= 0.5)
            continue;
          printf ("%2d: %lf\n", i1 - 1, x1);
	} while (i1 < 20);
      break;

    case '6' :
      i1 = 0;
inicio:
      if (i1 >= 20)
        goto fim;
      x1 = ((double) rand ()) / ((double) RAND_MAX);
      ++i1;
      if (x1 <= 0.5)
        goto inicio;
      printf ("%2d: %lf\n", i1 - 1, x1);
      goto inicio;
      // break;

    default : 
      printf ("Opcao invalida\n");
    }

fim:
  return 0;
}
