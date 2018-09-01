#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>

#define PROCESSES 6

int pid[PROCESSES];
int status;

int main(int argc, char const *argv[]) {

  int i, index = 0;
  index = PROCESSES;


    for (i = 0; i < index; i++) {

      pid[i] = fork();
      if(pid[i] == 0) {
        //printf("Proceso numero: %d\n", getpid());
        execlp("xterm","-n","-e","./getty",  NULL);
      }
    }

    while (1) {
      wait(&status);
      printf("%d\n", status);
      for(i = 0; i < PROCESSES; i++) {
        if(getpgid(pid[i]) == -1) {
          pid[i] = fork();
          if(pid[i] == 0)  execlp("xterm","-n","-e","./getty",  NULL);
        }
      }

    }







  return 0;
}
