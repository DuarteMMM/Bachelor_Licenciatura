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
#include <complex.h>
#undef I

int
main ()
{
  double w1 ;
  double _Complex z1 = 3.0 + 4.0 * _Complex_I;
  double complex z2 = 5.0 - 2.0 * _Complex_I;
  double _Complex c1 ;

  float x ;
  float complex f1 = 3.0 - 4.0 * _Complex_I;

  printf ("\nComplexos:\n");
  printf ("    z1: %lg %+lg i\n", creal(z1), cimag(z1));
  printf ("    z2: %lg %+lg i\n\n", creal(z2), cimag(z2));
  
  
  c1 = conj(z1);
  printf ("    conj(z1): %lg %+lg i\n", creal(c1), cimag(c1));
  
  w1 = cabs(z1);
  printf ("    cabs(z1): %lg\n", w1);
  
  w1 = carg(z1);
  printf ("    carg(c1): %lg  (%lgº)\n\n", w1, w1*180./M_PI);

  c1 = csqrt(-1);
  printf ("csqrt(-1): %lg %+lg i\n\n", creal(c1), cimag(c1));
  
  printf ("Operações binárias:\n");

  c1 = z1 + z2;
  printf ("    z1 + z2: %lg %+lg i\n", creal(c1), cimag(c1));

  c1 = z1 - z2;
  printf ("    z1 - z2: %lg %+lg i\n", creal(c1), cimag(c1));

  c1 = z1 * z2;
  printf ("    z1 * z2: %lg %+lg i\n", creal(c1), cimag(c1));

  c1 = z1 / z2;
  printf ("    z1 / z2: %lg %+lg i\n\n", creal(c1), cimag(c1));

  printf ("Funções trigonométricas, hiperbólicas, etc.):\n");

  c1 = csin(z1);
  printf ("    csin(z1): %lg %+lg i\n", creal(c1), cimag(c1));

  c1 = csinh(z1);
  printf ("    csinh(z1): %lg %+lg i\n", creal(c1), cimag(c1));
  
  c1 = cpow(z1, z2);
  printf ("    cpow(z1, z2): %lg %+lg i\n", creal(c1), cimag(c1));
  
  c1 = cexp(z1);
  printf ("    cexp(z1): %lg %+lg i\n", creal(c1), cimag(c1));
  
  c1 = clog(z1);
  printf ("    clog(z1): %lg %+lg i\n\n", creal(c1), cimag(c1));
  
  printf("float:\n");
  x = cabsf(f1);
  printf ("    f1: %g %+g i\n", creal(f1), cimag(f1));
  printf ("    cabsf(f1): %g\n\n", x);
  
  return 0;
}
