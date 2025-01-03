//
// Created by admin on 25.06.2024.
//

#ifndef SOCKET_CLIENT_H
#define SOCKET_CLIENT_H
using namespace std;
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
    int initClient(int portNo, string IPAddr);
    void connectToServer();
    void send(char * buffer, int bufferSize); // Send the given string to the server
    char* receiveFromServer(int bufferSize);



private:
    int sockfd, portno, n; //The variables for the client
    struct sockaddr_in serv_addr;
    struct hostent* server;

    void initSocket(int portNo, string IPAddr);
    void cliError(const char* msg);
    int writeMessageToServer(char *& buffer);





};

#endif //SOCKET_CLIENT_H
