/***********************************************
 *                                             *
 *      Converte polegadas em centimetros      *
 *      com ciclo e leitura do teclado         *
 *                                             *
 *      Versao: 1.5                            *
 *      Samuel Eleuterio                       *
 *                                             *
 ***********************************************/

#include <stdio.h>

int
main ()
{
  int    teste        ;
  float  p, c, dp, pf ;

  // Leitura dos dados
  
  printf ("Polegadas-Centimetros\n");
  printf ("  Escreva (primeiro, ultimo, incremento): ");
  teste = scanf ("%f,%f,%f", &p, &pf, &dp);

  // Testes de leitura correcta
  
  printf ("Inicio: %f  ;  Fim: %f  ;  Inc: %f (Com teste: %d)\n", 
          p, pf, dp, teste);

  if (teste != 3)
    {
      printf ("Numeros nao correctos!\n");
      return 1;
    }

  // Resultados
  
  printf ("\n");
  printf ("Tabela de Conversao de Polegadas em Centimetros\n");
  while (p <= pf)
    {
      c = 2.54 * p;
      printf ("   %5.2f in <--> %5.2f cm\n", p, c);
      p = p + dp;
    }
  printf ("\n");

  return 0;
}
