#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>


int main() {

  /** User variable introduced into terminal. */
  char cmd[80];

  /** Password variable introduced into terminal. */
  char cmd2[80];

  /** Buffer used for reading the passwd file. */
  char bf[160];

  /** User variable of the file. */
  char usr[80];

  /** Password variable of the file. */
  char ps[80];

  /** Idexes for looping. */
  int i = 0, i2 = 0;
  int login = 1;

  /** File with the users and passwords. */
  FILE *psd;
  psd = fopen("passwd", "r");
  fgets(bf, 80, psd);


  /** getUser from buffer. */
  while (bf[i] != ':') {
    usr[i] = bf[i];
    i++;
  }

  i++;

  /** getPassword from buffer. */
  while (bf[i] != ' ') {
    ps[i2] = bf[i];
    i++;
    i2++;
  }

  /** Ask for the user and password until they are valid. */
  do {
		printf("User: ");
		scanf("%[^\n]%*c",cmd);
    printf("Password: ");
    scanf("%[^\n]%*c",cmd2);

    if((strcmp(usr, cmd) == 0) && (strcmp(ps, cmd2) == 0)) {
      login = 0;

      /** Replace process with a new xterm terminal and the execution of sh. */
       execlp("xterm","-n","-e","./sh",  NULL);

     } else {
       printf("Password or User wrong\n\n\n");
     }


	} while(login);

  return 0;
}
