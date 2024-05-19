# Server 

1. Receive the data packet 
2. Send the acknowledgement to the sender 
3. Exit 

# Client 

1. Initialise an array of packets 
2. Initialise PACKETCOUNTER to 0
3. Initialise WINDOWSIZE
4. Send the window packets
5. When acknowledgement is received for the first packet in the window, slide
the window.
6. If no acknowledgment is received or negative acknowledgement is received,
send the missing packet again.
7. Repeat the process till all packets are transmitted.
8. Exit