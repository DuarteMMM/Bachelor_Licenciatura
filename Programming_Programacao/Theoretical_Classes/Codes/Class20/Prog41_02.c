/*
     Programa demonstrando o uso de strtol e strtod
      
     Autores: Joao Seixas 2004
              Samuel Eleuterio 2008
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
  //  char    s[] = "0123456789abcdefg" ;
  char      s[] = "012479afg"   ;
  char     *s8 = "020lixo1"     ;
  char     *s10 = "45.56lixo2"  ;
  char     *s16 = "0xFElixo3"   ;
  int       base2 = 2, base8 = 8, base10 = 10, base16 = 16 ;
  char     *p2, *p8, *p10, *p16 ;
  long int  v2, v8, v10, v16    ;
  double    d8, d10, d16;
     
  v2 = strtol (s, &p2, base2);
  v8 = strtol (s, &p8, base8);
  v10 = strtol (s, &p10, base10);
  v16 = strtol (s, &p16, base16);
     
  printf ("\nstrtol:\n");
  printf ("  s = \"%s\", base 2, resto = '%s', valor conv.= %ld\n", s, p2, v2);
  printf ("  s = \"%s\", base 8, resto = '%s', valor conv.= %ld\n", s, p8, v8);
  printf ("  s = \"%s\", base 10, resto = '%s', valor conv.= %ld\n", s, p10, v10);
  printf ("  s = \"%s\", base 16, resto = '%s', valor conv.= %ld\n", s, p16, v16);
     
  d8 = strtod (s8, &p8);
  d10 = strtod (s10, &p10);
  d16 = strtod (s16, &p16);

  printf ("\nstrtod:\n");
  printf ("  s = \"%s\", base 8, resto = '%s', valor conv.= %lf\n", s8, p8, d8);
  printf ("  s = \"%s\", base 10, resto = '%s', valor conv.= %lf\n", s10, p10, d10);
  printf ("  s = \"%s\", base 16, resto = '%s', valor conv.= %lf\n", s16, p16, d16);
  printf ("\n");
  
  return 0;
}
