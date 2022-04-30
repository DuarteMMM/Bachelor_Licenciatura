
/*****************************************************
 *                                                   *
 *      Strings e Funcoes                            *
 *                                                   *
 *      Versao: 1.0                                  *
 *      Samuel Eleuterio 2017                        *
 *                                                   *
 *****************************************************/

#include <stdio.h>
#include <string.h>

int main ()
{
  int     t1, n1, n2 ;
  double  x1         ;
  char   *str1 = "Sao 12, 15 e 7.3";
  char    str2[64] ;

  t1 = sscanf (str1, "Sao %d, %d e %lf", &n1, &n2, &x1);

  printf ("\n");
  printf ("O teste de leitura deu: %d.", t1);
  printf ("\nOs valores lidos foram:\n");
  printf ("  n1: %d  ;  n2: %d  ;  x1: %lf\n", n1, n2, x1);  
  printf ("\n");

  sprintf (str2, "O resultado da leitura deu: %d, %d, %lf", n1, n2, x1); 

  printf ("O resultado da escrita na string foi:\n  '%s'\n\n", str2);

  return 0;
}
