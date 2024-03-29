#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>


int main(int argc, char const *argv[]) {

  /** User variable introduced into terminal. */
  char cmd[80];

  /** Password variable introduced into terminal. */
  char cmd2[80];

  /** Buffer used for reading the passwd file. */
  char bf[160];

  /** User/Password variable of the file. */
  char ps[80];

  /** Idexes for looping. */
  int i = 0;
  int login = 1;
  int status;
  char padre;

  /** Flags to know if user/password was correct or not*/
  int access = 0;
  int miss = 0;

  /** File with the users and passwords. */
  FILE *psd;

  /** Ask for the user and password until they are valid. */
  do {
    /**Opens files with users/passwords*/
    psd = fopen("passwd", "r");
    /**Gets one user/passwords*/
    fgets(bf, 80, psd);

    /**Asks for user and password to login*/
		printf("User: ");
		scanf("%s",cmd);
    printf("Password: ");
    scanf("%s",cmd2);

    /**Concatenates input user and password*/
    strcat(cmd, ":"); strcat(cmd, cmd2);

    /**Clears flag when try was incorrect*/
    miss = 0;

    /**Loop to check if user/password was correct or not*/
    do {
      /**Clear char indexes*/
      i = 0;
      /**Clears array of user/password form text file*/
      memset(ps, '\0', sizeof(ps));

      /** Gets User and Password from buffer. */
      while ((bf[i] != '\n') && (bf[i] != '\0'))
      {
        ps[i] = bf[i];
        i++;
      }

      /**Succesful login*/
      if(strcmp(ps, cmd) == 0)
      {
        access = 1;
      }

       /**User/password does not match the one analyzed (at the moment) on the list*/
       else
       {
         /**None of the users/passwords match with inputs*/
          if(fgets(bf, 80, psd) == NULL)
          {
              /**Flag to indicate mismatch with user/password*/
              miss = 1;

              /**Clears terminal after failed login*/
              popen("clear","w");
              wait(NULL);

              /**Indicates failed login*/
              printf("Wrong Password or User\n");
          }
       }
    } while((access == 0) && (miss == 0));

    /**Closes users/passwords file*/
    fclose(psd);

    /**Switch to shell if login was Succesful*/
    if(access == 1)
    {
        login = 0;

        /**Clears terminal after login*/
        popen("clear","w");
        wait(NULL);

        /** Replace process with the execution of sh. */
        padre = getpid() + 0;
        execlp("./sh","",NULL);
        wait(&status);
        return status;

       }

	} while(login);

  return 0;
}
