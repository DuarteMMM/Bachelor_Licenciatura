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
show_help (int status)
{
  printf ("\n");
  printf ("  Prog22_01 <opcao> - Exemplificacao das Operacoes Basicas\n");
  printf ("    Opcoes:\n");
  printf ("      una  : Mostra operacoes unarias\n");
  printf ("      bin  : Mostra operacoes binarias\n");
  printf ("      log  : Mostra operacoes logicas\n");
  printf ("      bit  : Mostra operacoes sobre bits\n");
  printf ("\n");
  exit (status);
}

void
mostra_unarias (void)
{
  int  i1, i2 ;
  double  x1, x2 ;

  i1 = i2 = 20;
  printf ("\n*** Operacoes Unarias - Inteiros *** (i1 = %d)\n\n", i1);
  i1 = i2; printf ("  ++i1 = %d\n", ++i1);
  i1 = i2; printf ("  i1++ = %d\n", i1++);
  i1 = i2; printf ("  --i1 = %d\n", --i1);
  i1 = i2; printf ("  i1-- = %d\n", i1--);

  x2 = 20.0;
  printf ("\n*** Operacoes Unarias - Reais *** (i1 = %lf)\n\n", x2);
  x1 = x2; printf ("  ++x1 = %3.1lf\n", ++x1);
  x1 = x2; printf ("  x1++ = %3.1lf\n", x1++);
  x1 = x2; printf ("  --x1 = %3.1lf\n", --x1);
  x1 = x2; printf ("  x1-- = %3.1lf\n", x1--);
}

void
mostra_binarias (void)
{
  int  i1, i2, i3 ;
  double  x1, x2  ;

  i1 = 20; i2 = 3; 
  printf ("\n*** Operacoes Binarias - Inteiros ***\n\n");
  printf ("  %d + %d = %2d\n",  i1, i2, i1 + i2);
  printf ("  %d - %d = %2d\n",  i1, i2, i1 - i2);
  printf ("  %d * %d = %2d\n",  i1, i2, i1 * i2);
  printf ("  %d / %d = %2d\n",  i1, i2, i1 / i2);
  printf ("  %d %% %d = %2d\n", i1, i2, i1 % i2);

  x1 = 20.L; x2 = 3.L; 
  printf ("\n*** Operacoes Binarias (double) ***\n\n");
  printf ("  %4.1lf + %3.1lf = %8.5lf\n",  x1, x2, x1 + x2);
  printf ("  %4.1lf - %3.1lf = %8.5lf\n",  x1, x2, x1 - x2);
  printf ("  %4.1lf * %3.1lf = %8.5lf\n",  x1, x2, x1 * x2);
  printf ("  %4.1lf / %3.1lf = %8.5lf\n",  x1, x2, x1 / x2);

  i3 = 20; i2 = 3; 
  printf ("\n*** Operacoes Binarias (int) - Operadores Compostos ***\n\n");
  i1 = i3; i1 += i2;
  printf ("  %2d += %d ==> %3d\n",  i3, i2, i1);
  i1 = i3; i1 -= i2;
  printf ("  %2d -= %d ==> %3d\n",  i3, i2, i1);
  i1 = i3;  i1 *= i2;
  printf ("  %2d *= %d ==> %3d\n",  i3, i2, i1);
  i1 = i3; i1 /= i2;
  printf ("  %2d /= %d ==> %3d\n",  i3, i2, i1);
  i1 = i3; i1 %= i2;
  printf ("  %2d %%= %d ==> %3d\n",  i3, i2, i1);
}

