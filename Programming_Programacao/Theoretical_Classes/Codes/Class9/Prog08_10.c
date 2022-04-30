/*****************************************************
 *                                                   *
 *      Meu Segundo Programa em C                    *
 *      Para gerar números aleatórios                *
 *                                                   *
 *      E ordena-los com o algoritmo 'bubble sort'.  *
 *                                                   *
 *      Versao: 1.1                                  *
 *      Samuel Eleuterio 2008                        *
 *                                                   *
 *****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void
troca_valores (int  *n1 , 
               int  *n2 )
{
  int i1 ;

  i1 = (*n1);
  (*n1) = (*n2);
  (*n2) = i1;
}

void
bubble_sort (int  *r1 , 
             int   qt )
{
  int teste, i1 ;

  while (1)
    {
      teste = 0;
      for (i1 = 0 ; i1 < qt - 1 ; ++i1)
	{
          if (r1[i1] > r1[i1+1])
	    {
	      troca_valores (r1+i1, r1+i1+1);
	      teste = 1;
	    }
	}
      if (teste == 0)
	break;
    }
}

int 
main (int argc, char **argv)
{
  int     i1, qt      ;
  int     r1[1000000] ;
  time_t  t0, t1, t2  ;

  // Testes iniciais de leitura
  
  if ((argc != 2) || (sscanf (argv[1], "%d", &qt) != 1))
    {
      printf ("\n  Prog08_10 <numeros_a_gerar>\n\n");
      return (-1);
    }

  if ((qt < 1) || (qt > 1000000))
    {
      printf ("ERR-Tem de ser maior que 0 e menor ou igual a 1 000 000.\n");
      return (-1);
    }

  t0 = time (NULL);
  srand (t0);

  /* Geral Numeros Aleatorios */

  for (i1 = 0 ; i1 < qt ; ++i1)
    r1[i1] = rand ();
  printf ("Acabou de gerar %d numeros aleatorios   (Pt: %p)\n", qt, r1);

  /* Fazer Ordenacao */

  t1 = time (NULL);
  bubble_sort (r1, qt);
  t2 = time (NULL);
  printf ("Tempo a ordenar os %d aleatorios: %ld s\n", qt, t2 - t1);

  if (qt <= 100)
    for (i1 = 0 ; i1 < qt ; ++i1)
      printf ("%3d - %10d\n", i1, r1[i1]);

  return 0;
}
