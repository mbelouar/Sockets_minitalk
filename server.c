/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 22:58:16 by mbelouar          #+#    #+#             */
/*   Updated: 2023/03/30 22:58:22 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sockets.h"

int main()
{
    char *ip = "127.0.0.1";
    
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t   addr_size;
    char buffer[1024];
    int bind_int;

    // socket function is used to creating socket file descriptor
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    // AF_INET is used torepresent the IPv4 address
    // AF_INET6 for the IPv6
    // SOCK_STREAM : use the TCP
    // SOCK_DGRAM : uses the UDP

    if (server_fd < 0) // condition if the socket was not created
    {
        perror("[-]Socket FAILED");
        exit(EXIT_FAILURE);
    }
    printf("\n[+] TCP server socket created.\n");

    memset(&server_addr, '\0', sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = PORT;
    server_addr.sin_addr.s_addr = inet_addr(ip);

    // the bind fuinction is used to assign an address to a socket created
    bind_int = bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    // We usually use a structure of type sockaddr_in to represent this information
    //  because information such as port and address can only be stored in this structure
    // The sockaddr_in is cast to the sockaddr data type when calling the bind() function.

    if (bind_int < 0) // condition if the bind function failed
    {
        perror("[-] Bind FAILED");
        exit(EXIT_FAILURE);
    }
    printf("[+] Bind to the port numbetr : %d\n", PORT);

    // listen function is used to make the server node wait and listen for connections from the client node
    // on the port and address specified by the bind() function. 
    if (listen(server_fd, 5) < 0)
    {
        perror("[-] Listen FAILED");
        exit(EXIT_FAILURE);
    }
    // 5 : represent the maximum number of connection requests that can be made to the server by client nodes at a time.
    printf("\nListening ...\n");

    while (1)
    {
        addr_size = sizeof(client_addr);
        // accept function is used to establish a connection between the server and the client nodes for the transfer of data
        client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &addr_size);
        printf("\n[+] Client connected.\n");

        bzero(buffer, 1024);
        // The recv() function receives data on a socket with descriptor socket and stores it in a buffer.
        recv(client_fd, buffer, sizeof(buffer), 0);
        // The recv() call applies only to connected sockets. 
        printf("\nClient : %s", buffer);

        bzero(buffer, 1024);
        strcpy(buffer, "HI THIS IS THE SERVER. THANK YOU FOR THE MESSAGE THAT YOU SENT!");
        // The send() function sends data on the socket with descriptor socket.
        send(client_fd, buffer, strlen(buffer), 0);
        // The send() call applies to all connected sockets. 

        close(client_fd);
        printf("\n\nClient disconnected\n\n");
    }

    return (0);
}
