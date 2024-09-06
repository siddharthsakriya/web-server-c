#include <stdio.h>
#include "Server.h"

void launch(struct Server *server)
{
    printf("WAITING FOR CONNECTIONS\n");
    int addr_len = sizeof(server->address);
    int new_socket = accept(server->sock, (struct sockaddr *) &server->address, (socklen_t *) &addr_len);
};

int main()
{
    struct Server server = server_constructor(AF_INET, 0, SOCK_STREAM, INADDR_ANY, 80, 10, NULL); 
    server.launch();
    return 0;
};