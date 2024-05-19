# Server 

1. Initialise IP address and port number.
2. Create a UDP socket using socket() system call, if negetive print error
3. Bind the socket to local address using bind() system call, if negetive print "bind error"
4. Receive messages from client using recvfrom() system call
5. Send time data to client using sendto() system call 
6. Exit.

# Client 

1. Initialise IP address and port number.
2. Create a socket using socket() system call.
3. Send a message to server using sendto() system call.
4. Receive time from server using recvfrom() system call
5. Exit