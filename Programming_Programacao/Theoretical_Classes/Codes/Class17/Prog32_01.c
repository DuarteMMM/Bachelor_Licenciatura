/*
     Programa para testar a precisao da maquina
     Programa 8.2

      Principais variaveis:
       
         x1, x2    variaveis a somar
          i         contador
          
      Autor: J. Seixas 2004
      Samuel Eleuterio 2009, 2016
*/

#include <stdio.h>
#include <stdio.h>

void
teste_long_double (void)
{
  long double x1=1.0L, x2=1.0L, x3;      
  int i=0;

  x3 = x1 + x2;
  while (x3 != x1) 
    {
      ++i;
      x2 = x2 / 10.0L;
      x3 = x1 + x2;
    }
  printf("long double[%ld]: Numero de algarismos significativos precisos: %2d\n",
         sizeof(long double), i);
}

void
teste_double (void)
{
  double x1=1.0, x2=1.0, x3;      
  int i=0;

  x3 = x1 + x2;
  while (x3 != x1) 
    {
      ++i;
      x2 = x2 / 10.;
      x3 = x1 + x2;
    }
  printf("double[%ld]:       Numero de algarismos significativos precisos: %2d\n",
         sizeof(double), i);
}

void
teste_float (void)
{
  float x1=1.0f, x2=1.0f,  x3;
  int i=0;

  x3 = x1 + x2;
  while (x3 != x1) 
    {
      ++i;
      x2 = x2 / 10.f;
      x3 = x1 + x2;
      //printf ("  x1: %.15f ; x3: %.15f ; x2: %.15f ; x1+x2: %.15f\n", x1, x3, x2, x1+x2);
    }
  printf ("float[%ld]:        Numero de algarismos significativos precisos: %2d\n", 
          sizeof(float), i);
}

int main()
{
  printf("\n");
  teste_float();
  teste_double();
  teste_long_double();
  printf("\n");

  return 0;
}
