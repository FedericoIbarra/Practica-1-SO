#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>


int main() {
  char cmd[80];
  do {
    	printf("Sh> ");
    	scanf("%[^\n]%*c",cmd);
      if (strcmp("shutdow", cmd) != 0) {
        system(cmd); // Cambiar  system
      }
  } while(strcmp("shutdow", cmd) != 0);
}
