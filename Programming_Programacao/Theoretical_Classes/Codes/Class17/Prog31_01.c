/**************************************************
 *                                                *
 *     Exemplo da queda de um corpo com atrito    *
 *     Metodo de Euler                            *
 *                                                *
 *     Versao: 1.0                                *
 *     Samuel Eleuterio 2008                      *
 *                                                *
 **************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FNAME_DATA       "Prog31_01__Data.txt"
#define GNUPLOT_COMMAND  "gnuplot Prog31_01__Gnuplot"

#define G_TERRA    9.8

#define SIGNAL(a) (((a) < 0) ? (-1) : 1)

typedef struct
{
  double  t0     ;
  double  tf     ;
  double  x0     ;
  double  v0     ;
  double  b1     ;
  double  dt     ;
  double  massa  ;
  double  atrito ;
} Valores ;

//double t0, tf, x0, v0, b1, m1, dt, massa, atrito ;

void
show_help (int status)
{
  printf ("\n");
  printf ("  Prog31_01 -m=<massa> -b=<atrito> -x0=<pos inic> -v0=<vel inic> \n");
  printf ("            -t0=<instante inic> -t0=<instante final> -dt=<delta t>\n");
  printf ("\n");
  printf ("  Exemplo: Prog31_01 -m=1 -x0=20 -v0=40 -t0=0 -tf=10 -b=0.03 -dt=0.3\n");
  printf ("  Exemplo: Prog31_01 -m=1 -x0=20 -v0=40 -t0=0 -tf=10 -b=0.03 -dt=0.1\n");
  printf ("  Exemplo: Prog31_01 -m=1 -x0=20 -v0=40 -t0=0 -tf=10 -b=0.03 -dt=0.01\n");
  printf ("\n");
  exit (status);
}

Valores *
tira_argumentos (int argc, char **argv)
{
  int      n1, test_m, test_b, test_x0, test_v0, test_dt, test_t0, test_tf ;
  Valores *dados                                                           ;

  dados = (Valores *) calloc (1, sizeof (Valores));
  test_m = test_b = test_x0 = test_v0 = test_dt = test_t0 = test_tf = 0;
  if (argc == 1)
    show_help (-1);

  n1 = 1;
  while (n1 < argc)
    {
      if ((strncmp (argv[n1], "-x0=", 4) == 0) && 
          (sscanf (&argv[n1][4], "%lg", &dados->x0) == 1))
	test_x0 = 1;
      else if ((strncmp (argv[n1], "-v0=", 4) == 0) && 
          (sscanf (&argv[n1][4], "%lg", &dados->v0) == 1))
	test_v0 = 1;
      else if ((strncmp (argv[n1], "-m=", 3) == 0) && 
          (sscanf (&argv[n1][3], "%lg", &dados->massa) == 1))
	test_m = 1;
      else if ((strncmp (argv[n1], "-b=", 3) == 0) && 
          (sscanf (&argv[n1][3], "%lg", &dados->atrito) == 1))
	test_b = 1;
      else if ((strncmp (argv[n1], "-dt=", 4) == 0) && 
          (sscanf (&argv[n1][4], "%lg", &dados->dt) == 1))
	test_dt = 1;
      else if ((strncmp (argv[n1], "-t0=", 4) == 0) && 
          (sscanf (&argv[n1][4], "%lg", &dados->t0) == 1))
	test_t0 = 1;
      else if ((strncmp (argv[n1], "-tf=", 4) == 0) && 
          (sscanf (&argv[n1][4], "%lg", &dados->tf) == 1))
	test_tf = 1;
      else
	{
          printf ("\nERR-Argumento incorrecto: '%s'\n", argv[n1]);
          show_help (-1);
	}
      ++n1;
    }

  if (test_m == 0)
    {
      printf ("\nERR-Nao indicou a massa.\n");
      show_help (-1);
    }
  if (test_b == 0)
    {
      printf ("\nERR-Nao indicou a constante de atrito.\n");
      show_help (-1);
    }
  if (test_x0 == 0)
    {
      printf ("\nERR-Nao indicou a posicao inicial.\n");
      show_help (-1);
    }
  if (test_v0 == 0)
    {
      printf ("\nERR-Nao indicou a velocidade inicial.\n");
      show_help (-1);
    }
  if (test_dt == 0)
    {
      printf ("\nERR-Nao indicou o acrescimo no tempo.\n");
      show_help (-1);
    }
  if (test_t0 == 0)
    {
      printf ("\nERR-Nao indicou o instante inicial.\n");
      show_help (-1);
    }
  if (test_tf == 0)
    {
      printf ("\nERR-Nao indicou o instante final.\n");
      show_help (-1);
    }

  return dados;
}

int
main (int argc, char **argv)
{
  double    x1, v1, x2, v2, y1, y2 ;
  double    u1, u2, bm, t1, z1     ;
  FILE     *fich1                  ;
  Valores  *dados                  ;

  dados = tira_argumentos (argc, argv);

  if (!(fich1 = fopen (FNAME_DATA, "wt")))
    {
      printf ("\nERR-Nao conseguiu abrir o ficheiro '%s' para escrita\n", FNAME_DATA);
      return 0;
    }

/*
  x1, x2, v1, v2 -> Metodo de Euler
  y1, y2, u1, u2 -> Metodo de Euler-Cromer
  z1, z2         -> Queda ser atrito
*/

  t1 = dados->t0;
  v1 = u1 = dados->v0;
  x1 = y1 = z1 = dados->x0;
  bm = dados->atrito / dados->massa;
  fprintf (fich1, "%12.4f  %12.4f  %12.4f  %12.4f\n", dados->t0, x1, y1, z1);

  while (t1 < dados->tf)
    {
      v2 = v1 - (G_TERRA + bm * v1 * v1 * SIGNAL (v1)) * dados->dt;
      x2 = x1 + v1 * dados->dt;

      u2 = u1 - (G_TERRA + bm * u1 * u1 * SIGNAL (u1)) * dados->dt;
      y2 = y1 + u2 * dados->dt;

      t1 += dados->dt;
      z1 = dados->x0 + dados->v0 * (t1 - dados->t0) - G_TERRA * (t1 - dados->t0) * (t1 - dados->t0) / 2.;

      fprintf (fich1, "%12.4f  %12.4f  %12.4f  %12.4f\n", t1, x2, y2, z1);

      v1 = v2;
      x1 = x2;
      u1 = u2;
      y1 = y2;
    }

  fclose (fich1);

  system (GNUPLOT_COMMAND);
  printf ("\n");

  return 0;
}
