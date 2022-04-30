/********************************************
 *                                          *
 *      Funcao: Ponteiros para Funcoes      *
 *              Estruturas                  *
 *                                          *
 *      Versao: 1.2                         *
 *      Samuel Eleuterio 2008               *
 *                                          *
 ********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define FAZ_CONTAS_QT_OPER 4

typedef enum {soma, subtrai, multiplica, divide,
  oper_end} Operacao ;

typedef double (*ptr_funcd) (double , double ) ;

typedef struct 
{
  Operacao    oper           ;
  //ptr_funcd   func[FAZ_CONTAS_QT_OPER] ;
  double      (*(func[FAZ_CONTAS_QT_OPER])) (double , double ) ;
  double      valores[2]     ;
  double      resultado      ;
} FazContas ;

double faz_soma (double x ,
                 double y )
{
  return x + y;
}

double faz_subtrai (double x ,
                    double y )
{
  return x - y;
}

double faz_multiplica (double x ,
                       double y )
{
  return x * y;
}

double faz_divide (double x ,
                   double y )
{
  if (fabs(y) < 1e-300)
    y = (y < 0 ? -1 : 1) * 1e-300;
  return x/y;
}

/* Cria estrutura 'FazContas' */

FazContas  *
FazContas_cria (void)
{
  FazContas *c1 ;

  c1 = (FazContas *) malloc (sizeof (FazContas));

  c1->oper = oper_end;
  c1->func[soma] = faz_soma;
  c1->func[subtrai] = faz_subtrai;
  c1->func[multiplica] = faz_multiplica;
  c1->func[divide] = faz_divide;
  c1->valores[0] = 0.;
  c1->valores[1] = 0.;
  c1->resultado = 0.;

  return c1;
}

/* Destroi a estrutura 'FazContas' mas nao poe a variavel em 'NULL' */
void
FazContas_destroi_versao1 (FazContas *c1)
{
  if (!c1)
    return ;

  free (c1);
}

/* Destroi a estrutura 'FazContas' e poe a variavel em 'NULL' */
void
FazContas_destroi_versao2 (FazContas **c1)
{
  if ((!c1) || (!(*c1)))
    return ;

  free (*c1);
  (*c1) = NULL;
}

int
FazContas_marca_oper (FazContas  *c1  ,
                      char        ch1 )
{
  switch (ch1)
    {
      case '+' :
	c1->oper = soma;
	break;
      case '-' :
	c1->oper = subtrai;
	break;
      case 'x' :
	c1->oper = multiplica;
	break;
      case '/' :
	c1->oper = divide;
	break;
      default  :
	c1->oper = oper_end;
    }
  return (c1->oper == oper_end ? -1 : 1);
}

void
FazContas_guarda_valores (FazContas  *c1 ,
                          double      x1 ,
                          double      x2 )
{
  c1->valores[0] = x1;
  c1->valores[1] = x2;
}

int
FazContas_executa (FazContas  *c1)
{
  if (c1->oper == oper_end)
    return -1;

  c1->resultado = c1->func[c1->oper] (c1->valores[0], c1->valores[1]);

  return 1;
}

double
FazContas_da_resultado (FazContas  *c1)
{
  return c1->resultado;
}

void
help (int status)
{
  printf ("\n\n  Prog28_03 <valor> <operacao (+, -, x, /)> <valor>\n\n");
  exit (status);
}

int
main ()
{
  char         ch1        ;
  int          i1         ;
  double       x1, x2, x3 ;
  FazContas   *contas     ;

  contas = FazContas_cria ();

  while (1)
    {
      printf ("Escreva a conta a efectuar [x1 oper x2 ; Sair: 'q']: ");
      i1 = scanf ("%lf %c %lf", &x1, &ch1, &x2);
      if ((i1 == 0) && (getchar () == 'q'))
	break;
      while (getchar () != 10);

      if (i1 != 3)
	{
          printf ("\n  **** Expressao invalida ****\n\n");
	  continue;
	}
      if (FazContas_marca_oper (contas, ch1) == -1)
	{
          printf ("\n  **** Operador invalido ****\n\n");
	  continue;
	}

      FazContas_guarda_valores (contas, x1, x2);
      if (FazContas_executa (contas) == -1)
	{
          printf ("\n  **** Operador invalido ****\n\n");
	  continue;
	}

      x3 = FazContas_da_resultado (contas);
      printf ("\n  Resultado: %lf\n\n", x3);
    }

  FazContas_destroi_versao1 (contas);
  /* FazContas_destroi_versao2 (&contas); */

  return 0;
}

