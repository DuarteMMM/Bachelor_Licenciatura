/***********************************************
 *                                             *
 *      Converte polegadas em centimetros      *
 *      com ciclo e leitura do teclado         *
 *                                             *
 *      Versao: 1.1                            *
 *      Samuel Eleuterio                       *
 *                                             *
 ***********************************************/

#include <stdio.h>

int
main ()
{
  int    teste ;
  float  p, c  ;

  // Leitura dos dados
  
  printf ("Qual o primeiro valor para as polegadas que deseja? ");
  teste = scanf ("%f", &p);
  printf ("Leu: %f  (Com teste: %d)\n", p, teste);

  // Teste de leitura correcta
  
  if (teste != 1)
    {
      printf ("Nao deu um numero!\n");
      return 1;
    }

  // Resultados
  
  printf ("\n");
  printf ("Tabela de Conversao de Polegadas em Centimetros\n");
  while (p <= 10.)
    {
      c = 2.54 * p;
      printf ("   %5.2f in <--> %5.2f cm\n", p, c);
      p = p + 1.;
    }
  printf ("\n");

  return 0;
}
