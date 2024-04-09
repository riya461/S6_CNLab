## Server

1. Initialise IP address and port number.
2. Create a TCP socket using socket() system call.
3. Bind the socket to local address using bind() system call.
4. Listen to client using listen() system call.
5. Accept a connection from client using accept() system call.
6. Receive the filename from client using recv() system call.
7. If the requested file is in the server, send it to client along with the process id using send() system call. Else sent a message "File is not found".
7. Exit.

## Client

1. Initialise IP address and port number.
2. Create a socket using socket() system call.
3. Connect to server using connect() system call.
4. Request a file to server using send() system call.
5. Receive the process id along with either the file or error message from the server
using recv() system call.
5. Exit
