#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
  /* code */
char cmd[80];
char cmd2[80];
int login = 2;


  do {
		printf("User: ");
		scanf("%[^\n]%*c",cmd);
    printf("Password: ");
    scanf("%[^\n]%*c",cmd2);

    if((strcmp("a", cmd) == 0) && (strcmp("a", cmd2) == 0)) {
       //login = 0;
       printf("SI jala\n");
       fork();
       getchar();
       execlp("xterm","-n","-e","./sh",  NULL); //"-e", "./getty", NULL);
     } else {
       printf("Password or User wrong\n\n\n");
     }


	} while(login);

//  fork();
  return -1;
}
