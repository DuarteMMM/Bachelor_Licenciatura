#ifndef __UTILS_VECT_H__
#define __UTILS_VECT_H__ 1

// Liberta espaco de vectores e matrizes

#define vec_free(v) {free(v); v=NULL;}
#define matx_free(m) {free(m[0]); free(m); m=NULL;}

// Inicializa a zero vectores e matrizes

#define vec_clean(tipo,v,n) memset(v,0,n*sizeof(tipo))
#define matx_clean(tipo,m,nl,nc) vec_clean(tipo,m[0],nl*nc)

// Funções de Vectores

extern void *
vec_new (unsigned int  num    ,
         size_t        nbytes );

extern double
vec_modulo (double        *vect ,
            unsigned int   num  );

extern double
vec_pint (double       *vect1 ,
          double       *vect2 ,
          unsigned int  num   );

//Funções de Matrizes 

extern void **
matx_new (unsigned int  ncols  ,
          unsigned int  nrows  ,
          size_t        nbytes );

double
matx_trac (double       **matrix ,
           unsigned int   num    );

#endif /* __UTILS_VECT_H__ */
