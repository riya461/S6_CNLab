#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

void main(){
	int fd,n1,n2,f;
	char buff[50],data[50];
	printf("Enter the text\n");
	n1 = read(0,buff,50);
	fd = open("file.txt", O_CREAT | O_RDWR , 0777);
	write(fd,buff,n1);
	int close(int fd);

	f = open("file.txt",O_RDONLY);
	n2 = read(f,data,n1);
	data[n2]='\0';
	printf("The data in file: %s\n", data);
	int close(int f);

}