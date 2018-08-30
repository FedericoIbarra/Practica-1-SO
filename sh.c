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
      system(cmd); // Cambiar  system
  } while(strcmp("shutdown", cmd) != 0);
}
