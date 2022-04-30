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

int 
main (int argc, char **argv)
{
  int    i1, i2, i3 ;

  printf ("Escreva um número: ");
  scanf("%i", &i1);
  printf("i1: %d\n", i1);
  
  i1 = 12;
  i2 = 012;
  i3 = 0x12;

  printf ("\n*** Representacao de valores Constantes ***\n");
  printf ("\n");
  printf ("  Decimal:      i1 = 12    ==>  %d\n", i1);
  printf ("  Octal:        i2 = 012   ==>  %d\n", i2);
  printf ("  Hexadecimal:  i3 = 0x12  ==>  %d\n", i3);
  printf ("\n");

  i1 = 12;
  i2 = 014;
  i3 = 0xC;

  printf ("  Decimal:      i1 = 12    ==>  %d  (1 x 10 +  2)\n", i1);
  printf ("  Octal:        i2 = 014   ==>  %d  (1 x  8 +  4)\n", i2);
  printf ("  Hexadecimal:  i3 = 0xC   ==>  %d  (         12)\n", i3);
  printf ("\n");

  i1 = 193;

  printf ("\n*** Escrita dos valores ***\n");
  printf ("\n");
  printf ("  %d - Decimal     (%%d):   %d\n", i1, i1);
  printf ("  %d - Hexadecimal (%%x):    %x \n", i1, i1);
  printf ("                    (%%X):    %X\n", i1);
  printf ("  %d - Octal       (%%o):   %o \n", i1, i1);
  printf ("\n");

 return 0;
}
