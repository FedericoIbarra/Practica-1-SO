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
  int f,l;


  while (1) {
    p = fork();
    if ( p == 0) p = fork();
    p = fork();
    p = fork();

    l = wait(&status);

  printf("%d - %d\n",l,status);
    if((l != 0) && (status == 0)) {
      p = fork();
      wait(&status);
      execlp("xterm","-n","-e","./getty",  NULL);
    }

    execlp("xterm","-n","-e","./getty",  NULL);

    execlp("./init","",NULL);


  }


  /**
  * Replace code with a xterm terminal.
  * xterm   - the name of the program to be executed.
  * -n      - new terminal.
  * -e      - the new terminal has arguments to be executed.
  * ./getty - program to be executed by new terminal.
  */
//  execlp("xterm","-n","-e","./getty",  NULL);




  return 0;
}