void
mostra_logicas (void)
{
  int  i1, i2, i3, i4 ;

  i1 = 20;
  i2 = 30;
  i3 = 7;
  i4 = i1;

  printf ("\n*** Operacoes Lógicas ***\n\n");
  printf ("  %2d == %2d  ==>  %2d\n", i1, i4, i1 == i4);
  printf ("  %2d == %2d  ==>  %2d\n", i1, i2, i1 == i2);
  printf ("!(%2d == %2d) ==>  %2d\n", i1, i2, !(i1 == i2));
  printf ("  %2d >  %2d  ==>  %2d\n", i1, i4, i1 > i4);
  printf ("  %2d >= %2d  ==>  %2d\n", i1, i4, i1 >= i4);
  printf ("  %2d <  %2d  ==>  %2d\n", i1, i4, i1 < i4);
  printf ("  %2d <= %2d  ==>  %2d\n", i1, i4, i1 <= i4);
  printf ("------------\n");
  printf ("  (%2d == %2d) && (%2d < %2d)  ==>  %2d\n", 
          i1, i4, i1, i2, (i1 == i4) && (i1 < i2));
  printf ("  (%2d == %2d) && (%2d > %2d)  ==>  %2d\n", 
          i1, i4, i1, i2, (i1 == i4) && (i1 > i2));
  printf ("  (%2d == %2d) || (%2d > %2d)  ==>  %2d\n", 
          i1, i4, i1, i2, (i1 == i4) || (i1 > i2));
  printf ("!((%2d == %2d) || (%2d > %2d)) ==>  %2d\n", 
          i1, i4, i1, i2, !((i1 == i4) || (i1 > i2)));
  printf ("------------\n");
  printf ("  x = (%d >= 0 ? %d : %d)  ==>  %2d\n",
          i3, i1, i2, (i3 >= 0 ? i1 : i2));
  printf ("  x = (%d <  0 ? %d : %d)  ==>  %2d\n",
          i3, i1, i2, (i3 < 0 ? i1 : i2));
}

/* Binario - Hexa

     0: 0000  ;  1: 0001  ;  2: 0010  ;  3: 0011
     4: 0100  ;  5: 0101  ;  6: 0110  ;  7: 0111
     8: 1000  ;  9: 1001  ;  a: 1010  ;  b: 1011
     c: 1100  ;  d: 1101  ;  e: 1110  ;  f: 1111

*/

void
mostra_bits (void)
{
  int i1, i2, i3, i4 ;

  i1 = 0x2a;   /* 00101010  ==>  0010 1010  ==>  0x2a  ==> 2 * 16 + 10 = 42 */
  i2 = 0x12;   /* 00010010  ==>  0001 0010  ==>  0x12  ==> 1 * 16 +  2 = 18 */
  
  printf ("\n*** Operacoes sobre 'bits' ***\n\n");

  i3 = i1 & i2;
  printf ("  i1 = %d  ;  i2 = %d  ==>  i1 & i2 = %d\n", i1, i2, i3);
  i3 = i1 | i2;
  printf ("  i1 = %d  ;  i2 = %d  ==>  i1 | i2 = %d\n", i1, i2, i3);
  i3 = i1 ^ i2;
  printf ("  i1 = %d  ;  i2 = %d  ==>  i1 ^ i2 = %d\n", i1, i2, i3);

  printf ("\n");
  i3 = 1; 
  i4 = i3 << 1;
  printf ("  i1 = %d  ;  i1 << 1 = %d\n", i3, i4);
  i4 = i3 << 2;
  printf ("  i1 = %d  ;  i1 << 2 = %d\n", i3, i4);
  i4 = i3 << 3;
  printf ("  i1 = %d  ;  i1 << 3 = %d\n", i3, i4);
  i4 = i3 << 4;
  printf ("  i1 = %d  ;  i1 << 4 = %d\n", i3, i4);
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

  if (argc != 2)
    show_help (-1);

  if (strcmp (argv[1], "una") == 0)
    mostra_unarias ();
  else if (strcmp (argv[1], "bin") == 0)
    mostra_binarias ();
  else if (strcmp (argv[1], "log") == 0)
    mostra_logicas ();
  else if (strcmp (argv[1], "bit") == 0)
    mostra_bits ();
  else
    {
      printf ("Opcao desconhecida '%s'\n", argv[1]);
      show_help (-1);
    }

  printf ("\n");

  return 0;
}
