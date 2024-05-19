
#include <stdio.h>
#include <unistd.h>

void main(){
	printf("Process id: %d\n", getpid() );
	printf("Parent Process id: %d\n", getppid() );
}