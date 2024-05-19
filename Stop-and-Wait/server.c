# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <arpa/inet.h>
#include <time.h>


 void main () {
 char *ip = "127.0.0.100";
 int port = 5560;

 int sockfd ;
 struct sockaddr_in server_addr , client_addr ;
 char buffer [1024];
 socklen_t addr_size ;
 int n;

 sockfd = socket ( AF_INET , SOCK_DGRAM ,0) ;
 if( sockfd <0) {
 perror ("[ -] Socket error ") ;
 exit (1) ;
 }

 memset (&server_addr ,'\0',sizeof ( server_addr )) ;
 server_addr.sin_family= AF_INET ;
 server_addr.sin_port = htons ( port ) ;
 server_addr.sin_addr . s_addr = inet_addr ( ip ) ;

 n = bind ( sockfd ,( struct sockaddr *) & server_addr , sizeof ( server_addr ));
 if(n <0) {
 perror ("[+] Bind error ");
 exit (1) ;
 }

 while (1) {
 bzero ( buffer ,1024) ;
 addr_size = sizeof ( client_addr );

 // Receive the data packet
 recvfrom ( sockfd , buffer ,1024 ,0 ,( struct sockaddr *) & client_addr ,& addr_size );

 printf (" Server : Received packet %s\n", buffer ) ;
 sleep (1) ;
 printf (" Server : Sending acknowledgement from packet %s\n", buffer );
//  Send acknowledgement to sender
 sendto ( sockfd , buffer ,1024 ,0 ,( struct sockaddr *) & client_addr , sizeof ( client_addr ));
 }
 }
