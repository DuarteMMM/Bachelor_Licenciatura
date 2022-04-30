/*
    Programa demonstrando o uso de "<errno.h>"
     
    Autor: J. Seixas 2004
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <errno.h>


double
erro_em_log_errno (void)
{
  char   *str1 = "  ===> funcao log" ;
  double  x, y ;

  x = 0.;
  y = log(x);


  printf ("*** log(0.) - Teste de 'errno.h' ***\n\n");
  printf("log(%lg): %lg\n", x, y);

  if (errno == EDOM)
    printf ("  errno: EDOM\n");
  else if (errno == ERANGE)
    printf ("  errno: ERANGE\n");

  perror(str1);

  printf ("\n  Resultado de 'strerror': %s\n", strerror(errno));

  return y;
}

double
erro_em_acos_errno (void)
{
  char   *str1 = "  ===> funcao acos";
  double  x, y ;

  x = 3.;
  y = acos(x);

  printf ("*** acos(3.) - Teste de 'errno.h' ***\n\n");
  printf("acos(%lg): %lg\n", x, y);

  if (errno == EDOM)
    printf ("  errno: EDOM\n");
  else if (errno == ERANGE)
    printf ("  errno: ERANGE\n");

  perror(str1);

  printf ("\n  Resultado de 'strerror': %s\n", strerror(errno));

  return y;
}

int 
main(int argc, char **argv)
{
  printf ("\n");

  erro_em_acos_errno ();
  printf ("\n\n");

  erro_em_log_errno ();
  printf ("\n");

  return 0;
}
