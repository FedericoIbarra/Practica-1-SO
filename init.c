#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>

int p;

int main(int argc, char const *argv[]) {

  /** Return value of fork*/
  int pid, status;

  /** Return value of exec*/
  int f;


  p = fork();
  if(p == 0) p =  fork();
  p = fork();


  //pid = wait(&status);
  //printf("Status: %d - %d\n", p, pid);
//  execlp("./sh","",NULL);


/*
  if(pid == -1 || status == 0) p = fork();

  printf("PID: %d - STATUS: %d\n", pid, status);
*/

  execlp("xterm","-n","-e","./getty",  NULL); //"-e", "./getty", NULL);




  return 0;
}
