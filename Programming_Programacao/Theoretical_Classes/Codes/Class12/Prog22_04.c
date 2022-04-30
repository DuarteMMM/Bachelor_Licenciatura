/*****************************************************
 *                                                   *
 *      Exemplos de Operacoes                        *
 *                                                   *
 *      Versao: 1.0                                  *
 *      Samuel Eleuterio 2008                        *
 *                                                   *
 *****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
mostra_bits (void)
{
  int i1, i2, i3, i4 ;

  i1 = 0x2a;   /* 00101010  ==>  0010 1010  ==>  0x2a  ==> 2 * 16 + 10 = 42 */
  i2 = 0x12;   /* 00010010  ==>  0001 0010  ==>  0x12  ==> 1 * 16 +  2 = 18 */
  
  printf ("\n*** Operacoes sobre 'bits' ***\n\n");

  i3 = i1 & i2;
  printf ("  i1 = %d  ;  i2 = %d  ==>  i1 & i2 = %2d\n", i1, i2, i3);
  i3 = i1 | i2;
  printf ("  i1 = %d  ;  i2 = %d  ==>  i1 | i2 = %2d\n", i1, i2, i3);
  i3 = i1 ^ i2;
  printf ("  i1 = %d  ;  i2 = %d  ==>  i1 ^ i2 = %2d\n", i1, i2, i3);

  printf ("\n");
  i3 = 1; 
  i4 = i3 << 1;
  printf ("  i1 = %d  ;  i1 << 1 = %2d\n", i3, i4);
  i4 = i3 << 2;
  printf ("  i1 = %d  ;  i1 << 2 = %2d\n", i3, i4);
  i4 = i3 << 3;
  printf ("  i1 = %d  ;  i1 << 3 = %2d\n", i3, i4);
  i4 = i3 << 4;
  printf ("  i1 = %d  ;  i1 << 4 = %2d\n", i3, i4);
  printf ("\n");

  i3 = 16; 
  i4 = i3 >> 1;
  printf ("  i1 = %d  ;  i1 >> 1 = %d\n", i3, i4);
  i4 = i3 >> 2;
  printf ("  i1 = %d  ;  i1 >> 2 = %d\n", i3, i4);
  i4 = i3 >> 3;
  printf ("  i1 = %d  ;  i1 >> 3 = %d\n", i3, i4);
  i4 = i3 >> 4;
  printf ("  i1 = %d  ;  i1 >> 4 = %d\n", i3, i4);
  i4 = i3 >> 5;
  printf ("  i1 = %d  ;  i1 >> 5 = %d\n", i3, i4);
  printf ("\n");

  i3 = 16; 
  i4 = ~i3;
  printf ("  i1 = %3d ;  ~i1     = %4d\n", i3, i4);
  i3 = 127; 
  i4 = ~i3;
  printf ("  i1 = %3d ;  ~i1     = %4d\n", i3, i4);
  printf ("\n");
  i3 = 0; 
  i4 = ~i3;
  printf ("  i1 = %3d ;  ~i1     = %4d\n", i3, i4);
  i3 = 1; 
  i4 = ~i3;
  printf ("  i1 = %3d ;  ~i1     = %4d\n", i3, i4);
}

int 
main (int argc, char **argv)
{
  mostra_bits ();
  printf ("\n");

  return 0;
}
