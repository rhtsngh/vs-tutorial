// ClientApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "TcpSocketBridge.h"

void messageReceived(messageStruct* s)
{
    std::cout << "Client received: " << s->message << std::endl;
}

int main()
{
    std::cout << "Hello World! This is Client.\n";

    const char* address = "127.0.0.1";
    WORD port = 27016;

    //HANDLE handler;
    //handler = Client::CreateInstance();
    //Client::CreateSocket((TcpClient*)handler);
    //Client::ConnectServer((TcpClient*)handler, address, port);
    //Client::SendData((TcpClient*)handler, "Hello Server");
    //char* data = Client::RecvData((TcpClient*)handler);
    //std::cout << "Got data: " << data << std::endl;
    //Client::DisposeInstance((TcpClient*)handler);

    HANDLE handler;
    handler = ClientCreateInstance(address, port);
    ClientConnectToHost((TcpSocket*)handler);
    ClientSetMessageCallback((TcpSocket*)handler , &messageReceived);
    ClientSendData((TcpSocket*)handler, "Hello Server");
    //char* data = ClientRecvData((TcpSocket*)handler);
    //std::cout << "Got data: " << data << std::endl;
    while (1) {};
    ClientDisposeInstance((TcpSocket*)handler);

    //TcpSocket client(address, port);
    //client.connectToHost();
    ////ClientSendData((TcpSocket*)handler, "Hello Server");
    ////char* data = ClientRecvData((TcpSocket*)handler);
    ////std::cout << "Got data: " << data << std::endl;
    //client.disconnectFromHost();
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
