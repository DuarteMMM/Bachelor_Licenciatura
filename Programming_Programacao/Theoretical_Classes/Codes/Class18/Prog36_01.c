/*************************************
 *                                   *
 *     Exemplos de <limits.h>        *
 *                                   *
 *     Versao: 1.0                   *
 *     Samuel Eleuterio 2008         *
 *                                   *
 *************************************/

#include <stdio.h>
#include <limits.h>

void 
show_limits (void)
{
  printf ("*** Constantes definidas em 'limits.h'\n");
  printf ("\n");

  printf ("  CHAR_BIT  %d        (Numero de bits num 'char')\n", CHAR_BIT);
  printf ("\n");

  printf ("  SCHAR_MIN %d\n", SCHAR_MIN);
  printf ("  SCHAR_MAX %d\n", SCHAR_MAX);
  printf ("  UCHAR_MAX %d\n", UCHAR_MAX);
  printf ("\n");

  printf ("  SHRT_MIN  %d\n", SHRT_MIN);
  printf ("  SHRT_MAX  %d\n", SHRT_MAX);
  printf ("  USHRT_MAX %u\n", USHRT_MAX);
  printf ("\n");

  printf ("  INT_MIN  %d\n", INT_MIN);
  printf ("  INT_MAX  %d\n", INT_MAX);
  printf ("  UINT_MAX %u\n", UINT_MAX);
  printf ("\n");

  printf ("  LONG_MIN  %ld\n", LONG_MIN);
  printf ("  LONG_MAX  %ld\n", LONG_MAX);
  printf ("  ULONG_MAX %lu\n", ULONG_MAX);
  printf ("\n");

  printf ("  LLONG_MIN  %lld\n", LLONG_MIN);
  printf ("  LLONG_MAX  %lld\n", LLONG_MAX);
  printf ("  ULLONG_MAX %llu\n", ULLONG_MAX);
  printf ("\n");
}

int
main (int argc, char **argv)
{
  printf ("\n");

  show_limits ();

  return 0;
}
