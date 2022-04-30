/*
     Programa exemplificando opcoes de formato para char
      
     Autor: J. Seixas 2004
*/

#include <stdio.h>

int main()
{
  int c;
     
  for (c = 32 ; c < 127 ; ++c)
    printf ("decimal = %3d:\toctal = 0%o\thexa = 0x%X\tchar = '%c'\n", c, c, c, c);

  return 0;
}
