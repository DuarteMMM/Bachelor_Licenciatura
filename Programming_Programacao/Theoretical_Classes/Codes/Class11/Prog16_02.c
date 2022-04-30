/*****************************************************
 *                                                   *
 *      Exemplo de Estrutura - Bit Fields            *
 *                                                   *
 *      Versao: 1.0                                  *
 *      Samuel Eleuterio 2015                        *
 *                                                   *
 *****************************************************/

#include <stdio.h>
#include <stdlib.h>

/*
   Nota: Os valores limites de 'ano' foram ajustados ao tamanho 
   maximo para caber nos 2 bytes. De outro modo, o intervalo podia
   ter sido menor.
 */

typedef struct 
{
  unsigned int dia  :  5 ;   // 2^5  = 32
  unsigned int mes  :  4 ;   // 2^4  = 16
  int          ano  : 14 ;   // 2^14 = 16384
  unsigned int sexo :  1 ;   // 2^1  =  2
} DataNascSexo ;

int
main (int argc, char **argv)
{
  int  i1 ;
  DataNascSexo  pessoa = {30, 8, 1996, 1} ;
  unsigned int  power2[16] ;

  power2[0] = 1;
  for (i1 = 1 ; i1 < 16 ; ++i1)
    power2[i1] = 2 * power2[i1 - 1];

  printf ("\nDados Iniciais:\n");
  printf ("  Data de Nascimento: %.2u / %.2u / %.4d\n", pessoa.dia, pessoa.mes, pessoa.ano);
  if (pessoa.sexo == 0)
    printf ("  Sexo(%d): Masculino\n", pessoa.sexo);
  else
    printf ("  Sexo(%d): Feminino\n", pessoa.sexo);

  printf ("\n");
  printf ("Tamanho 'DataNascSexo' (sizeof): %lu\n", sizeof (DataNascSexo));
  printf ("Tamanho 'unsigned int' (sizeof): %lu\n", sizeof (unsigned int));
  printf ("Tamanho 'int' (sizeof):          %lu\n", sizeof (int));
  printf ("\n");
  printf ("Limites:\n");
  printf ("  Dia  (UInt. -  5 bits): [  0, %u ]\n", power2[5]-1);
  printf ("  Mes  (UInt. -  4 bits): [  0, %u ]\n", power2[4]-1);
  printf ("  Ano  (Int.  - 14 bits): [ %d, %d ]\n", -power2[13], power2[13]-1);
  printf ("  Sexo (UInt. -  1 bits): [  0, %u ]\n", power2[1]-1);
  printf ("\n");

  printf ("Somar '1' ao sexo ('pessoa.sexo):\n");
  for (i1 = 0 ; i1 < 3 ; ++i1)
    {
      ++pessoa.sexo;
      printf ("  [%d] Sexo: %u\n", i1, pessoa.sexo);
    }
  printf ("\n");
  
  printf ("Somar '1' ao dia ('pessoa.dia):\n");
  for (i1 = 0 ; i1 < 4 ; ++i1)
    {
      ++pessoa.dia;
      printf ("  [%d] Dia: %u\n", i1, pessoa.dia);
    }
  printf ("\n");
  printf ("Dados Apos Alteracoes:\n");
  printf ("  Data de Nascimento: %.2u / %.2u / %.4d\n", pessoa.dia, pessoa.mes, pessoa.ano);
  if (pessoa.sexo == 0)
    printf ("  Sexo(%d): Masculino\n", pessoa.sexo);
  else
    printf ("  Sexo(%d): Feminino\n", pessoa.sexo);
  printf ("\n");
  
  return 0;
}
