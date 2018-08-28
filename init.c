#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  /* code */

  int p;
  //we start with 1 process

  p = fork();
  if (p > 0) p = fork();
  p =  fork();

  execlp("xterm","-n","-e","./getty",  NULL); //"-e", "./getty", NULL);

  p = fork();


  return 0;
}
