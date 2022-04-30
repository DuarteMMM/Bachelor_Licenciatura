/********************************************
 *                                          *
 *      Exemplo de Instrucoes Condicionais  *
 *        'if ... else ...'                 *
 *                                          *
 *      Versao: 1.0                         *
 *      Samuel Eleuterio 2008               *
 *                                          *
 ********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
show_help (int status)
{
  printf ("\n  Prog23_02 <Opcao>\n");
  printf ("    Opcao:\n");
  printf ("      so - Somar\n");
  printf ("      su - Subtrair\n");
  printf ("      mu - Multiplicar\n");
  printf ("      di - Dividir\n");
  printf ("\n");

  exit (status);
}


int
main (int argc, char **argv)
{
  double x1, x2 ;

  x1 = 12.;
  x2 = 4.;

  if (argc != 2)
    show_help (-1);

  printf ("\nValores iniciais: %g , %g\n", x1, x2);

  printf ("\n********* Modo2 *********\n\n");

  if (strcmp (argv[1], "so") == 0)
    printf ("V2 - Escolheu a 'somar': %lf\n", x1 + x2);
  else 
    {
      if (strcmp (argv[1], "su") == 0)
        printf ("V2 - Escolheu a 'subtrair': %lf\n", x1 - x2);
      else 
	{
          if (strcmp (argv[1], "mu") == 0)
            printf ("V2 - Escolheu a 'multiplicar': %lf\n", x1 * x2);
          else
	    {
              if (strcmp (argv[1], "di") == 0)
                printf ("V2 - Escolheu a 'dividir': %lf\n", x1 / x2);
              else
                printf ("V2 - A opção que escolheu não é válida!!!!!\n");
	    }
	}
    }

  /*  O que esta' antes e' equivalente a  */

  printf ("\n********* Modo1 *********\n\n");

  if (strcmp (argv[1], "so") == 0)
    printf ("V1 - Escolheu a 'somar': %lf\n", x1 + x2);
  else if (strcmp (argv[1], "su") == 0)
    printf ("V1 - Escolheu a 'subtrair': %lf\n", x1 - x2);
  else if (strcmp (argv[1], "mu") == 0)
    printf ("V1 - Escolheu a 'multiplicar': %lf\n", x1 * x2);
  else if (strcmp (argv[1], "di") == 0)
    printf ("V1 - Escolheu a 'dividir': %lf\n", x1 / x2);
  else
    printf ("V1 - A opcao que escolheu nao e valida!!!!!\n");

  printf ("\n");

  return 0;
}
