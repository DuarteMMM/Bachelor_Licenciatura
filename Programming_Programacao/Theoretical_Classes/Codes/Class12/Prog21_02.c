/*****************************************************
 *                                                   *
 *      Exemplo de constantes                        *
 *                                                   *
 *      Versao: 1.0                                  *
 *      Samuel Eleuterio 2014                        *
 *                                                   *
 *****************************************************/

#include <stdio.h>
#include <stdlib.h>

void
func1 (int conta)
{
  static int i1 = 9 ;
  int i2 = 17 ;

  ++i1;
  ++i2;

  printf ("Conta:%3d  -  i1:%3d  -  i2:%3d\n", conta, i1, i2);
}

int 
main (int argc, char **argv)
{
  int n, quantos ;

  if ((argc != 2) || (sscanf (argv[1], "%d", &quantos) != 1))
    {
      printf ("\n    Prog21_02 <quantos>\n\n");
      exit (0);
    }

  for (n = 0 ; n < quantos ; ++n)
    func1 (n);

  return 0;
}
