/*
     Programa para testar a eficiencia de calculo com a string 
     usando-se ou nao a funcao 'strlen' na condicao do ciclo.

     Autor: Samuel Eleuterio 2013
*/

#include <stdio.h>
#include <string.h>
#include <time.h>

int main()
{
  long   i, k, qt       ;
  char   str[100], c1   ;
  time_t ti, tf, t1, t2 ;

  for (i = 0 ; i < 90 ; ++i)
    str[i] = 48 + (i % 40);
  str[i] = 0;
  c1 = 'A';

  ti = time (NULL);
  t1 = clock();

  for (i = 1 ; i <= 10000000 ; ++i)
    {
      k = 0;
      qt = 0;
      while (k < strlen(str))
	{
	  if (str[k] == c1)
	    ++qt;
	  ++k;
	}
    }

  t2 = clock();
  tf = time (NULL);
  printf ("\nCalculo usando 'strlen' na condicao do ciclo:\n"); 
  printf ("  Tempo (CPU): %lf s; real : %lg s\n\n", 
          (t2 - t1) / (double) CLOCKS_PER_SEC, difftime(tf,ti));
  //printf ("x: %lf\n", x);

  return 0;
}
