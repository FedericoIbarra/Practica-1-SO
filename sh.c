#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>


int main(int argc, char const *argv[]) {

  /** Input of the user. */
  char cmd[80];

  /** Index to kill all processes.*/
  int i = 0;


  while (1) {
  	printf("Sh> ");
  	scanf("%s",cmd);
    /** If the input is 'exit', kill the current process. */
    if (strcmp("exit", cmd) == 0)
    {
      return -1;
    }
    /**Shuts down all six processes*/
    else if (strcmp("shut", cmd) == 0)
    {
        execl("/usr/bin/killall", "killall","./init","./getty", "./sh", (char*)NULL);
    }
    /**Executes specific command on console*/
    else
    {
      /**
      * Reference to fopen: http://pubs.opengroup.org/onlinepubs/009696699/functions/popen.html
      * checked on september 1, 2018.
      */
      popen(cmd,"w");
      wait(NULL);
    }
  }
}
