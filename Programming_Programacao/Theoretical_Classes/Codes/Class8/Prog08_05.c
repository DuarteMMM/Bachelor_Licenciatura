/***********************************************
 *                                             *
 *      Meu Segundo Programa em C              *
 *      Para gerar números aleatórios          *
 *                                             *
 *      Versao: 1.1                            *
 *      Samuel Eleuterio 2008                  *
 *                                             *
 ***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int 
main ()
{
  int     i1, qt, teste   ;
  int     r0, r1[1000000] ;
  time_t  t0, t1, t2      ;

  printf ("Quantos aleatorios quer gerar? [Máximo 1 000 000]: ");
  teste = scanf ("%d", &qt);
  if ((teste != 1) || (qt < 1) || (qt > 1000000))
    {
      printf ("ERR-Tem de ser maior que 0 e menor ou igual a 1 000 000.\n");
      return (-1);
    }

  t0 = time (NULL);
  srand (t0);

  // Geral Numeros Aleatorios

  for (i1 = 0 ; i1 < qt ; ++i1)
    {
      r1[i1] = rand ();
      //printf ("%2d - %d\n", i1, r1[i1]);
    }
  t1 = time (NULL);
  printf ("Acabou de gerar %d numeros aleatorios. Tempo: %ld s\n", qt, t1 - t0);
  
  // Fazer Ordenacao por Bubble Sort

  while (1)
    {
      teste = 0;
      for (i1 = 0 ; i1 < qt - 1 ; ++i1)
	{
          if (r1[i1] > r1[i1+1])
	    {
              //  Trocar r1[i1] com r1[i1 + 1]
              r0 = r1[i1];
              r1[i1] = r1[i1+1];
              r1[i1+1] = r0;
	      teste = 1;
	    }
	}
      if (teste == 0)
	break;
    }
  t2 = time (NULL);

  // Mostrar resultados

  if (qt <= 30)
    for (i1 = 0 ; i1 < qt ; ++i1)
      printf ("%3d - %10d\n", i1, r1[i1]);

  printf ("Tempo a ordenar os %d aleatorios: %ld s\n", qt, t2 - t1);

  return 0;
}
