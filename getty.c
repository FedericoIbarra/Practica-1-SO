#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>


int main(int argc, char const *argv[]) {

  //printf("%d\n", argv[0]);

  /** User variable introduced into terminal. */
  char cmd[80];

  /** Password variable introduced into terminal. */
  char cmd2[80];

  /** Buffer used for reading the passwd file. */
  char bf[160];
  char bf_temp[160];

  /** User variable of the file. */
  char usr[80];

  /** Password variable of the file. */
  char ps[80];

  /** Idexes for looping. */
  int i = 0, i2 = 0;
  int login = 1;
  int status;
  char padre;

  int access = 0;
  int miss = 0;

  /** File with the users and passwords. */
  FILE *psd;
  psd = fopen("passwd", "r");

  /** Ask for the user and password until they are valid. */
  do {
		printf("User: ");
		scanf("%s",cmd);
    printf("Password: ");
    scanf("%s",cmd2);

    fclose(psd);
    psd = fopen("passwd", "r");
    fgets(bf, 80, psd);

    miss = 0;

    do {
      i = 0, i2 = 0;

      /** getUser from buffer. */
      while (bf[i] != ':')
      {
        usr[i] = bf[i];
        i++;
      }

      i++;

      /** getPassword from buffer. */
      while (bf[i] != ' ')
      {
        ps[i2] = bf[i];
        i++;
        i2++;
      }

      if((strcmp(usr, cmd) == 0) && (strcmp(ps, cmd2) == 0))
      {
        access = 1;
       }

       else
       {
          if(fgets(bf, 80, psd) == NULL)
          {
              miss = 1;
              printf("Wrong Password or User\n\n\n");
          }
       }

    } while((access == 0) && (miss == 0));

    if(access == 1)
    {
        login = 0;

        /** Replace process with a new xterm terminal and the execution of sh. */
        padre = getpid() + 0;
        execlp("./sh","",NULL);
        wait(&status);
        return status;

       }

	} while(login);

  return 0;
}
