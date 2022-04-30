#ifndef __PROG44_XX_H__
#define __PROG44_XX_H__ 1

typedef struct
{
  char         *nome   ;
  char          sexo   ;
  int           idade  ;
  double        altura ;
} Pessoa ;

typedef struct _StDD
{
  Pessoa       *data ;
  struct _StDD *next ;
} StDD ;


extern StDD *
stdd_create (char   *nome   ,
	     char    sexo   ,
	     int     idade  ,
	     double  altura );

extern void
stdd_init (StDD **stdd);

extern int
stdd_read_file (StDD **stdd  ,
		char  *fname );

extern int
stdd_line_to_stdd (StDD **stdd ,
		   char  *s1   );

extern void
stdd_print_element (StDD *stdd);

extern void
stdd_list (StDD *stdd);

extern void
stdd_insert (StDD  **stdd   ,
	     char   *nome   ,
	     char    sexo   ,
	     int     idade  ,
	     double  altura );

extern int
stdd_write_file (StDD  *stdd  ,
	  	 char  *fname );

extern void
stdd_delete (StDD **stdd);

#endif  //  __PROG44_XX_H__
