/*****************************************************
 *                                                   *
 *      Programa em C                                *
 *      Para gerar números aleatórios                *
 *                                                   *
 *      E ordena-los com o algoritmo 'quick_sort'    *
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

void
quick_sort (int *r1  ,
            int  esq ,
            int  dir )
{
  int  i, j, m ;
  int  rm ;

  i = esq;
  j = dir;
  m = (esq + dir) / 2;
  rm = r1[m];
  while (i <= j)
    {
      while (r1[i] < rm)
	++i;
      while (rm < r1[j])
	--j;
      if (i <= j)
	{
          troca_valores (&r1[i], &r1[j]);
          ++i;
	  --j;
	}
    }
  if (esq < j)
    quick_sort (r1, esq, j);
  if (i < dir)
    quick_sort (r1, i, dir);
}

int 
main ()
{
  int     i1, qt      ;
  int     r1[1000000] ;
  time_t  t0, t1, t2  ;

  printf ("Quantos aleatorios quer gerar? [Máximo 1 000 000]: ");
  scanf ("%d", &qt);
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
  t1 = time (NULL);
  printf ("Acabou de gerar %d numeros aleatorios\n", qt);

  /* Fazer Ordenacao por Quick Sort */

  quick_sort (r1, 0, qt - 1);

  t2 = time (NULL);
  
  printf ("Tempo a ordenar os %d aleatorios: %ld s\n", qt, t2 - t1);

  if (qt <= 100)
    for (i1 = 0 ; i1 < qt ; ++i1)
      printf ("%2d - %d\n", i1, r1[i1]);
  else
    {
      printf ("Os primeiros 20 elementos sao:\n");
      for (i1 = 0 ; i1 < 20 ; ++i1)
	printf ("%2d - %d\n", i1, r1[i1]);
    }

  return 0;
}
