/***********************************************
 *                                             *
 *      Converte polegadas em centimetros      *
 *      com ciclo e leitura do teclado         *
 *                                             *
 *      Versao: 1.2                            *
 *      Samuel Eleuterio                       *
 *                                             *
 ***********************************************/

#include <stdio.h>

int
main ()
{
  int    teste1, teste2 ;
  float  p, c, dp ;

  // Leitura dos dados
  
  printf ("Qual o primeiro valor para as polegadas que deseja? ");
  teste1 = scanf ("%f", &p);

  printf ("Qual o incremento que deseja? ");
  teste2 = scanf ("%f", &dp);

  printf ("Inicio: %f  ;  Increm.: %f (Com testes: %d e %d)\n", p, dp, teste1, teste2);

  // Testes de leitura correcta

  if ((teste1 + teste2) != 2)
    {
      printf ("Numeros nao correctos!\n");
      return 1;
    }

  // Resultados
  
  printf ("\n");
  printf ("Tabela de Conversao de Polegadas em Centimetros\n");
  while (p <= 10.)
    {
      c = 2.54 * p;
      printf ("   %5.2f in <--> %5.2f cm\n", p, c);
      p = p + dp;
    }
  printf ("\n");

  return 0;
}
