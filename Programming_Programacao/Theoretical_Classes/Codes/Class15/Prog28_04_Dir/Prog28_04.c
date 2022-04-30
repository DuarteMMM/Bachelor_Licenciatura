/********************************************
 *                                          *
 *      Funcao: Ponteiros para Funcoes      *
 *              Estruturas                  *
 *                                          *
 *      Versao: 1.2                         *
 *      Samuel Eleuterio 2008               *
 *                                          *
 ********************************************/

#include <stdio.h>
#include <stdlib.h>

#include "Prog28_04_FazContas.h"

void
show_help (int status)
{
  printf ("\n\n  Prog27_04 <valor> <operacao (+, -, x, /)> <valor>\n\n");
  exit (status);
}

int
main ()
{
  char         ch1        ;
  int          i1         ;
  double       x1, x2, x3 ;
  FazContas   *contas     ;

  contas = FazContas_cria ();

  while (1)
    {
      printf ("Escreva a conta a efectuar [x1 oper x2 ; Sair: 'q']: ");
      i1 = scanf ("%lf %c %lf", &x1, &ch1, &x2);
      if ((i1 == 0) && (getchar () == 'q'))
	break;

      //printf ("x1: %lf  ;  oper: %c  ;  x2: %lf\n", x1, ch1, x2);

      if (i1 != 3)
	{
	  while (getchar () != 10);
          printf ("\n  **** Expressao invalida ****\n\n");
	  continue;
	}
      if (FazContas_marca_oper (contas, ch1) == -1)
	{
          printf ("\n  **** Operador invalido ****\n\n");
	  continue;
	}

      FazContas_guarda (contas, x1, x2);
      if (FazContas_executa (contas) == -1)
	{
          printf ("\n  **** Operador invalido ****\n\n");
	  continue;
	}

      x3 = FazContas_da_resultado (contas);
      printf ("\n  Resultado: %lf\n\n", x3);
    }

  FazContas_destroi_versao1 (contas);
  /* FazContas_destroi_versao2 (&contas); */

  return 0;
}

