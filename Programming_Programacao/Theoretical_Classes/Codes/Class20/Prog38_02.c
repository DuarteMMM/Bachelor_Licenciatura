/********************************************
 *                                          *
 *     Exemplos de <time.h>                 *
 *                                          *
 *     Versao: 1.0                          *
 *     Samuel Eleuterio 2008                *
 *                                          *
 ********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <locale.h>

#define LEN2 128

int
main (int argc, char **argv)
{
  char          *str1, str2[LEN2] ;
  clock_t        ct1, ct2         ;
  struct tm     *ptr_tm2          ;

  if ((argc != 2) || (!((strcmp(argv[1], "en") == 0) || (strcmp(argv[1], "pt") == 0))))
    {
      printf ("\n  Prog38_02 <val>   ( 'en' - en_US.UTF-8  ;  'pt' - pt_PT.UTF-8 )\n\n");
      exit (1);
    }

  if (strcmp(argv[1], "en") == 0)
    setlocale (LC_TIME, "en_US.UTF-8");
  else
    setlocale (LC_TIME, "pt_PT.UTF-8");

  ct2 = 0;
  ct1 = time (&ct2);
  printf ("\nFunção 'time':\n");
  printf ("    Por return (ct1):   %ld \n    Por ponteiro (ct2): %ld\n", ct1, ct2);
  
  ptr_tm2 = localtime (&ct1);

  str1 = asctime (ptr_tm2);
  printf ("\nasctime:  %s\n", str1);

  printf ("Dados de 'struct tm'\n");

  strftime (str2, LEN2, "  Dia da Semana (Completo, Abreviado): %A - %a", ptr_tm2);
  printf ("  %s\n", str2);

  strftime (str2, LEN2, "  Dia da Semana (Dia, Sem. do Ano): %w - %W", ptr_tm2);
  printf ("  %s\n", str2);

  strftime (str2, LEN2, "  Mês (Completo, Abreviado): %B - %b", ptr_tm2);
  printf ("  %s\n", str2);
  strftime (str2, LEN2, "  Dia e hora: %c", ptr_tm2);
  printf ("  %s\n", str2);
  strftime (str2, LEN2, "  Hora do dia (0-24 ; AM/PM): %H - %p", ptr_tm2);
  printf ("  %s\n", str2);
  strftime (str2, LEN2, "  Segundos : %S", ptr_tm2);
  printf ("  %s\n", str2);
  strftime (str2, LEN2, "  Data : %x", ptr_tm2);
  printf ("  %s\n", str2);
  strftime (str2, LEN2, "  Hora : %X", ptr_tm2);
  printf ("  %s\n", str2);
  strftime (str2, LEN2, "  Ano (yy, yyyy): %y - %Y", ptr_tm2);
  printf ("  %s\n", str2);
  strftime (str2, LEN2, "  Zona: %Z", ptr_tm2);
  printf ("  %s\n", str2);

  strftime (str2, LEN2, "  %A, %d %B %Y as %H:%M:%S (%Z)", ptr_tm2);
  printf ("\n  Data (%s): %s\n", argv[1], str2);

  setlocale (LC_TIME, (strcmp(argv[1], "en") == 0 ? "pt_PT.UTF-8" : "en_US.UTF-8"));
  
  strftime (str2, LEN2, "  %A, %d de %B de %Y as %H:%M:%S (%Z)", ptr_tm2);
  printf ("\n  Data (%s): %s\n\n", (strcmp(argv[1], "en") == 0 ? "pt" : "en"), str2);

  return 1;
}
