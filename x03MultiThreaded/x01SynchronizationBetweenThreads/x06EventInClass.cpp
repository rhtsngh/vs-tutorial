// x05Events.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Explanation:
//  - mythreadA runs first to wait for myEvent occuring
//  - mythreadB runs after to trigger myEvent
//  - that leads to: even mythreadA is active firstly, the job A is operated after job B.

#include "Header.h"
#if ENABLE_X06
#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <process.h>

class Something {
public:
    Something();
    ~Something();
    void runThread();

public:
    HANDLE m_event;
    HANDLE m_thread;
};

Something::Something()
{
    m_event = CreateEvent(0, 0, 0, 0);
    m_thread = (HANDLE)_beginthreadex(0, 0, &(Something::runThread), (void*)0, 0, 0);
}

Something::~Something()
{

}

void Something::runThread()
{

}

int main()
{
    std::cout << "Hello! This is x05Events\n";

    

    std::cout << "Byebye!\n";

    return 0;
}
#endif
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
