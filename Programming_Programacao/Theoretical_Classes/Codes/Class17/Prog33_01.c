/****************************************
 *                                      *
 *     Exemplo da Funcao Exponencial    *
 *     Metodo de Euler                  *
 *                                      *
 *     Versao: 1.0                      *
 *     Samuel Eleuterio 2008            *
 *                                      *
 ****************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define FNAME_DATA       "Prog33_01__Data.txt"
#define GNUPLOT_COMMAND  "gnuplot Prog33_01__Gnuplot"

typedef struct
{
  double  x0 ;
  double  xf ;
  double  z0 ;
  double  dx ;
} Valores ;

void
show_help (int status)
{
  printf ("\n");
  printf ("  Prog33_01 -x0=<x inic> -xf=<x final> -y0=<Valor inicial> -dx=<incremento>\n");
  printf ("\n");
  printf ("    Exemplos:\n");
  printf ("      Prog33_01 -x0=0 -xf=8 -z0=1 -dx=0.01\n");
  printf ("      Prog33_01 -x0=0 -xf=8 -z0=1 -dx=0.1\n");
  printf ("\n");
  exit (status);
}

Valores *
tira_argumentos (int argc, char **argv)
{
  int      n1, test_x0, test_xf, test_z0, test_dx ;
  Valores *dados                                  ;

  dados = (Valores *) calloc (1, sizeof (Valores));
  test_x0 = test_xf = test_dx = test_z0 = 0;

  if (argc == 1)
    show_help (-1);

  n1 = 1;
  while (n1 < argc)
    {
      if ((strncmp (argv[n1], "-x0=", 4) == 0) && 
          (sscanf (&argv[n1][4], "%lg", &dados->x0) == 1))
	test_x0 = 1;
      else if ((strncmp (argv[n1], "-xf=", 4) == 0) && 
          (sscanf (&argv[n1][4], "%lg", &dados->xf) == 1))
	test_xf = 1;
      else if ((strncmp (argv[n1], "-dx=", 4) == 0) && 
          (sscanf (&argv[n1][4], "%lg", &dados->dx) == 1))
	test_dx = 1;
      else if ((strncmp (argv[n1], "-z0=", 4) == 0) && 
          (sscanf (&argv[n1][4], "%lg", &dados->z0) == 1))
	test_z0 = 1;
      else
	{
          printf ("\nERR-Argumento incorrecto: '%s'\n", argv[n1]);
          show_help (-1);
	}
      ++n1;
    }

  if (test_x0 == 0)
    {
      printf ("\nERR-Nao indicou o 'x' inicial.\n");
      show_help (-1);
    }
  if (test_xf == 0)
    {
      printf ("\nERR-Nao indicou o 'x' final.\n");
      show_help (-1);
    }
  if (test_dx == 0)
    {
      printf ("\nERR-Nao indicou o acrescimo em 'x'.\n");
      show_help (-1);
    }
  if (test_z0 == 0)
    {
      printf ("\nERR-Nao indicou a condicao inicial inicial.\n");
      show_help (-1);
    }

  return dados;
}

int
main (int argc, char **argv)
{
  double    x1, y1, y2, s1 ;
  FILE     *fich1          ;
  Valores  *dados          ;

  dados = tira_argumentos (argc, argv);

  if (!(fich1 = fopen (FNAME_DATA, "wt")))
    {
      printf ("\nERR-Nao consegui abrir a file '%s' para escrita\n", FNAME_DATA);
      return 0;
    }

  printf ("x0: %lf ; xf: %lf ; y0: %lf ; dx: %lf\n", 
          dados->x0, dados->xf, dados->z0, dados->dx);

  /*
     Crescimento          y(x+dx) - y(x)
                    ==>   -------------- = y(x)     ==>    y(x+dx) = y(x) + y(x) * dx
     exponencial                dx
   */

  x1 = dados->x0;      
  y1 = dados->z0;      // Solucao aproximada
  s1 = dados->z0;      // Solucao exacta
  
  fprintf (fich1, "%12.4f  %12.4f  %12.4f\n", x1, y1, s1);

  while (x1 < dados->xf)
    {
      y2 = y1 + y1 * dados->dx;
      x1 += dados->dx;
      s1 = dados->z0 * exp (x1-dados->x0);

      fprintf (fich1, "%12.4f  %12.4f  %12.4f\n", x1, y2, s1);
      y1 = y2;
    }

  fclose (fich1);

  system (GNUPLOT_COMMAND);

  return 0;
}
