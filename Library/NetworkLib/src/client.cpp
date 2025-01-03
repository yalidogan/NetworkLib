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
#include "client.h"
#include <netdb.h>
#include <arpa/inet.h>
#define BUFF_SIZE 80
#define PORT 8080
#define SA struct sockaddr

using namespace std;



//For the error handling in the program
//Perror prints and error message and exit is for the abnormal termination

void client::cliError(const char *msg){

    perror(msg);
    exit(0); //Exit code 0 for the client error

}


int client::initClient() {
    //This is the implementation of the client of the given server



    char *buffer = new char[256];

    //Initializes the client socket and its variables
    initSocket();

    //Connects to the given IP Address
    connectToServer();

    //Manages the connection by reading and writing the messages with the server
    manageConn(buffer);



    return 0;

}


int client::writeMessageToServer(int sockfd, char *&buffer) {

    int n = 0;

    n = write(sockfd, buffer, strlen(buffer));

    if(n < 0){
        //Error on writing to the socket
        cout << "Error writing to the socket" << endl;
        return -1;
    }
    else{
        cout << "Successfully written the message to the socket" << endl;
        return 1;
    }
}


int client::readMessageFromServer(int sockfd, char *&buffer) {
    int n = 0;

    n = read(sockfd, buffer, 255);

    if(n < 0){
        cliError("Error reading from the socket");
        return -1;
    }
    else{
        cout << "Successfully read from the socket" << endl;
        return 1;
    }

}

void client::clearBuffer(char *&buffer, int size) {
    bzero(buffer, size);
}


void client::initSocket(){
    portno = 8080;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd < 0){
        cliError("Error opening the client socket");
    }
    else{
        cout << "Successfully opened the client socket" << endl;
    }


    bzero((char*) &serv_addr, sizeof(serv_addr)); //Set to 0
    serv_addr.sin_family = AF_INET;

    string IP = "127.0.0.1";

    inet_pton(AF_INET, ("127.0.0.1"), &serv_addr.sin_addr.s_addr);

    serv_addr.sin_port = htons(portno);

}

void client::connectToServer() {
    if(connect(sockfd, (const sockaddr*) &serv_addr, sizeof(serv_addr)) < 0){
        cliError("Error connecting");
    }
    else{
        cout << "Successfully connected to server" << endl;
    }
}

void client::manageConn(char*& buffer) {

    while(1){
        cout << "Please enter a message:" << endl;
        //bzero(buffer, 256); //Set the buffer to 0
        clearBuffer(buffer, 256);

        fgets(buffer, 255, stdin);

        int successfullyWritten = writeMessageToServer(sockfd, buffer);

        //bzero(buffer, 256); //Clear the buffer
        clearBuffer(buffer, 256);

        int successfullyRead = readMessageFromServer(sockfd, buffer);

        printf("%s\n", buffer);
    }

}