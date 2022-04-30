/********************************************
 *                                          *
 *      Funcao:                             *
 *                                          *
 *      Versao: 1.2                         *
 *      Joao Seixas 2004                    *
 *      Samuel Eleuterio 2008, 2015         *
 *                                          *
 ********************************************/

// http://nadeausoftware.com/articles/2012/01/c_c_tip_how_use_compiler_predefined_macros_detect_operating_system

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main ()
{
  printf ("\n");

#if defined(__MACH__)
  printf ("**** __MACH__    **** TRUE  **** Isto e um 'Apple - Mac'.\n");
#else
  printf ("**** __MACH__    **** FALSE **** Isto nao e um 'Apple - Mac'.\n");
#endif

#if defined(__APPLE__)
  printf ("**** __APPLE__   **** TRUE  **** Isto e um sistema 'Apple'.\n");
#else
  printf ("**** __APPLE__   **** FALSE **** Isto nao e um sistema 'Apple'.\n");
#endif

#if defined(__unix__)
  printf ("**** __unix__    **** TRUE  **** Isto e um sistema 'Unix'.\n");
#else
  printf ("**** __unix__    **** FALSE **** Isto nao e um sistema 'Unix'.\n");
#endif

#ifdef __linux__
  printf ("**** __linux__   **** TRUE  **** Isto e um sistema 'Linux'.\n");
#else
  printf ("**** __linux__   **** FALSE **** Isto nao e um sistema 'Linux'.\n");
#endif

#ifdef __MINGW64__
  printf ("**** __MINGW64__ **** TRUE  **** Isto e um sistema 'MingW64'.\n");
#else
  printf ("**** __MINGW64__ **** FALSE **** Isto nao e um sistema 'MingW64'.\n");
#endif

#ifdef __MINGW32__
  printf ("**** __MINGW32__ **** TRUE  **** Isto e um sistema 'MingW32'.\n");
#else
  printf ("**** __MINGW32__ **** FALSE **** Isto nao e um sistema 'MingW32'.\n");
#endif

#if defined(_WIN32)
  printf ("**** _WIN32      **** TRUE  **** Isto e um sistema 'Windows 32'.\n");
#else
  printf ("**** _WIN32      **** FALSE **** Isto nao e um sistema 'Windows 32'.\n");  
#endif

#if defined(_WIN64)
  printf ("**** _WIN64      **** TRUE  **** Isto e um sistema 'Windows 64'.\n");
#else
  printf ("**** _WIN64      **** FALSE **** Isto nao e um sistema 'Windows 64'.\n");  
#endif

  printf ("\n");

  return 0;
}
