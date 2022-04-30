/*
     Programa para testar a eficiencia de calculo
     com a funcao logistica
     Programa 8.3
     
      Autor: J. Seixas 2004
*/

#include <stdio.h>
#include <time.h>

int main()
{
  long   i      ;
  double x=.51  ;
  time_t ti, tf ;
  time_t t1, t2 ;
  
  ti = time (NULL);
  t1 = clock();

  for (i = 1 ; i <= 20000000 ; ++i) 
    printf ("i= %ld : x= %8.6lf\n", i, x *= 8. * (1.-x) / 3.);

  t2 = clock();
  tf = time (NULL);
  printf ("\nCalculo com escrita no ecran:\n");
  printf ("  Tempo (CPU): %lf s; real : %lg s\n\n", 
          (t2 - t1) / (double) CLOCKS_PER_SEC, difftime(tf,ti));
  return 0;
}
