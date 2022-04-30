/***************************************
 *                                     *
 *     Exemplos de                     *
 *          <locale.h> e <time.h>      *
 *                                     *
 *     Versao: 1.0                     *
 *     Samuel Eleuterio 2008           *
 *                                     *
 ***************************************/

#include <stdio.h>
#include <locale.h>
#include <time.h>

#define LEN 32

struct lconv *
muda_locale (char *ch_locale)
{
  setlocale (LC_ALL, ch_locale);
  return localeconv ();
}

void
show_locale (void)
{
  time_t         t1       ;
  struct tm     *data     ;
  struct lconv  *lc       ;
  char           buff[64] ;

  printf ("\n");
  printf ("*** Resultados obtidos a partir 'locale.h' ***\n");
  printf ("\n");
  printf ("%37c*** Tempo ***\n\n", LEN);

  buff[0] = 0;
  t1 = time (NULL);
  data = localtime (&t1);
  printf ("== Inicio == %s\n%28c", setlocale (LC_ALL, NULL), LEN);

  strftime (buff, LEN, "%A. %d %B %Y; ", data);
  printf ("%s\n", buff);

  printf ("==== PT ==== %s\n%28c", setlocale (LC_TIME, "pt_PT.UTF-8"), LEN);
  //printf ("==== PT ==== %s\n%28c", setlocale (LC_ALL, "pt_PT.UTF-8"), LEN);
  strftime (buff, LEN, "%A. %d %B %Y; ", data);
  printf ("%s\n", buff);

  printf ("==== US ==== %s\n%28c", setlocale (LC_TIME, "en_US.UTF-8"), LEN);
  strftime (buff, LEN, "%A. %d %B %Y; ", data);
  printf ("%s\n", buff);
  printf ("\n");

  printf ("%24c *****  struct lconv  *****\n", LEN);
  printf ("%24c pt_PT.UTF-8    en_US.UTF-8\n\n", LEN);

  lc = muda_locale ("pt_PT.UTF-8");
  printf ("      decimal_point:         '%s'", lc->decimal_point);
  sprintf (buff, "PT: %lg", 0.5);
  lc = muda_locale ("en_US.UTF-8");
  sprintf (&buff[20], "US: %lg", 0.5);
  printf ("            '%s'   %s   %s\n", lc->decimal_point, buff, &buff[20]);
  
  lc = muda_locale ("pt_PT.UTF-8");
  printf ("      thousands_sep:         '%s' ", lc->thousands_sep);
  lc = muda_locale ("en_US.UTF-8");
  printf ("            '%s'\n", lc->thousands_sep);

  lc = muda_locale ("pt_PT.UTF-8");
  printf ("      grouping:              '%s' ", lc->grouping);
  lc = muda_locale ("en_US.UTF-8");
  printf ("            '%s' (ASCII: %d %d)\n", 
          lc->grouping, lc->grouping[0], lc->grouping[1]);
  printf ("\n");

  lc = muda_locale ("pt_PT.UTF-8");
  printf ("      int_curr_symbol:       '%s'", lc->int_curr_symbol);
  lc = muda_locale ("en_US.UTF-8");
  printf ("         '%s'\n", lc->int_curr_symbol);

  lc = muda_locale ("pt_PT.UTF-8");
  printf ("      currency_symbol:       '%s'", lc->currency_symbol);
  lc = muda_locale ("en_US.UTF-8");
  printf ("            '%s'\n", lc->currency_symbol);

  lc = muda_locale ("pt_PT.UTF-8");
  printf ("      mon_decimal_point:     '%s'", lc->mon_decimal_point);
  lc = muda_locale ("en_US.UTF-8");
  printf ("            '%s'\n", lc->mon_decimal_point);
  printf ("\n");

  lc = muda_locale ("pt_PT.UTF-8");
  printf ("      mon_thousands_sep:     '%s'", lc->mon_thousands_sep);
  lc = muda_locale ("en_US.UTF-8");
  printf ("           '%s'\n", lc-> mon_thousands_sep);

  lc = muda_locale ("pt_PT.UTF-8");
  printf ("      mon_grouping:          '%s' (ASCII: %d %d)", lc->mon_grouping, 
	  lc->mon_grouping[0], lc->mon_grouping[1]);
  lc = muda_locale ("en_US.UTF-8");
  printf ("             '%s' (ASCII: %d %d)\n", lc->mon_grouping, 
	  lc->mon_grouping[0], lc->mon_grouping[1]);

  lc = muda_locale ("pt_PT.UTF-8");
  printf ("      positive_sign:         '%s'", lc->positive_sign);
  lc = muda_locale ("en_US.UTF-8");
  printf ("             '%s'\n", lc->positive_sign);
  printf ("\n");

  lc = muda_locale ("pt_PT.UTF-8");
  printf ("      negative_sign:         '%s'", lc->negative_sign);
  lc = muda_locale ("en_US.UTF-8");
  printf ("            '%s'\n", lc->negative_sign);

  lc = muda_locale ("pt_PT.UTF-8");
  printf ("      int_frac_digits:       '%d'", lc->int_frac_digits);
  lc = muda_locale ("en_US.UTF-8");
  printf ("            '%d'\n", lc->int_frac_digits);

  lc = muda_locale ("pt_PT.UTF-8");
  printf ("      frac_digits:           '%d'", lc->frac_digits);
  lc = muda_locale ("en_US.UTF-8");
  printf ("            '%d'\n", lc->frac_digits);
  printf ("\n");

  lc = muda_locale ("pt_PT.UTF-8");
  printf ("      p_cs_precedes:         '%d'", lc->p_cs_precedes);
  lc = muda_locale ("en_US.UTF-8");
  printf ("            '%d'\n", lc->p_cs_precedes);

  lc = muda_locale ("pt_PT.UTF-8");
  printf ("      p_sep_by_space:        '%d'", lc->p_sep_by_space);
  lc = muda_locale ("en_US.UTF-8");
  printf ("            '%d'\n", lc->p_sep_by_space);

  lc = muda_locale ("pt_PT.UTF-8");
  printf ("      n_cs_precedes:         '%d'", lc->n_cs_precedes);
  lc = muda_locale ("en_US.UTF-8");
  printf ("            '%d'\n", lc->n_cs_precedes);
  printf ("\n");

  lc = muda_locale ("pt_PT.UTF-8");
  printf ("      n_sep_by_space:        '%d'", lc->n_sep_by_space);
  lc = muda_locale ("en_US.UTF-8");
  printf ("            '%d'\n", lc->n_sep_by_space);

  lc = muda_locale ("pt_PT.UTF-8");
  printf ("      p_sign_posn:           '%d'", lc->p_sign_posn);
  lc = muda_locale ("en_US.UTF-8");
  printf ("            '%d'\n", lc->p_sign_posn);

  lc = muda_locale ("pt_PT.UTF-8");
  printf ("      n_sign_posn:           '%d'", lc->n_sign_posn);
  lc = muda_locale ("en_US.UTF-8");
  printf ("            '%d'\n", lc->n_sign_posn);
  printf ("\n");

#ifdef __USE_ISOC99
  lc = muda_locale ("pt_PT.UTF-8");
  printf ("      int_p_cs_precedes:     '%d'", lc->int_p_cs_precedes);
  lc = muda_locale ("en_US.UTF-8");
  printf ("            '%d'\n", lc->int_p_cs_precedes);

  lc = muda_locale ("pt_PT.UTF-8");
  printf ("      int_p_sep_by_space:    '%d'", lc->int_p_sep_by_space);
  lc = muda_locale ("en_US.UTF-8");
  printf ("            '%d'\n", lc->int_p_sep_by_space);

  lc = muda_locale ("pt_PT.UTF-8");
  printf ("      int_n_cs_precedes:     '%d'", lc->int_n_cs_precedes);
  lc = muda_locale ("en_US.UTF-8");
  printf ("            '%d'\n", lc->int_n_cs_precedes);
  printf ("\n");

  lc = muda_locale ("pt_PT.UTF-8");
  printf ("      int_n_sep_by_space:    '%d'", lc->int_n_sep_by_space);
  lc = muda_locale ("en_US.UTF-8");
  printf ("            '%d'\n", lc->int_n_sep_by_space);

  lc = muda_locale ("pt_PT.UTF-8");
  printf ("      int_p_sign_posn:       '%d'", lc->int_p_sign_posn);
  lc = muda_locale ("en_US.UTF-8");
  printf ("            '%d'\n", lc->int_p_sign_posn);

  lc = muda_locale ("pt_PT.UTF-8");
  printf ("      int_n_sign_posn:       '%d'", lc->int_n_sign_posn);
  lc = muda_locale ("en_US.UTF-8");
  printf ("            '%d'\n", lc->int_n_sign_posn);
#else
  lc = muda_locale ("pt_PT.UTF-8");
  printf ("      __int_p_cs_precedes:   '%d'", lc->__int_p_cs_precedes);
  lc = muda_locale ("en_US.UTF-8");
  printf ("            '%d'\n", lc->__int_p_cs_precedes);

  lc = muda_locale ("pt_PT.UTF-8");
  printf ("      __int_p_sep_by_space:  '%d'", lc->__int_p_sep_by_space);
  lc = muda_locale ("en_US.UTF-8");
  printf ("            '%d'\n", lc->__int_p_sep_by_space);

  lc = muda_locale ("pt_PT.UTF-8");
  printf ("      __int_n_cs_precedes:   '%d'", lc->__int_n_cs_precedes);
  lc = muda_locale ("en_US.UTF-8");
  printf ("            '%d'\n", lc->__int_n_cs_precedes);
  printf ("\n");

  lc = muda_locale ("pt_PT.UTF-8");
  printf ("      __int_n_sep_by_space:  '%d'", lc->__int_n_sep_by_space);
  lc = muda_locale ("en_US.UTF-8");
  printf ("            '%d'\n", lc->__int_n_sep_by_space);

  lc = muda_locale ("pt_PT.UTF-8");
  printf ("      __int_p_sign_posn:     '%d'", lc->__int_p_sign_posn);
  lc = muda_locale ("en_US.UTF-8");
  printf ("            '%d'\n", lc->__int_p_sign_posn);

  lc = muda_locale ("pt_PT.UTF-8");
  printf ("      __int_n_sign_posn:     '%d'", lc->__int_n_sign_posn);
  lc = muda_locale ("en_US.UTF-8");
  printf ("           '%d'\n", lc->__int_n_sign_posn);
#endif

  printf ("\n");
}

int
main (int argc, char **argv)
{
  show_locale ();

  return 0;
}
