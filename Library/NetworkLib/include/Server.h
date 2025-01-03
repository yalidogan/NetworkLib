//
// Created by admin on 25.06.2024.
//

#ifndef SOCKET_SERVER_H
#define SOCKET_SERVER_H

#include <iostream>
#include <cstring>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <cstdlib>
#include <signal.h>

class Server{

public:

    Server();
    int initServer(int portNoIs);

private:
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen; //Length of the socket address

    void handleConn(char*& buffer); //Handles the connection for concurrent processes
    void error(const char* msg);
    void closeSockets();
    int readFromClient(char*& buffer); //Pass the buffer by reference to the method
    int writeToClient(char*& buffer);
    void openSocket();
    void initSocket();
    void bindSocket();
    void waitForConn();
};

#endif //SOCKET_SERVER_H
