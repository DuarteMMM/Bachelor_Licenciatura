/************************************
 *                                  *
 *     Exemplos de <float.h>        *
 *                                  *
 *     Versao: 1.0                  *
 *     Samuel Eleuterio 2008        *
 *                                  *
 ************************************/

#include <stdio.h>
#include <float.h>

void
show_float (void)
{
  printf ("\n");
  printf ("*** Constantes definidas em 'float.h'\n");
  printf ("\n");

  printf ("  FLT_MIN  %g\n",  FLT_MIN);
  printf ("  FLT_MAX  %g\n",  FLT_MAX);
  printf ("  DBL_MIN  %g\n",  DBL_MIN);
  printf ("  DBL_MAX  %g\n",  DBL_MAX);
  printf ("  LDBL_MIN %Lg\n", LDBL_MIN);
  printf ("  LDBL_MAX %Lg\n", LDBL_MAX);
  printf ("\n");

  printf ("  FLT_EPSILON  %g\n",  FLT_EPSILON);
  printf ("  DBL_EPSILON  %g\n",  DBL_EPSILON);
  printf ("  LDBL_EPSILON %Lg\n", LDBL_EPSILON);
  printf ("\n");
  
  printf ("  FLT_DIG  %d\n", FLT_DIG);
  printf ("  DBL_DIG  %d\n", DBL_DIG);
  printf ("  LDBL_DIG %d\n", LDBL_DIG);
  printf ("\n");
}

int
main ()
{
  show_float ();
  return 0;
}
