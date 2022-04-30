#ifndef __PROG28_04_FAZ_CONTAS_H__
#define __PROG28_04_FAZ_CONTAS_H__ 1

#define QT_OPER_FAZ_CONTAS 4

/*
typedef double (*ptr_funcd) (double , double ) ;
*/

typedef enum {soma, subtrai, multiplica, divide,
  oper_end} Operacao ;

typedef struct
{
  Operacao    oper           ;
  /*  ptr_funcd   func[QT_OPER_FAZ_CONTAS] ;  */
  double      (*(func[QT_OPER_FAZ_CONTAS])) (double , double ) ;
  double      valores[2]     ;
  double      resultado      ;
} FazContas ;


extern FazContas *FazContas_cria (void);

extern void FazContas_destroi_versao1 (FazContas *c1);

extern void FazContas_destroi_versao2 (FazContas **c1);

extern int FazContas_marca_oper (FazContas  *c1, char ch1);

extern void FazContas_guarda (FazContas *c1, double x1, double x2);

extern int FazContas_executa (FazContas *c1);

extern double FazContas_da_resultado (FazContas *c1);

#endif  /* __PROG28_03_FAZ_CONTAS_H__ */
