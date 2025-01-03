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
#include "/home/admin/CLionProjects/test/Library/NetworkLib/include/Server.h"

#define BUFF_SIZE 80
#define PORT 8080
#define SA struct sockaddr

using namespace std;


void Server::error(const char *msg) {
    perror(msg);
    exit(1); //Exit code is 1 for the server
}

Server::Server() = default;

int Server::initServer(int portNoIs) {

    portno = portNoIs;
    //Create the server

    char* buffer = new char[256]; //For the data
    //Transport address and port

    int n;

//Initializes the socket
    initSocket();

//waitForConnections
//manageConn or something

//Binds the socket to a port on the computer
    bindSocket();

    //Listents for connections
    waitForConn();

    //Handles the connections between client and server socket
    handleConn(buffer);

    closeSockets(); //Closes the sockets with the file descriptors
    return 0; //Never reached
}


void Server::closeSockets() {
    close(sockfd);
    close(newsockfd);
}

int Server::readFromClient(char *&buffer) {
    //Return 1 on success and -1 on failure with their own prints
    int n = 0;

    n = read(newsockfd, buffer, 255);

    if (n < 0) {
        cout << "Error reading from the socket" << endl;
        return -1; //Go out to the other loop and listen for connections
    }
    else if(n == 0){
        cout << "Client disconnected" << endl;
        return -1;
    }
    else {
        cout << "Successfully received the message" << endl;
        cout << "The message is: " << buffer << endl;
        return 1;
    }
}

int Server::writeToClient(char *&buffer) {
    int n = 0;
    n = write(newsockfd, "Message received.", 18);
    cout << "End of transmission " << endl;

    if (n < 0) {
        cout << "Error writing message to socket" << endl;
        cout << "Client disconnected" << endl;
        return -1;
    }
    else{
        cout << "Write successful" << endl;
        return 1;
    }


}

void Server::initSocket() {
    //Initializes the server socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0); //this is the socket ID returned by the syscall
    if (sockfd < 0) {
        //The socket could not be opened
        error("Error opening the socket");
    } else {
        cout << "Successfully opened the socket with socketfd " << sockfd << endl;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr)); //To set the struct as null
    portno = 8080; //Pre defined


//Bind the server to the client socket
//Here define the protocols and connection
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno); //htons to convert the normal bytes to network applicable use
    serv_addr.sin_addr.s_addr = INADDR_ANY;
}

void Server::bindSocket() {
    //Binds the server socket to a client socket
    //Bind the socket to a port in the local computer
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        //Check if the bind was successful
        error("Error on binding");
    } else {
        cout << "Successfully binded the socket to port " << portno << endl;
    }


}

void Server::waitForConn() {
    cout << "Waiting for new connections..." << endl;
    listen(sockfd, 5);

}

void Server::handleConn(char*& buffer) {
    while (1) {

        clilen = sizeof(cli_addr);

        //Accept the new connection
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

        if (newsockfd < 0) {
            error("Error on accepting");
            //cout << "Error on accepting" << endl;
        } else {
            cout << "Accepted a message from client socket with fd " << newsockfd << endl;
        }

        while (1) {
            //READ FROM CLIENT
            if (newsockfd < 0) {
                cout << "Disconnected" << endl;
                break;
            }
            cout << "Awaiting new message..." << endl;

            bzero(buffer, 256); //Clear the buffer

            int readSuccessful = readFromClient(buffer);
            if(readSuccessful == -1){
                break;
            }
//======================================================================================
            //WRITE TO CLIENT

            int writeSuccessful = writeToClient(buffer);
            if(writeSuccessful == -1){
                break;
            }
        }
        close(newsockfd);

    }
}