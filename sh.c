#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>


int main(int argc, char const *argv[]) {
  char cmd[80];
  int i = 0;


  do {
    	printf("Sh> ");
    	scanf("%s",cmd);
      if (strcmp("exit", cmd) == 0) {
        return -1;
      }  else if (strcmp("shut", cmd) == 0) {
          //kill(getpid(), SIGTERM);
          //kill(getppid(), SIGTERM);
      } else {

        /**Reference to fopen: http://pubs.opengroup.org/onlinepubs/009696699/functions/popen.html,
          checked on september 1, 2018*/
        popen(cmd,"w"); // Cambiar  system
        wait(NULL);
      }

  } while(strcmp("shutdow", cmd) != 0);
}
