/******************************************
 *                                        *
 *     Exemplo do declinio radioactivo    *
 *     Metodo de Euler                    *
 *                                        *
 *     Versao: 1.0                        *
 *     Samuel Eleuterio 2008              *
 *                                        *
 ******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define FNAME_DATA       "Prog30_02__Data.txt"
#define GNUPLOT_COMMAND  "gnuplot Prog30_02__Gnuplot"

typedef struct
{
  double  x0 ;
  double  x1 ;
  double  t0 ;
  double  tf ;
  double  dt ;
  double  b  ;
} Valores ;

void
show_help (int status)
{
  printf ("\n");
  printf ("  Prog30_01 - Resolucao da equacao diferencial: dx/dt = - b x\n");
  printf ("    Argumentos:\n");
  printf ("      -x0=<valor>   : Valor inicial de 'x'\n");
  printf ("      -t0=<valor>   : Valor inicial de 't'\n");
  printf ("      -tf=<valor>   : Valor final de 't'\n");
  printf ("      -dt=<valor>   : Valor do incremento 'dt'\n");
  printf ("      -b=<valor>    : Taxa de desintegracoo\n");
  printf ("  Exemplos:\n");
  printf ("    Prog30_02 -x0=10.   -t0=0. -tf=10 -b=0.5 -dt=1\n");
  printf ("    Prog30_02 -x0=1000. -t0=0. -tf=30 -b=0.1 -dt=5 \n");
  printf ("\n");
  exit (status);
}

Valores *
args_get_values (int argc, char **argv)
{
  int       n1, test_x0, test_t0     ;
  int       test_tf, test_dt, test_b ;
  Valores  *dados                    ;

  dados = (Valores *) calloc (1, sizeof (Valores));
  test_x0 = test_t0 = test_tf = test_dt = test_b = 0;

  n1 = 1;
  while (n1 < argc)
    {
      if ((strncmp (argv[n1], "-x0=", 4) == 0) && 
          (sscanf (&argv[n1][4], "%lg", &dados->x0) == 1))
	test_x0 = 1;
      else if ((strncmp (argv[n1], "-t0=", 4) == 0) && 
	       (sscanf (&argv[n1][4], "%lg", &dados->t0) == 1))
	test_t0 = 1;
      else if ((strncmp (argv[n1], "-tf=", 4) == 0) && 
	       (sscanf (&argv[n1][4], "%lg", &dados->tf) == 1))
	test_tf = 1;
      else if ((strncmp (argv[n1], "-dt=", 4) == 0) && 
	       (sscanf (&argv[n1][4], "%lg", &dados->dt) == 1))
	test_dt = 1;
      else if ((strncmp (argv[n1], "-b=", 3) == 0) && 
	       (sscanf (&argv[n1][3], "%lg", &dados->b) == 1))
	test_b = 1;
      else 
	{
	  printf ("ERR-Argumento invalido: '%s'\n", argv[n1]);
          show_help (-1);
	}
      ++n1;
    }

  if (test_x0 == 0)
    {
      printf ("Nao inicializou 'x0'\n");
      show_help (-1);
    }

  if (test_t0 == 0)
    {
      printf ("Nao inicializou 't0'\n");
      show_help (-1);
    }

  if (test_tf == 0)
    {
      printf ("Nao inicializou 'tf'\n");
      show_help (-1);
    }

  if (test_dt == 0)
    {
      printf ("Nao inicializou 'dt'\n");
      show_help (-1);
    }

  if (test_b == 0)
    {
      printf ("Nao inicializou 'b'\n");
      show_help (-1);
    }

  return dados;
}

int
main (int argc, char **argv)
{
  double    t, x, y, z, k1, k2 ;
  FILE     *fich1              ;
  Valores  *dados              ;

  dados = args_get_values (argc, argv);

  if (!(fich1 = fopen (FNAME_DATA, "wt")))
    {
      printf ("ERR-Nao conseguiu abrir a file '%s'\n", FNAME_DATA);
      return -1;
    }

/* 
     x -> solucao aproximada Euler
     z -> solucao aproximada Runge-K (2)
     y -> solucao exacta
*/

  t = dados->t0;
  x = y = z = dados->x0;
  fprintf (fich1, "%12.4le  %12.4le  %12.4le  %12.4le\n", t, x, z, y);
  while (t < dados->tf)
    {
      x = x - dados->b * x * dados->dt;

      k1 = - dados->b * dados->dt * z;
      k2 = - dados->b * dados->dt * (z + (k1 / 2.));
      z = z + k2;

      t += dados->dt;
      y = dados->x0 * exp(-dados->b * (t - dados->t0));

      fprintf (fich1, "%12.4le  %12.4le  %12.4le  %12.4le\n", t, x, z, y);
    }

  fclose (fich1);

  system (GNUPLOT_COMMAND);

  return 0;
}
