#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
  /* code */
char cmd[80];
char cmd2[80];


  do {
		printf("User: ");
		scanf("%[^\n]%*c",cmd);
		//system(cmd);
	} while(strlen(cmd) == 0);

  while (strlen(cmd2) == 0) {
    printf("Password: \n");
    scanf("%[^\n]%*c",cmd2);
  }

}
