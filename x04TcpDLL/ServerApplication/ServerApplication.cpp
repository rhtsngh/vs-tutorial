// ServerApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "TcpServerBridge.h"

int main()
{
    std::cout << "Hello World!\n";

    const char* address = "127.0.0.1";
    WORD port = 27016;

    HANDLE handler;
    handler = Server::CreateInstance();
    Server::CreateSocket((TcpServer*)handler);
    Server::BindSocket((TcpServer*)handler, address, port);
    Server::ListenSocket((TcpServer*)handler);
    Server::AcceptConnection((TcpServer*)handler);
    char* data = Server::RecvData((TcpServer*)handler);
    std::cout << "Got data: " << data << std::endl;
    Server::SendData((TcpServer*)handler, "Hello Client");
    Server::DisposeInstance((TcpServer*)handler);
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
