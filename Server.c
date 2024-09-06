#include "Server.h"

//define server constructor

 struct Server server_constructor(int domain , int protocol, int service, u_long interface, int port, int backlog, void (*launch)(void))
 {
    struct Server server;
    server.domain = domain;
    server.protocol = protocol;
    server.service = service;
    server.interface = interface;
    server.port = port;
    server.backlog = backlog;
    
    server.address.sin_family = domain;
    /* converts port into bytes that would refer to a network port*/
    server.address.sin_port = htons(port);
    /* creates socket connection to network, allows OS to communicate with the network*/
    server.sock = socket(domain, service, protocol);

    if (server.sock == 0)
    {
        perror("socket failed to create");
        exit(1);
    }

   /* binds the socket to the network */
    if (bind(server.sock, (struct sockaddr *) &server.address, sizeof(server.address)) < 0)
    {
        perror("bind failed");
        exit(1);
    }

    if (listen(server.sock, backlog) < 0)
    {
        perror("listen failed");
        exit(1);
    }
    /* creates server object */
    server.launch = launch;
   

    /* does the same thing as htons but for a long */
    server.address.sin_addr.s_addr = htonl(interface);

 }