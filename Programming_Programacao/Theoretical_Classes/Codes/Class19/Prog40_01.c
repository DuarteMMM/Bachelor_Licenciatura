/**********************************
 *                                *
 *     Exemplos de <math.h>       *
 *                                *
 *     Versao: 1.0                *
 *     Samuel Eleuterio 2008      *
 *                                *
 **********************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void
help (int status)
{
  printf ("  Prog40_01 <opcao> - Mostra funcoes definidas em 'math.h'\n");
  printf ("    Opcao:\n");
  printf ("      const  : Mostra constantes definidas\n");
  printf ("      trig   : Mostra funcoes trigonometricas\n");
  printf ("      hiper  : Mostra funcoes hiperbolicas\n");
  printf ("      exp    : Mostra funcoes exponencial e logaritmo\n");
  printf ("      outras : Mostra outras funcoes\n");
  printf ("\n");
  exit (status);
}

void
show_constantes (void)
{
  printf ("*** Constantes definidas ***\n");

  printf ("  M_E        (e)            %22.20lf\n", M_E);         /* e          */
  printf ("  M_LOG2E    (log_2 e)      %22.20lf\n", M_LOG2E);     /* log_2 e    */
  printf ("  M_LOG10E   (log_10 e)     %22.20lf\n", M_LOG10E);    /* log_10 e   */
  printf ("  M_LN2      (log_e 2)      %22.20lf\n", M_LN2);       /* log_e 2    */
  printf ("  M_LN10     (log_e 10)     %22.20lf\n", M_LN10);      /* log_e 10   */
  printf ("  M_PI       (pi)           %22.20lf\n", M_PI);        /* pi         */
  printf ("  M_PI_2     (pi/2)         %22.20lf\n", M_PI_2);      /* pi/2       */
  printf ("  M_PI_4     (pi/4)         %22.20lf\n", M_PI_4);      /* pi/4       */
  printf ("  M_1_PI     (1/pi)         %22.20lf\n", M_1_PI);      /* 1/pi       */
  printf ("  M_2_PI     (2/pi)         %22.20lf\n", M_2_PI);      /* 2/pi       */
  printf ("  M_2_SQRTPI (2/sqrt(pi))   %22.20lf\n", M_2_SQRTPI);  /* 2/sqrt(pi) */
  printf ("  M_SQRT2    (sqrt(2))      %22.20lf\n", M_SQRT2);     /* sqrt(2)    */
  printf ("  M_SQRT1_2  (1/sqrt(2))    %22.20lf\n", M_SQRT1_2);   /* 1/sqrt(2)  */

  printf ("\n");
  printf ("  HUGE_VAL (%%lg): %lg\n", HUGE_VAL);
  printf ("  INFINITY (%%lg): %lg\n", INFINITY);
  printf ("  NAN      (%%lg): %lg\n", NAN);
  printf ("\n");
}


void
show_trigonometricas (void)
{
  double  x1, x2 ;

  printf ("*** Funcoes trigonometricas ***\n");

  x1 = M_PI / 6.;
  x2 = 0.5;
  printf ("  %lf = sin (%g);\n", sin (x1), x1);
  printf ("  %lf = cos (%g);\n", cos (x1), x1);
  printf ("  %lf = tan (%g);\n", tan (x1), x1);
  printf ("\n");

  printf ("  %lf = asin (%g);\n", asin (x2), x2);
  printf ("  %lf = acos (%g);\n", acos (x2), x2);
  printf ("  %lf = atan (%g);\n", atan (x2), x2);
  printf ("  %lf = atan2 (%g, %g);   ( atan2 (x1, x2)  <==>  atan (x1/x2), com sinais do quadrantes )\n", 
          atan2 (x2, x2 + 1.5), x2, x2 + 1.5);
  printf (" %lf = atan2 (%g, %g);\n", atan2 (-x2, -x2 - 1.5), -x2, -x2 - 1.5);

  printf ("\n");
}

void
show_hiperbolicas (void)
{
  double  x1 ;

  printf ("*** Funcoes hiperbolicas ***\n");

  x1 = 3.5;
  printf ("  %g = sinh (%g)        (e^x - e^-x) / 2\n", sinh (x1), x1);
  printf ("  %g = cosh (%g)        (e^x + e^-x) / 2\n", cosh (x1), x1);
  printf ("  %g = tanh (%g)       sinh (x) / cosh (x)\n", tanh (x1), x1);

  printf ("\n");
}

void
show_exp_log (void)
{
  int     i1, i2         ;
  double  x1, x2, x3, x4 ;
  double  y1, x5         ;

  printf ("***** Funcoes exponencial e logaritmo\n");

  x1 = 1.;
  x2 = M_E;
  x3 = 100.;
  x4 = 15.9;
  x5 = 16.4;
  i2 = 5;

  printf ("  %f = exp (%g);\n", exp (x1), x1);
  printf ("  %f = log (%g);\n", log (x2), x2);
  printf ("  %f = log10 (%g);\n", log10 (x3), x3);
  printf ("\n");
  
  printf ("***** z = frexp (x, &k)  <==>  x = z * 2^k  c/  z em [0.5 , 1.0[\n");
  y1 = frexp (x4, &i1);
  printf ("  %f = frexp (%g, &i1);  ==>  i1 = %d\n", y1, x4, i1);
  y1 = frexp (x5, &i1);
  printf ("  %f = frexp (%g, &i1);  ==>  i1 = %d\n\n", y1, x5, i1);

  printf ("***** z = ldexp (x, k)  <==>   z = x * 2^k  (k --> int)\n");
  printf ("  %f = ldexp (%g, %d);\n", ldexp (x2, i2), x2, i2);
  printf ("  %f = ldexp (%g, %d);\n", ldexp (1, 5), 1., 5);

  printf ("\n");
}

void
show_outras (void)
{
  double  x1, x2, x3, x4 ;
  double  y1, y2, x5     ;

  printf ("*** Funcoes diversas ***\n");

  x1 = 15.8;
  x2 = 3.0;
  x3 = -3.7;
  x4 = 2.1;
  x5 = 2.0;

  y2 = modf (x1, &y1);
  printf ("  %f = modf (%g, &y1);  ==>  y1 = %g \n", y2, x1, y1);
  printf ("  %f = fmod (%g, %g);\n", fmod (x1, x2), x1, x2);
  printf ("  %f = fmod (%g, %g);\n", fmod (x1, x5), x1, x5);
  printf ("\n");

  printf ("  %f = fabs (%g);\n", fabs (x1), x1);
  printf ("  %f = fabs (%g);\n", fabs (x3), x3);
  printf ("\n");

  printf ("  %f = pow (%g, %g);\n", pow (x4, x2), x4, x2); 
  printf ("  %f = sqrt (%g);\n", sqrt (x1), x1); 
  printf ("\n");

  printf ("  %f = ceil (%g);\n", ceil (x1), x1); 
  printf ("  %f = floor (%g);\n", floor (x1), x1); 

  printf ("\n");
}


int
main (int argc, char **argv)
{
  printf ("\n");

  if (argc != 2)
    help (-1);

  if (strcmp (argv[1], "const") == 0)
    show_constantes ();
  else if (strcmp (argv[1], "trig") == 0)
    show_trigonometricas ();
  else if (strcmp (argv[1], "hiper") == 0)
    show_hiperbolicas ();
  else if (strcmp (argv[1], "exp") == 0)
    show_exp_log ();
  else if (strcmp (argv[1], "outras") == 0)
    show_outras ();
  else
    {
      printf ("\nERR-Opcao invalida\n");
      help (-2);
    }

  return 0;
}
