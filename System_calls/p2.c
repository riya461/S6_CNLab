// create child process and allow process to display parent or child 


#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int pid,status;
	pid = fork();
	if(pid == -1){
		perror("Bad fork\n");
		return 1;
	}
	if(pid == 0){
		printf("Child: %d\n",pid);
	}
	else{
		wait(&status);
		printf("Parent: %d\n",pid);		
	}
	return 0;
}