// TcpClasses.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include "TcpServer.h"
#include "TcpClient.h"

int main()
{
    std::cout << "Hello World!\n";

    const char* address = "127.0.0.1";
    WORD port = 27016;

    TcpServer server;
    server.createSocket();
    server.bindSocket(address, port);
    server.listenSocket();
    server.acceptConnection();
    char * data = server.recvData();
    printf(" - Data: %s\n", data);
    server.sendData("What's up Client?");
    while (1) {};

    //TcpClient client;
    //client.createSocket();
    //client.connectServer(address, port);
    //client.sendData("HIHIHI");

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
