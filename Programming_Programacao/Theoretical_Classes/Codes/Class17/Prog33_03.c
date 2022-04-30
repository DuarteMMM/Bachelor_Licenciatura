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

#define FNAME_DATA       "Prog33_03__Data.txt"
#define GNUPLOT_COMMAND  "gnuplot Prog33_03__Gnuplot"

typedef struct
{
  double  x0 ;
  double  xf ;
  double  z0 ;
  double  dx ;
} Valores ;

/****************************************************************/

double 
funcao (double x, double t)
{
  return x;
}

double 
RungeKutta2 (double (*func) (double , double ) ,
             double x1                         ,
             double t1                         ,
             double h                          )
{
  double x2, k1, k2 ;

  k1 = h * func (x1, t1);
  k2 = h * func (x1 + k1 / 2., t1 + h / 2.);
  x2 = x1 + k2;

  return x2;
}

double 
RungeKutta4 (double (*func) (double , double ) ,
             double x1                         ,
             double t1                         ,
             double h                          )
{
  double x2, k1, k2, k3, k4 ;

  k1 = h * func (x1, t1);
  k2 = h * func (x1 + k1 / 2., t1 + h / 2.);
  k3 = h * func (x1 + k2 / 2., t1 + h / 2.);
  k4 = h * func (x1 + k3, t1 + h);

  x2 = x1 + (k1 + k4 + 2. * (k2 + k3)) / 6.;

  return x2;
}

/******************************************************************/

void
show_help (int status)
{
  printf ("\n");
  printf ("  Prog33_03 -x0=<x inic> -xf=<x final> -y0=<Valor inicial> -dx=<incremento>\n");
  printf ("\n");
  printf ("    Exemplos:\n");
  printf ("      Prog33_03 -x0=0 -xf=8 -z0=1 -dx=0.2\n");
  printf ("      Prog33_03 -x0=0 -xf=8 -z0=1 -dx=0.1\n");
  printf ("      Prog33_03 -x0=0 -xf=8 -z0=1 -dx=0.01\n");
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
  double    z1, z2, w1, w2 ;
  FILE     *fich1          ;
  Valores  *dados          ;

  dados = tira_argumentos (argc, argv);

  if (!(fich1 = fopen (FNAME_DATA, "wt")))
    {
      printf ("\nERR-Nao consegui abrir a file '%s' para escrita\n", FNAME_DATA);
      return 0;
    }

  /*
     Crescimento          y(x+dx) - y(x)
                    ==>   -------------- = y(x)     ==>    y(x+dx) = y(x) + y(x) * dx
     exponencial                dx
   */

  x1 = dados->x0;
  y1 = z1 = w1 = dados->z0;
  s1 = dados->z0;
  fprintf (fich1, "%12.4f  %12.4f  %12.4f  %12.4f  %12.4f\n", x1, y1, z1, w1, s1);
  while (x1 < dados->xf)
    {
      // Metodo de Euler / Euler-Cromer
      y2 = y1 + y1 * dados->dx;

      // Metodo de Runge-Kutta 2a Ordem
      z2 = RungeKutta2 (funcao, z1, x1, dados->dx);

      // Metodo de Runge-Kutta 4a Ordem
      w2 = RungeKutta4 (funcao, w1, x1, dados->dx);

      // Solucao exacta - exponencial
      x1 += dados->dx;
      s1 = dados->z0 * exp (x1-dados->x0);

      //printf ("z1: %lf ; z2: %lf  ===>  w1: %lf ; w2: %lf  ===> %lf\n",z1,z2,w1,w2,exp(x1));
      fprintf (fich1, "%12.4f  %12.4f  %12.4f  %12.4f  %12.4f\n", x1, y2, z2, w2, s1);
      y1 = y2;
      z1 = z2;
      w1 = w2;
    }

  fclose (fich1);

  system (GNUPLOT_COMMAND);

  return 0;
}
