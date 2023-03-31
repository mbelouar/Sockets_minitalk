# Sockets_minitalk
The purpose of this project is to code a small data exchange program using SOCKETS.

# What is socket programming?
Socket programming is a way of connecting two nodes on a network to communicate with each other. One socket(node) listens on a particular port at an IP, while the other socket reaches out to the other to form a connection. The server forms the listener socket while the client reaches out to the server.

# Stages for server
![alt text for screen readers](https://media.geeksforgeeks.org/wp-content/uploads/20220330131350/StatediagramforserverandclientmodelofSocketdrawio2-448x660.png "Socket Programming in C").

# 1. Socket creation:
The first stage deals with the creation of a socket, which is the basic component for sending or receiving signals between nodes. The sys/socket.h header has the necessary functions to create a socket in C. In socket programming in C, a socket can be created by the socket() function with syntax   :

` int sockfd = socket(domain, type, protocol) `
```
    
    * The domain represents the address family over which the communication will be performed. The domain is pre-fixed values present in the sys/socket.h header. Some domains are,
        AF_LOCAL or AF_UNIX is used for local communication or in the case where the client and server are on the same node. These sockets are called UNIX domain sockets.
        AF_INET is used to represent the IPv4 address of the client to which a connection should be made. Similarly AF_INET6 is used for IPv6 addresses. These sockets are called internet domain sockets.
        AF_BLUETOOTH is used for low-level Bluetooth connection.
    * The type represents the type of communication used in the socket. Some mostly used types of communication are,
        SOCK_STREAM uses the TCP(Transmission Control Protocol) to establish a connection. This type provides a reliable byte stream of data flow and is a connection-based protocol. These sockets are called stream sockets.
        SOCK_DGRAM uses the UDP(User Datagram Protocol) which is unreliable and a connectionless protocol. These sockets are also called datagram sockets.
    * The protocol represents the protocol used in the socket. This is represented by a number. When there is only one protocol in the protocol family, the protocol number will be 0, or else the specific number for the protocol has to be specified.
    
    -> The socket() function creates a socket and returns a file descriptor which represents an open file that will be utilized by the socket in reading and writing operations and the file descriptor is used to represent the socket in later stages. In case of an error in creating the socket, -1 is returned by the socket() function.

```

# 2. Setsockopt:
The setsockopt() function in socket programming in C is used to specify some options for the socket to control the behavior of the socket. The syntax is  :

` int setsockopt(int socket_descriptor, int level, int option_name, const void *value_of_option, socklen_t option_length); `

```

    * The socket is the file descriptor returned by the socket() function.
    * The level parameter represents the level at which the option for the socket must be applied. The SOL_SOCKET represents the socket level and IPPROTO_TCP represents the TCP level.
    * The option_name specifies the rules or options that should be modified for the socket. Some useful options are,
        SO_DEBUG is used to enable the recording of debugging information.
        SO_REUSEADDR is used to enable the reusing of local addresses in the bind() function.
        SO_SNDBUF is used to set the maximum buffer size that can be sent using the socket connection.
    * The option_value is used to specify the value for the options set in the option_name parameter.
    * The option_length is the length of the variable used to set the option value.

    -> The function returns a value of 0 of data type int on the successful application of the option and a value of -1 on failure.
```

# 3. Bind:
The bind() function in socket programming in C is used to assign an address to a socket created using the socket() function. The syntax of bind() function is :

` int bind(int socket_descriptor , const struct sockaddr *address, socklen_t length_of_address); `

```

    * The socket_descriptor is the value of the file descriptor returned by the socket() function.
    * The address is a structure of type sockaddr. We usually use a structure of type sockaddr_in to represent this information, because information such as port and address can only be stored in this structure. The sockaddr_in is cast to the sockaddr data type when calling the bind() function.
    * The length_of_address represents the size of the address passed as the second parameter.

    -> The function returns 0 on binding the address and port successfully or returns -1 on failure.
```

# 4. Listen:
The listen() function in socket programming is used to make the server node wait and listen for connections from the client node on the port and address specified by the bind() function. The syntax is :

` int listen(int socket_descriptor, int back_log); `

```

    * The socket_descriptor represents the value of the file descriptor returned by the socket() function.
    * The back_log marks the maximum number of connection requests that can be made to the server by client nodes at a time. The number of requests made after the number specified by back_log may cause an error or will be ignored by the server if the options for retransmission are set.

    -> The function returns 0 on listening on the address and port specified or returns -1 on failure.
```

# 5. Accept:
The accept() function is used to establish a connection between the server and the client nodes for the transfer of data. The syntax is :

` int accept(int socket_descriptor, struct sockaddr *restrict address, socklen_t *restrict length_of_address); `

```

    * The socket_descriptor represents the value of the file descriptor returned by the socket() function.
    * The address is the variable of the sockaddr_in structure in which the address of the socket returned from the function will be stored.
    * The length_of_address depicts the size of the address parameter.

    -> The accept() function creates a new socket from the first connection request for the specified socket_descriptor and returns the file descriptor of the new socket. The file descriptor of this new socket is used in the read() and write() functions to send and receive data to and from the client node.
```

# 6. Connect:
The connect() function is used to send the connection request and connect to the server node. The syntax of the function is :

`int connect(int socket_descriptor, const struct sockaddr *address, socklen_t length_of_address); `

```

    * The socket_descriptor represents the value of the file descriptor returned by the socket() function during the creation of a socket on the client-side.
    * The address represents the structure with the information of the address and port number of the server node to which the connection is to be made.
    * The length_of_address is the size of the address structure used in the second parameter.

    -> The connect() function returns a value of 0 on successfully connecting with the server and returns a value of -1 on error or the connection fails.
```

# Stages for Client

> ***Socket connection:***  Exactly same as that of server’s socket creation
>
> ***Connect:***  The connect() system call connects the socket referred to by the file descriptor sockfd to the address specified by addr. Server’s address and port is specified in addr.

```diff
+ By   : Bickle
```
