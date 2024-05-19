#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define timeout 1

int main(){
	for(int i=0;i<5;i++){
		printf("hello\n");
		sleep(timeout);
	}
}