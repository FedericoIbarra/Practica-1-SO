#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>


int main() {
  /* code */
char cmd[80];
char cmd2[80];
char bf[160];
char usr[80];
char ps[80];
int i = 0, i2 = 0;

  FILE *psd;
  psd = fopen("passwd", "r");

  fgets(bf, 80, psd);



  while (bf[i] != ':') {
    usr[i] = bf[i];
    i++;
  }

  i++;

  while (bf[i] != ' ') {
    ps[i2] = bf[i];
    printf("%c\n", bf[i]);
    i++;
    i2++;
  }


  do {
		printf("User: ");
		scanf("%[^\n]%*c",cmd);
    printf("Password: ");
    scanf("%[^\n]%*c",cmd2);

    if((strcmp(usr, cmd) == 0) && (strcmp(ps, cmd2) == 0)) {
       fork();
       execlp("xterm","-n","-e","./sh",  NULL); 
     } else {
       printf("Password or User wrong\n\n\n");
     }


	} while(login);

  return -1;
}
