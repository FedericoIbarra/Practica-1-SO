#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>


int main() {
  char cmd[80];
  int i = 0;

system("clear");

  do {
    	printf("Sh> ");
    	scanf("%[^\n]%*c",cmd);
      if (strcmp("exit", cmd) == 0) {
        //printf("Si jala\n");
        kill(getpid(), SIGKILL);
      }  /*else if (strcmp("shut", cmd) == 0) {
      //  while (i < 6) {
           execlp("kill","-9",getpid(),NULL);
        //   i++;
        //}

      }*/ else {
        system(cmd); // Cambiar  system
      }

  } while(strcmp("shutdow", cmd) != 0);
}
