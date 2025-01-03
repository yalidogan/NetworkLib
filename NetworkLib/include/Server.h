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
    int initServer(int portNoIs, int bufferSizeIs, int& initID, int& bindID);
    void closeSockets();
    char* receiveMessage(int &n);
    int acceptConnection(); //Return the connection identifier
    int send(char* buffer, int size); //To send data to the client

private:
    void error(const char* msg);
    int initSocket();
    int bindSocket();
    void waitForConn();
    int readFromClient(char *& buffer); //Pass the buffer by reference to the method


    int sockfd, newsockfd, portno, bufferSize;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen; //Length of the socket address


};

#endif //SOCKET_SERVER_H
