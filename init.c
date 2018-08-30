#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>


int main(int argc, char const *argv[]) {

  /** Return value of fork */
  int p;

  /** Status of new processes */
  int status;

  /** Return value of exec */
  int f;


  /** Fork all, total = 2 */
  p = fork();

  /** Only fork the parent, total = 3 */
  if(p == 0) p =  fork();

  /** Fork all again, total = 6 */
  p = fork();

  /**
  * Replace code with a xterm terminal.
  * xterm   - the name of the program to be executed.
  * -n      - new terminal.
  * -e      - the new terminal has arguments to be executed.
  * ./getty - program to be executed by new terminal.
  */
  execlp("xterm","-n","-e","./getty",  NULL);




  return 0;
}
