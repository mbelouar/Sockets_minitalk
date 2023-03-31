/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 22:58:32 by mbelouar          #+#    #+#             */
/*   Updated: 2023/03/30 22:58:33 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sockets.h"

// Stages for Client
/*The client-side sends the connection requests to the server-side.
To perform these several stages have to be performed on the client side,*/

int main(int argc, char** argv)
{
    if (argc != 3)
        return (printf("invalid args\n") * 0);
    char *ip = argv[1];
    
    int status;
    int client_fd;
    struct sockaddr_in addr;
    char buffer[1024] = {0};
    char* hello_msg = argv[2];

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
    printf("\n[+] TCP client socket created.\n");

    memset(&addr, 0, sizeof(addr));

    addr.sin_family = AF_INET;
    addr.sin_port = PORT;
    addr.sin_addr.s_addr = inet_addr(ip);

    // The connect() function is used to send the connection request and connect to the server node.
    status = connect(client_fd, (struct sockaddr *)&addr, sizeof(addr));
    if (status < 0) // check if the connection was done.
    {
        perror("[-] The connection is FAILED");
        return(-1);
    }
    printf("\nConnected to the server.\n");

    send(client_fd, hello_msg, strlen(hello_msg), 0);

    // bzero(buffer, 1024);
    recv(client_fd, buffer, sizeof(buffer), 0);
    printf("\nServer : %s", buffer);

    close(client_fd);
    printf("\n\nDisconnected from the server.\n");
    return (0);
}
