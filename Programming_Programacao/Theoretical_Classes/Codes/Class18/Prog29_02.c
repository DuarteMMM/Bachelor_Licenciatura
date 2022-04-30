/********************************
 *   Criar uma variante da      *
 *   funcao printf para as      *
 *   estruturas complex e       *
 *   complex2                   *
 *                              *
 *   Capitulo 5: vargs.c        *
 *                              *
 *   Autor: J. Seixas 2004      *
 *   samuel Eleut0rio 2019      *
 *                              *
 ********************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/* prototipo com numero variavel de argumentos */

int print_struct (char *, ...);

struct complex
{
  double r ;
  double i ;
};

typedef struct complex  complex  ;

int main()
{
  complex z1 = {1.0, 1.5};
  complex z2 = {2.0, 2.2};

  print_struct ("z1:%y\nz2:%y\n", z1, z2); 
  return 0;
}

/* definicao da funcao print_struct */

int print_struct (char *format, ...)
{
  int     nargs = 0 ;
  char    id        ;
  complex ctmp      ;
  va_list vp        ;                    // vp: lista de argumentos
   
  va_start(vp, *format);                 // inicializacao da lista
  while( (id = format[0]) != '\0')      // processamento dos argumentos
    {
      if (id == '%')
	{
          ++nargs;
          if (format[1] == 'y')
            {
              ctmp = va_arg(vp, complex);
              printf("(%lf, %lf)", ctmp.r, ctmp.i);
            }
          ++format;
	}
      else 
        putchar(id);
      ++format;     
    }
  va_end(vp);  // termina o acesso a lista de argumentos

  return nargs;
}
