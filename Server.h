#ifndef Server_h
#define Server_h

#include <sys/socket.h>
#include <netinet/in.h>

struct Server
{
    /* data */
    int domain;
    int protocol;
    int service;
    u_long interface;
    int port;
    int backlog;

    struct sockaddr_in address;

    /* decl of a function pointer */
    void (*launch)(void);

};

struct Server server_constructor(int domain , int protocol, int service, u_long interface, int por, int backlog, void (*launch)(void));

#endif /* Server.h */