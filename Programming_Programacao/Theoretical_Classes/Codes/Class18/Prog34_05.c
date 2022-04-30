/* 
   Example using signal by TechOnTheNet.com 
     http://www.techonthenet.com/c_language/standard_library_functions/signal_h/signal.php

   The SIGUSR1 and SIGUSR2 signals are set aside for you to use any way you want. 
   They’re useful for simple interprocess communication, if you write a signal 
   handler for them in the program that receives the signal. 
   (https://www.gnu.org/software/libc/manual/html_node/Miscellaneous-Signals.html)
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void signal_handler (int signal)
{
  // Display a message indicating we have received a signal
  if (signal == SIGUSR2) 
    printf ("(4) Received a SIGUSR2 signal\n");
    
  // Exit the application
  exit(0);
}

int main (int argc, const char * argv[])
{
  // Display a message indicating we are registering the signal handler
  printf("(1) Registering the signal handler\n");
    
  // Register the signal handler
  signal (SIGUSR2, signal_handler);
    
  // Display a message indicating we are raising a signal
  printf ("(2) Raising a SIGUSR2 signal\n");
    
  // Raise the SIGUSR2 signal
  raise (SIGUSR2);
    
  // Display a message indicating we are leaving main
  printf ("(3) Finished main\n");
    
  return 0;
}
