//
// Created by admin on 25.06.2024.
//

#ifndef SOCKET_CLIENT_H
#define SOCKET_CLIENT_H
#include <iostream>
#include <cstring>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <cstdlib>
#include "client.h"
#include <netdb.h>
#include <arpa/inet.h>


class client{

public:
    client() = default;
    int initClient();

private:
    int sockfd, portno, n; //The variables for the client
    struct sockaddr_in serv_addr;
    struct hostent* server;

    void cliError(const char* msg);
    int writeMessageToServer(int sockfd, char *& buffer);
    int readMessageFromServer(int sockfd, char*& buffer);
    void clearBuffer(char*& buffer, int size);


    void initSocket();
    void connectToServer();
    void manageConn(char *& buffer);

};

#endif //SOCKET_CLIENT_H
