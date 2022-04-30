#ifndef __UTILS_H__
#define __UTILS_H__ 1

/* Verdadeiro e falso */

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

/* Macro para o calculo do quadrado */

#define QUAD(x) ((x) * (x))

/* Macro para o delta de Kronecker */

#define DELTA(a,b) (((a) == (b)) ? 1 : 0)

/* Macro para libertar espaco de uma variavel 'alocada' e po-la a 'NULL' */

#define freeNull(x) {free(x); x=NULL;}

/* Funções declaradas */

extern void tsrand (void);

extern double xrand (double  max);

extern float fxrand (float  max);

#endif  /* __UTILS_H__ */
