
// server program for udp connection
#include <stdio.h>
#include <time.h>
#include <strings.h>
#include<string.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include<netinet/in.h>
#define PORT 8057
#define MAXLINE 1000

// Driver code
int main()
{
char buffer[100];
char input[10];
char *message ;
int listenfd, len;
struct sockaddr_in servaddr, cliaddr;
bzero(&servaddr, sizeof(servaddr));

// Create a UDP Socket
listenfd = socket(AF_INET, SOCK_DGRAM, 0);
servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
servaddr.sin_port = htons(PORT);
servaddr.sin_family = AF_INET;

// bind server address to socket descriptor
bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr));

//receive the datagram
len = sizeof(cliaddr);
printf("Connection Established....\n");
while(1)
{

int n = recvfrom(listenfd, buffer, sizeof(buffer),0, (struct sockaddr*)&cliaddr,&len); //receive message from server
buffer[n] = '\0';
printf("Recieved: ");
puts(buffer);
if(strcmp(buffer,"request")==0)
{
time_t t = time ( NULL );
struct tm * tm = localtime (& t);
char current_time [ MAXLINE];
strftime ( current_time , MAXLINE , "%Y -%m -%d %H:%M:%S", tm ) ;

sendto(listenfd, current_time, MAXLINE, 0,(struct sockaddr*)&cliaddr, sizeof(cliaddr));
}
}
} 
