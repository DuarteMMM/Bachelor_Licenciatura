/********************************************
 *                                          *
 *     Passagem por referencia e por valor  *
 *                                          *
 *     Versao: 1.0                          *
 *     Joao Seixas 2004                     *
 *     Samuel Eleuterio 2008                *
 *                                          *
 ********************************************/

#include <stdio.h>

int g1 = 1;

int
change_val (int *i ,
            int  j ,
            int  k )
{
  ++(*i);
  ++j;
  ++g1;
  ++k;

  printf ("  Dentro da funcao 'change_val': i1 = %d ; i2 = %d ; i3 = %d ; g1 = %d\n\n", *i, j, k, g1);

  return k;
}

int
main ()
{
  int i1, i2, i3 ;

  i1 = 1;
  i2 = 1;
  i3 = 1; 

  printf ("\n");
  printf ("  Antes de chamar 'change_val':  i1 = %d ; i2 = %d ; i3 = %d ; g1 = %d\n\n", i1, i2, i3, g1);

  i3 = change_val (&i1, i2, i3);

  printf ("  Depois de chamar 'change_val': i1 = %d ; i2 = %d ; i3 = %d ; g1 = %d\n\n", i1, i2, i3, g1);

  return 0;
}
