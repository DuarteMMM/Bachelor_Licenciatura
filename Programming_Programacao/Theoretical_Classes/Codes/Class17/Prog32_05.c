/*
     Programa para testar a eficiencia de calculo
     com a funcao logistica
     Programa 8.7
     
      Autor: J. Seixas 2004
*/

#include <stdio.h>
#include <time.h>

int main()
{
  long   i        ;
  double x=.51    ;
  double y        ;
  time_t ti, tf   ;
  time_t t1, t2   ;
  
  ti = time (NULL);
  t1 = clock();

  y = 8./3.;
  for (i = 1 ; i <= 20000000 ; ++i) 
    x *= y * (1.-x);

  t2 = clock();
  tf = time (NULL);
  printf ("\nCalculo sem escrita e com 8./3. -> 2.666666:\n");
  printf ("  Tempo (CPU): %lf s; real : %lg s\n\n", 
          (t2 - t1) / ((double) CLOCKS_PER_SEC), difftime(tf,ti));
  //printf ("x: %lf\n", x);

  return 0;
}
