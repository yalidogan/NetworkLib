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


int client::initClient(int portNo, string IPAddr) {
    //This is the implementation of the client of the given server

    //Initializes the client socket and its variables
    initSocket(portNo, IPAddr);

    //Connects to the given IP Address
    connectToServer();

    return 0;

}


int client::writeMessageToServer(char *& buffer) {

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



void client::initSocket(int portNo, string IPAddr){
    portno = portNo;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd < 0){
        cliError("Error opening the client socket");
    }
    else{
        cout << "Successfully opened a client with sockfd " <<sockfd <<  endl;
    }


    bzero((char*) &serv_addr, sizeof(serv_addr)); //Set to 0
    serv_addr.sin_family = AF_INET;

    string IP = IPAddr;
    const char* charArrIP = IPAddr.c_str();

    inet_pton(AF_INET, charArrIP, &serv_addr.sin_addr.s_addr);

    serv_addr.sin_port = htons(portno);

}

void client::connectToServer() {

    if(connect(sockfd, (const sockaddr*) &serv_addr, sizeof(serv_addr)) < 0){
        cout << "Error connecting " << endl;
        //cliError("Error connecting");
    }
    else{
        cout << "Successfully connected to server" << endl;
    }
}


void client::send(char * buffer, const int bufferSize) {

    int n = 0;

    n = write(sockfd, buffer, strlen(buffer));

    if(n < 0){
        //Error on writing to the socket
        cout << "Error writing to the socket" << endl;

    }
    else{
        cout << "Successfully written the message to the socket" << endl;

    }

}

char* client::receiveFromServer(int bufferSize) {
    //To receive messages from the server
    int n = 0;
    char* buffer = new char[bufferSize];

    n = read(sockfd, buffer, bufferSize);

    if(n < 0){
        //Error
        cout << "Error reading from the server" << endl;
    }
    else if(n == 0){
        cout << "No data read from the socket" << endl;
    }
    else{
        cout << "Successfully read from the server" << endl;
        return buffer;
    }
}