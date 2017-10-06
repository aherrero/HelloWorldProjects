/****************** CLIENT CODE ****************/

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>

int main(int argc , char *argv[])
{
    int port = 8888;
    if (argc > 1)
    {
        port = atoi(argv[1]);
        printf("Port number: %d\n", port);
        //port = 1234
    }

    char ipaddress[] = "127.0.0.1";
    if (argc > 2)
    {
        strcpy(ipaddress, argv[2]);
        printf("IP Address: %s\n", ipaddress);
        //ipaddress = "192.168.0.2";
    }

    int clientSocket;

    char buffer[1024];
    struct sockaddr_in serverAddr;
    socklen_t addr_size;

    /*---- Create the socket. The three arguments are: ----*/
    /* 1) Internet domain 2) Stream socket 3) Default protocol (TCP in this case) */
    clientSocket = socket(PF_INET, SOCK_STREAM, 0);

    /*---- Configure settings of the server address struct ----*/
    /* Address family = Internet */
    serverAddr.sin_family = AF_INET;
    /* Set port number, using htons function to use proper byte order */
    serverAddr.sin_port = htons(port);
    /* Set IP address to localhost */
    serverAddr.sin_addr.s_addr = inet_addr(ipaddress);
    /* Set all bits of the padding field to 0 */
    memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  

    /*---- Connect the socket to the server using the address struct ----*/
    addr_size = sizeof serverAddr;
    int res = connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size);
    if(res != 0)
    {
	printf("Error connecting to the server: %s\n", strerror(errno));
	close(clientSocket);
	return -1;
    }
    printf("Client connected to the server.\n");


    /*---- Read the message from the server into the buffer ----*/
    //recv(clientSocket, buffer, 1024, 0);
    printf("Enter message : ");
    scanf("%s" , buffer);
    send(clientSocket , buffer , strlen(buffer) , 0);
    printf("Message Sent\n");

    /*---- Print the received message ----*/
    //printf("Data received: %s",buffer);   

    close(clientSocket);

    return 0;
}
