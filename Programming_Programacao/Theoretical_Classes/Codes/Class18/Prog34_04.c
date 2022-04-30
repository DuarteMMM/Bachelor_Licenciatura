/*
    Exemplo retirado de:
       http://www.sanfoundry.com/c-questions-setjmp-longjmp-functions-standard-library-uses/
 */

#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
 
// declare variable of type jmp_buf
jmp_buf resume_here;
 
void hello(void)
{
  int value = 7;   // Return value to 'setjmp'. If 'value = 0' the return is '1'.
  
  printf ("(3) Hey, I'm in 'hello()'\n");
  longjmp (resume_here, value);
 
  // other code
  printf("(4) can't be reached here because I did longjmp!\n");
}

int main(void)
{
  int i1 ;
  
  printf ("(0) Begin!!\n"); 

  // Initialize 'resume_here' by calling setjmp()

  if ((i1 = setjmp(resume_here)))
    {
      printf("(1) After 'longjump()', back in 'main()'\n");
      printf("    'jump buffer variable 'resume_here'' becomes INVALID!\n");
      printf("    Return(setjmp): %d\n", i1);
    }
  else
    {
      printf("(2) 'setjmp()' returns first time\n");
      printf("    Return(setjmp): %d\n", i1);
      hello();
    }

  printf ("(5) End!!!\n");
 
  return 0;
}
 
