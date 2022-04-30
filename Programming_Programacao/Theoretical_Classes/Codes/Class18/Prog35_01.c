/********************************************
 *                                          *
 *     Exemplos de <ctype.h>                *
 *                                          *
 *     Versao: 1.0                          *
 *     Samuel Eleuterio 2008                *
 *                                          *
 ********************************************/

#include <stdio.h>
#include <ctype.h>

int
main ()
{
  printf ("\n");

  printf ("%8d = isalpha (%c)\n", isalpha ('a'), 'a');
  printf ("%8d = isalpha (%c)\n", isalpha ('1'), '1');
  printf ("\n");

  printf ("%8d = isdigit (%c)\n", isdigit ('a'), 'a');
  printf ("%8d = isdigit (%c)\n", isdigit ('A'), 'A');
  printf ("%8d = isdigit (%c)\n", isdigit ('8'), '8');
  printf ("\n");

  printf ("%8d = isxdigit (%c)\n", isxdigit ('a'), 'a');
  printf ("%8d = isxdigit (%c)\n", isxdigit ('1'), '1');
  printf ("%8d = isxdigit (%c)\n", isxdigit ('2'), '2');
  printf ("%8d = isxdigit (%c)\n", isxdigit ('h'), 'h');
  printf ("\n");

  printf ("%8d = isalnum (%c)\n", isalnum ('1'), '1');
  printf ("%8d = isalnum (%c)\n", isalnum ('a'), 'a');
  printf ("%8d = isalnum (%c)\n", isalnum ('?'), '?');
  printf ("\n");

  printf ("%8d = islower (%c)\n", islower ('a'), 'a');
  printf ("%8d = islower (%c)\n", islower ('A'), 'A');
  printf ("%8d = islower (%c)\n", islower ('1'), '1');
  printf ("\n");

  printf ("%8d = isupper (%c)\n", isupper ('a'), 'a');
  printf ("%8d = isupper (%c)\n", isupper ('A'), 'A');
  printf ("%8d = isupper (%c)\n", isupper ('1'), '1');
  printf ("\n");

  printf ("%8d = isgraph (%c)\n", isgraph ('1'), '1');
  printf ("%8d = isgraph (%c)\n", isgraph ('a'), 'a');
  printf ("%8d = isgraph (%c)\n", isgraph ('?'), '?');
  printf ("%8d = isgraph (SPACE)\n", isgraph (' '));
  printf ("%8d = isgraph (CTRL C)\n", isgraph (3));
  printf ("%8d = isgraph (ESC)\n", isgraph (33));
  printf ("\n");

  printf ("%8d = isprint (%c)\n", isprint ('1'), '1');
  printf ("%8d = isprint (%c)\n", isprint ('a'), 'a');
  printf ("%8d = isprint (%c)\n", isprint ('?'), '?');
  printf ("%8d = isprint (SPACE)\n", isprint (' '));
  printf ("%8d = isprint (CTRL C)\n", isprint (3));
  printf ("%8d = isprint (ESC)\n", isprint (33));
  printf ("\n");

  printf ("%8d = ispunct (%c)\n", ispunct ('1'), '1');
  printf ("%8d = ispunct (%c)\n", ispunct ('a'), 'a');
  printf ("%8d = ispunct (%c)\n", ispunct ('?'), '?');
  printf ("%8d = ispunct (SPACE)\n", ispunct (' '));
  printf ("\n");
 
  printf ("%8d = isspace (%c)\n", isspace ('1'), '1');
  printf ("%8d = isspace (SPACE)\n", isspace (' '));
  printf ("%8d = isspace (TAB)\n", isspace (9));
  printf ("%8d = isspace (NL)\n", isspace (10));
  printf ("%8d = isspace (CR)\n", isspace (13));
  printf ("\n");

  printf ("%8d = iscntrl (CTRL C)\n", iscntrl (3));
  printf ("%8d = iscntrl ('%c')\n", iscntrl ('a'), 'a');
  printf ("\n");

  printf ("%8c = tolower (%c)\n", tolower ('A'), 'A');
  printf ("%8c = tolower (%c)\n", tolower ('a'), 'a');
  printf ("%8c = tolower (%c)\n", tolower ('7'), '7');
  printf ("%8c = tolower (%c)\n", tolower ('?'), '?');
  printf ("\n");

  printf ("%8c = toupper (%c)\n", toupper ('A'), 'A');
  printf ("%8c = toupper (%c)\n", toupper ('a'), 'a');
  printf ("%8c = toupper (%c)\n", toupper ('7'), '7');
  printf ("%8c = toupper (%c)\n", toupper ('?'), '?');
  printf ("\n");

  return 0;
}
