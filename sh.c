#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>


int main() {
  char cmd[80];

system("clear");

  do {
    	printf("Sh> ");
    	scanf("%[^\n]%*c",cmd);
      if (strcmp("exit", cmd) == 0) {
        //printf("Si jala\n");
        kill(getpid(), SIGKILL);
      }  else if (strcmp("shutdow", cmd) == 0) {
         execlp("killall","9","*",NULL);
      } else {
        system(cmd); // Cambiar  system
      }

  } while(strcmp("shutdow", cmd) != 0);
}
