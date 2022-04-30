/***********************************************
 *                                             *
 *      Converte polegadas em centimetros      *
 *      com ciclo e leitura do teclado         *
 *                                             *
 *      Versao: 1.3                            *
 *      Samuel Eleuterio                       *
 *                                             *
 ***********************************************/

#include <stdio.h>

int
main ()
{
  int    teste1, teste2, teste3 ;
  float  p, c, dp, pf ;

  // Leitura dos dados
  
  printf ("Qual o primeiro valor para as polegadas que deseja? ");
  teste1 = scanf ("%f", &p);

  printf ("Qual o último valor para as polegadas que deseja? ");
  teste2 = scanf ("%f", &pf);

  printf ("Qual o incremento que deseja? ");
  teste3 = scanf ("%f", &dp);

  // Testes de leitura correcta
  
  printf ("Inicio: %f  ;  Fim: %f  ;  Inc: %f (Com testes: %d, %d e %d)\n", 
          p, pf, dp, teste1, teste2, teste3);

  if ((teste1 + teste2 + teste3) != 3)
    {
      printf ("Números não correctos!\n");
      return 1;
    }

  // Resultados
  
  printf ("\n");
  printf ("Tabela de Conversão de Polegadas em Centimetros\n");
  while (p <= pf)
    {
      c = 2.54 * p;
      printf ("   %5.2f in <--> %5.2f cm\n", p, c);
      p = p + dp;
    }
  printf ("\n");

  return 0;
}
