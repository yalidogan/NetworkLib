//
// Created by admin on 24.06.2024.
//
#include <iostream>
#include <cstring>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <cstdlib>
#include <signal.h>
#include "Server.h"

#define BUFF_SIZE 80
#define PORT 8080
#define SA struct sockaddr

using namespace std;


void Server::error(const char *msg) {
    perror(msg);
    exit(1); //Exit code is 1 for the server
}

Server::Server() = default;

int Server::initServer(int portNoIs, int bufferSizeIs, int &initID, int &bindID) {

    portno = portNoIs;
    //Create the server
    bufferSize = bufferSizeIs;
    //Transport address and port

    int n;

    //Set the port and init the socket
    initID = initSocket();
    //Binds the socket to a port on the computer
    bindID = bindSocket();
    //Listen for connection
    waitForConn();

    //Accept the new connection and wait here
     acceptConnection();


    return 0; //Never reached
}


void Server::closeSockets() {
    close(sockfd);
    close(newsockfd);
}

int Server::readFromClient(char *& buffer) {
    //Return 1 on success and -1 on failure
    int n = 0;

    n = read(newsockfd, buffer, 255);
    //The return is the number of bytes read

    if (n < 0) {  
        cout << "Error reading from the socket" << endl;
        return n; //Go out to the other loop and listen for connections
    }
    else if(n == 0){
        cout << "Client disconnected" << endl;
        return n;
    }
    else { // n > 0
        //cout << "Successfully received the message" << endl;
        //cout << "The message is: " << buffer << endl;
        return n;
    }

}



int Server::initSocket() {
    //Initializes the server socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0); //this is the socket ID returned by the syscall

    if (sockfd < 0) {
        //The socket could not be opened
        //error("Error opening the socket");
        cout << "Error on opening the socket" << endl;

    } else {
        cout << "Successfully opened the socket with socketfd " << sockfd << endl;

    }

    bzero((char *) &serv_addr, sizeof(serv_addr)); //To set the struct as null


    //Bind the server to the client socket
    //Here define the protocols and connection
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno); //htons to convert the normal bytes to network applicable use
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    return sockfd;
}

int Server::bindSocket() {
    //Binds the server socket to a client socket
    //Bind the socket to a port in the local computer
    int n = bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
    if (n < 0) {
        //Check if the bind was successful
        //error("Error on binding");
        cout << "Error on binding" << endl;
        return n;

    } else {
        cout << "Successfully binded the socket to port " << portno << endl;
        return n;
    }


}

void Server::waitForConn() {
    cout << "Waiting for new connections..." << endl;
    listen(sockfd, 5);

}

char* Server::receiveMessage(int &n) {
    //READ FROM CLIENT
    char* buffer = new char[bufferSize]; //For the incoming message

    if (newsockfd < 0) {
        //cout << "Disconnected" << endl;
        error("Disconnected!");
    }
    cout << "Awaiting new message..." << endl;

    bzero(buffer, 256); //Clear the buffer

    int readSuccessful = readFromClient(buffer);
    n = readSuccessful;

    return buffer;


}

int Server::acceptConnection() {

    clilen = sizeof(cli_addr);
    //Accept the new connection
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

    if (newsockfd < 0) {
        //error("Error on accepting");
        cout << "Error on accepting" << endl;
    } else {
        cout << "Accepted a message from client socket with fd " << newsockfd << endl;
        return newsockfd;
    }

}


int Server::send(char *buffer, int size) {
    int n = 0;
    n = write(newsockfd, buffer, size);

    return n;
}



