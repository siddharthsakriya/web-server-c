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

    /* does the same thing as htons but for a long */
    server.address.sin_addr.s_addr = htonl(interface);

 }