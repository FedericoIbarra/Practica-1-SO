#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>

/** Number of processes to create.*/
#define PROCESSES 6

/** Global: array pids of the created processes.*/
int pid[PROCESSES];

/** Global: return status of each process.*/
int status;

int main(int argc, char const *argv[]) {

  /** Index for recursion.*/
  int i;

    /** Create N number of processes.*/
    for (i = 0; i < PROCESSES; i++) {

      /** Only fork if the root is the parent.*/
      pid[i] = fork();
      if(pid[i] == 0) {
        /** Replace the new process code with an xterm terminal.*/
        execlp("xterm","-n","-e","./getty",  NULL);
      }
    }

    /** Infinite loop that crates new process when another one is killed.*/
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
