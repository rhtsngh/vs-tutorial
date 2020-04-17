// SampleServerv2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "TcpServer.h"

bool good = true;

void messageReceived(messageStruct* s)
{
    std::cout << "Server received: " << s->message << std::endl;
}

void errorOccurred(errorStruct* e)
{
    std::cout << e->code << " : " << e->message << std::endl;
    good = false;
}

int main()
{
    std::cout << "Hello World!\n";

    TcpServer server("127.0.0.1", 27016);
    server.waitForConnected();
    server.setMessageCallback(&messageReceived);

    //server.sendData("Hello Client");
    //char * clientResponse = server.recvData();
    //std::cout << clientResponse << std::endl;

    std::string str;
    while (good) {
        std::cout << ">";
        std::getline(std::cin, str);
        server.sendData(str.c_str());
    };

    server.close();
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
