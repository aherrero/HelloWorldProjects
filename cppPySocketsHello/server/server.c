/****************** SERVER CODE ****************/

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

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

    int welcomeSocket, newSocket;
    char buffer[1024];
    struct sockaddr_in serverAddr;
    struct sockaddr_storage serverStorage;
    socklen_t addr_size;

    /*---- Create the socket. The three arguments are: ----*/
    /* 1) Internet domain 2) Stream socket 3) Default protocol (TCP in this case) */
    welcomeSocket = socket(PF_INET, SOCK_STREAM, 0);

    /*---- Configure settings of the server address struct ----*/
    /* Address family = Internet */
    serverAddr.sin_family = AF_INET;
    /* Set port number, using htons function to use proper byte order */
    serverAddr.sin_port = htons(port);
    /* Set IP address to localhost */
    serverAddr.sin_addr.s_addr = inet_addr(ipaddress);
    /* Set all bits of the padding field to 0 */
    memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  

    /*---- Bind the address struct to the socket ----*/
    bind(welcomeSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

    /*---- Listen on the socket, with 5 max connection requests queued ----*/
    if(listen(welcomeSocket,5) == 0)
        printf("Listening\n");
    else
        printf("Error\n");

    /*---- Accept call creates a new socket for the incoming connection ----*/
    addr_size = sizeof serverStorage;
    newSocket = accept(welcomeSocket, (struct sockaddr *) &serverStorage, &addr_size);
    printf("Client accepted\n");


    /*---- Send message to the socket of the incoming connection ----*/
    //strcpy(buffer,"Hello World\n");
    //send(newSocket,buffer,13,0);
    printf("Waiting message\n");
    recv(newSocket , buffer , 1024 , 0);

    printf("Server: %s\n", buffer);

    close(newSocket);
    close(welcomeSocket);

    return 0;
}
