/********************************************
 *                                          *
 *      Exemplo de Instrucoes Condicionais  *
 *        'if ... else ...'                 *
 *                                          *
 *      Versao: 1.0                         *
 *      Samuel Eleuterio 2008               *
 *                                          *
 ********************************************/

#include <stdio.h>
#include <stdlib.h>

void
help (int status)
{
  printf ("\n  Prog23_03 <letra>\n");
  printf ("\n");

  exit (status);
}


int
main (int argc, char **argv)
{
  if (argc != 2)
    help (-1);

  if (!(((argv[1][0] >= 'A') && (argv[1][0] <= 'Z')) ||
	((argv[1][0] >= 'a') && (argv[1][0] <= 'z'))))
    {
      printf ("\n  Tem de escrever uma letra!\n");
      help (-1);
    }

  printf ("\n  ***** ");
  switch (argv[1][0])
    {
      case 'A' : 
      case 'a' : 
	printf ("Muito bem. Escreveu a primeira vogal.");
        break;
      case 'E' : case 'e' : 
	printf ("Ah!, agora escreveu a segunda vogal.");
        break;
      case 'I' : case 'i' : 
	printf ("Desta foi a terceira vogal.");
        break;
      case 'O' : case 'o' : 
	printf ("Pois... agora foi a quarta vogal.");
        break;
      case 'U' : case 'u' : 
	printf ("Esta finalmente é a quinta vogal.");
        break;
      case 'Y' : case 'y' : 
	printf ("E esta?... Vogal, semi-vogal ou consoante?...");
        break;
      default :
	printf ("Escreveu uma consoante.");
    }
  printf (" *****\n\n");

  return 0;
}
