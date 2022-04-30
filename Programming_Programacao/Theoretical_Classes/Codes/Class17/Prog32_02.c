/*
     Programa para testar a eficiencia de calculo
     com a funcao logistica
     Programa 8.5
     
      Autor: J. Seixas 2004
*/

#include <stdio.h>
#include <time.h>

int main()
{
  long int  i      ;
  double    x=.51  ;
  time_t    ti, tf ;
  time_t    t1, t2 ;
  
  ti = time (NULL);
  t1 = clock();

  for (i = 1 ; i <= 20000000 ; ++i) 
    x *= 8. * (1.-x) / 3.;

  t2 = clock();
  tf = time (NULL);
  printf ("\nCalculo sem escrita:\n"); 
  printf ("  Tempo (CPU): %lf s; real : %lg s\n\n", 
          (t2 - t1) / ((double) CLOCKS_PER_SEC), difftime(tf,ti));
  //printf ("x: %lf\n", x);

  return 0;
}
