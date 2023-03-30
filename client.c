#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORT 8080

// Stages for Client
/*The client-side sends the connection requests to the server-side.
To perform these several stages have to be performed on the client side,*/

int main()
{
    char *ip = "127.0.0.1";
    
    int client_fd;
    struct sockaddr_in addr;
    socklen_t   addr_size;
    char buffer[1024];
    char* hello_msg = "HELLO FROM THE CLIENT";
    int status, valread;

    // socket function is used to creating socket file descriptor
    client_fd = socket(AF_INET, SOCK_STREAM, 0);
    // AF_INET is used torepresent the IPv4 address
    // AF_INET6 for the IPv6
    // SOCK_STREAM : use the TCP
    // SOCK_DGRAM : uses the UDP

    if (client_fd < 0) // condition if the socket was not created
    {
        perror("[-]Socket FAILED");
        exit(EXIT_FAILURE);
    }
    printf("[+]TCP client socket created.\n");

    memset(&addr, '\0', sizeof(addr));

    addr.sin_family = AF_INET;
    addr.sin_port = PORT;
    addr.sin_addr.s_addr = inet_addr(ip);

    // The connect() function is used to send the connection request and connect to the server node.
    status = connect(client_fd, (struct sockaddr *)&addr, sizeof(addr));
    if (status < 0) // check if the connection was done.
    {
        perror("[-]The connection is FAILED");
        return(-1);
    }
    printf("\nConnected to the server.\n");

    bzero(buffer, 1024);
    strcpy(buffer, hello_msg);
    printf("\nClient : %s\n", buffer);
    send(client_fd, buffer, strlen(buffer), 0);

    bzero(buffer, 1024);
    recv(client_fd, buffer, sizeof(buffer), 0);
    printf("\nServer : %s", buffer);

    close(client_fd);
    printf("\nDisconnected from the server.\n");
    return (0);
}